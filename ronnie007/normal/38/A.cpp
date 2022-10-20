#include<iostream>
#include<stdio.h>
using namespace std;

int main()
    {
    int n;
    int d[150];
    int a,b;
    scanf("%d",&n);
    int i;
    for(i=1;i<n;i++)
        {
        scanf("%d",&d[i]);
        }
    scanf("%d%d",&a,&b);
    int s=0;
    for(i=a;i<b;i++)
        {
        s+=d[i];
        }
    printf("%d\n",s);
    return 0;
    }