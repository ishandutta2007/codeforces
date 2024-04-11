#include<iostream>
#include<stdio.h>
using namespace std;


int main()
    {
    int n;
    int i;
    int x;
    int sm=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&x);
        sm+=x;
        }
    printf("%lf\n",double(sm)/n);
    return 0;
    }