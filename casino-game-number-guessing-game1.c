#include<stdio.h>
#include <string.h> // Needed to use strings
#include <stdlib.h> // Needed to use random numbers
#include <time.h>


void drawLine(int n, char symbol);
void rules();

int main()
{
    char playerName[10];
    int amount=0; // hold player's balance amount
    int bettingAmount;
    int guess;
    int dice; // hold computer generated number
    char choice;

    srand(time(0)); // "Seed" the random generator

    drawLine(60,'_');
    printf("\n\n\n\t\t CASINO GAME \n\n\n\n");
    drawLine(60,'_');

    printf("\n\nEnter Your Name : ");
    scanf("%s",playerName);

    printf("\n\nEnter Deposit amount to play game : $");
    scanf("%d",&amount);

    do
    {
        //system("cls");
        rules();
        printf("\n\nYour current balance is $%d ",amount);
        printf("\n");

		// Get player's betting amount
        do
        {
            printf("enter money to bet : $");
            scanf("%d",&bettingAmount);
            if(bettingAmount > amount)
            {
                printf("Your betting amount is more than your current balance\n");
                printf("\nRe-enter data\n");
            }

        }while(bettingAmount > amount);

		// Get player's numbers
        do
        {
            printf("Guess your number to bet between 1 to 10 :");
            scanf("%d",&guess);
            if(guess <= 0 || guess > 10)
            {
                printf("Please check the number!! should be between 1 to 10\n");
                printf("\nRe-enter data\n ");
            }

        }while(guess <= 0 || guess > 10);

        dice = rand()%10 + 1; // Will hold the randomly generated integer between 1 and 10

        if(dice == guess)
        {
            printf("\n\nGood Luck!! You won Rs.%d",bettingAmount * 10);
            amount = amount + bettingAmount * 10;
        }
        else
        {
            printf("Bad Luck this time !! You lost $ %d",bettingAmount);
            amount = amount - bettingAmount;
        }

        printf("\nThe winning number was : %d",dice);
        printf("\n");
        printf("\n %s You have $ %d",playerName,amount);
        if(amount == 0)
        {
            printf("You have no money to play ");
            break;
        }
        printf("\n\n-->Do you want to play again (y/n)? ");
        scanf("%c",choice);
    }while(choice!='n' || choice!='N');

    printf("\n\n\n");
    drawLine(70,'=');
    printf("\n\nThanks for playing game. Your balance amount is $ %d",amount);
    printf("\n \n");
    drawLine(70,'=');

    return 0;
}

void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        printf("%c",symbol);
    printf("\n");
}

void rules()
{

    printf("\n\n");
    drawLine(80,'-');
    printf("\t\tRULES OF THE GAME\n");
    drawLine(80,'-');
    printf("\t1. Choose any number between 1 to 10\n");
    printf("\t2. If you win you will get 10 times of money you bet\n");
    printf("\t3. If you bet on wrong number you will lose your betting amount\n\n");
    drawLine(80,'-');
}
