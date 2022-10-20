#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n;
    int i;
    scanf("%d",&n);
    if(n%2==1)
        {
        printf("-1\n");
        return 0;
        }
    else
        {
        for(i=2;i<=n;i+=2)
            {
            printf("%d %d ",i,i-1);
            }
        printf("\n");
        }
    return 0;
    }