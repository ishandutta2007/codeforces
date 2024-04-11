#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    long long n;
    cin>>n;
    int i,j;
    for(i=0;i<=n;i++)
        {
        for(j=0;j<n-i;j++)
            {
            printf("  ");
            }
        printf("0");
        for(j=1;j<=i;j++)
            {
            printf(" %d",j);
            }
        for(j=i-1;j>=0;j--)
            {
            printf(" %d",j);
            }
        printf("\n");
        }
    for(i=n;i>=1;i--)
        {
        for(j=0;j<n-i+1;j++)
            {
            printf("  ");
            }
        printf("0");
        for(j=1;j<i;j++)
            {
            printf(" %d",j);
            }
        for(j=i-2;j>=0;j--)
            {
            printf(" %d",j);
            }
        printf("\n");
        }

    return 0;
    }