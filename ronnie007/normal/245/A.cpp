#include<iostream>
#include<stdio.h>
using namespace std;


int main()
    {
    int n;
    int i;
    int a,b,c;
    scanf("%d",&n);
    int x[1050];
    int y[1050];
    for(i=1;i<=n;i++)
        {
        x[i]=0;
        y[i]=0;
        }
    for(i=0;i<n;i++)
        {
        scanf("%d%d%d",&a,&b,&c);
        x[a]+=b;
        y[a]+=c;
        }
    for(i=1;i<=2;i++)
        {
        if(x[i]>=y[i])printf("LIVE\n");
        else printf("DEAD\n");
        }
    return 0;
    }