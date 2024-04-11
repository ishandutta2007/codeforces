#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    int p;
    p=(n*y)/100;
    if((n*y)%100!=0)p++;
    if(p>=x)printf("%d\n",p-x);
    else printf("0\n");
    return 0;
    }