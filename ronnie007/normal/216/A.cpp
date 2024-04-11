#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
    {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",b*c+(a-1)*c+(a-1)*b-(a-1));
    return 0;
    }