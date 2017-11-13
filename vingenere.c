#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
     string key = get_string("key: ");

     string plaintext = get_string("plaintext: ");

    char cipher[strlen(plaintext)+1];
    int counter = 0;
    int k = counter % strlen(key);

    for (int i = 0; i < strlen(plaintext);  i++)
        {
            k = counter % strlen(key);
            if (islower(plaintext[i]))
            {

                cipher[counter]= 'a' + (((plaintext[i]-'a') + (key[k]-'a')) % 26);
                counter++;
            }
            else if (isupper(plaintext[i]))
            {

                cipher[counter]= 'A' + (((plaintext[i]-'A') + (toupper (key[k])-'A')) % 26);
                counter++;
            }
            else
            {
                cipher[counter] = plaintext[i];
                counter++;
            }
        }
        cipher[counter]= '\0';

    printf("\nCipher: %s\n", cipher);
}