#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n;
    int a[100007];
    int i;
    scanf("%d",&n);
    int br=0;
    for(i=1;i<=n;i++)
        {
        scanf("%d",&a[i]);
        }
    for(i=n-1;i>=1;i--)
        {
        if(a[i]>a[i+1])
            {
            printf("%d\n",i);
            return 0;
            }
        }
    printf("0\n");
    return 0;
    }