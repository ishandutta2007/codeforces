#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n,i;
    int mx=-10;
    int mn=1000000;
    int c;
    int br=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&c);
        if(c>mx){br++;mx=c;}
        if(c<mn){br++;mn=c;}
        }
    printf("%d\n",br-2);
    return 0;
    }