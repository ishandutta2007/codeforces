#include<iostream>
#include <stdio.h>
#include<string>
using namespace std;
int a[6], b[7];

int main()
    {

    string s;
    int i;

    cin>>s;

    for (i = 0; i < 6; i++)
        {
        if(s[i]=='R')a[0]++;
        if(s[i]=='O')a[1]++;
        if(s[i]=='Y')a[2]++;
        if(s[i]=='G')a[3]++;
        if(s[i]=='B')a[4]++;
        if(s[i]=='V')a[5]++;
        }

    for (i = 0; i < 6; i++) b[a[i]]++;

    if (b[6] == 1 || b[5] == 1)
        {
        printf("1\n");
        }
    else if (b[4] == 1 || b[3] == 2)
        {
        printf("2\n");
        }
    else if (b[3] == 1)
        {
        if (b[2] == 1)
            {
            printf("3\n");
            }
        else
            {
            printf("5\n");
            }
        }
    else if (b[2] == 3)
        {
        printf("6\n");
        }
    else if (b[2] == 2)
        {
        printf("8\n");
        }
    else if (b[2] == 1)
        {
        printf("15\n");
        }
    else
        {
        printf("30\n");
        }

    return 0;
    }