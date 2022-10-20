#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n;
    int a[150];
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {
        scanf("%d",&a[i]);
        }
    for(i=1;i<=n;i++)
        {
        for(j=1;j<=n;j++)
            {
            if(a[j]==i)
                {
                printf("%d ",j);
                break;
                }
            }
        }
    printf("\n");
    return 0;
    }