#include <stdio.h>
#include <string.h>

int l;
char c[100000];

int main()
{
    scanf("%s", c);
    l=strlen(c);
    for(int i=0; i<l; i++)
    {
        printf("%c", c[i]);
    }
    for(int i=l-1; i>=0; i--)
    {
        printf("%c", c[i]);
    }
    return 0;
}