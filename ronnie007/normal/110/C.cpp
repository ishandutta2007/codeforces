#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n;
    scanf("%d",&n);
    int i;
    int j;
    int x;
    int rem4=-1,rem7=-1;
    for(i=0;4*i<=n;i++)
        {
        if((n-4*i)%7!=0)continue;
        rem7=(n-4*i)/7;
        rem4=i;
        break;
        }
    if(rem7==-1){printf("-1\n");return 0;}
    for(i=0;i<rem4;i++)
        {
        printf("4");
        }
    for(i=0;i<rem7;i++)
        {
        printf("7");
        }
    printf("\n");
    return 0;
    }