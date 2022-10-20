#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    int p=n/2;
    if(x==p || x==p+1)
        {
        if(y==p || y==p+1)
            {
            printf("NO\n");
            return 0;
            }
        }
    printf("YES\n");
    return 0;
    }