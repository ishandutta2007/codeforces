#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    i=1;
    while(m>0)
        {
        if(m>=i)m=m-i;
        else {printf("%d\n",m);return 0;}
        i=i%n+1;
        }
    printf("0\n");
    return 0;
    }