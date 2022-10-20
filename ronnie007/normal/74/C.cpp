#include<iostream>
#include<stdio.h>
using namespace std;


int gcd(int x,int y)
    {
    if(y==0)return x;
    return gcd(y,x%y);
    }

int main()
    {
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d\n",gcd(n-1,m-1)+1);
    return 0;
    }