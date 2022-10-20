#include<iostream>
#include<stdio.h>
using namespace std;
int main()
    {
    int a[221],k,i,n;
    scanf("%d%d",&n,&k);
    for(i=0;i<n*2+1;i++)
        {
        scanf("%d",&a[i]);
        }
    for(i=0;i<n*2+1;i++)
        {
        if(i==0)printf("%d",a[i]);
        else if(i%2==0)printf(" %d",a[i]);
        else
            {
            if(k>0 && a[i]-1>a[i-1] && a[i]-1>a[i+1])
                {
                a[i]--;
                k--;
                }
            printf(" %d",a[i]);
            }
        }
    printf("\n");
    }