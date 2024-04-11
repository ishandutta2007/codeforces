#include<iostream>
#include<stdio.h>
using namespace std;



int main()
    {
    int n,k;
    int i;
    scanf("%d%d",&n,&k);
    if(n/k<3 || k==1)
        {
        printf("-1\n");
        return 0;
        }
    for(i=0;i<k;i++)
        {
        n--;
        printf("%d ",i+1);
        }
    for(i=0;i<k;i++)
        {
        n-=2;
        printf("%d %d ",i+1,i+1);
        }
    while(n>0)
        {
        n--;
        printf("1 ");
        }
    printf("\n");
    return 0;
    }