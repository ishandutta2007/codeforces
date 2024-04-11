#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;


struct dr
    {
    int a;
    int b;
    };

bool f(struct dr x,struct dr y);

int main()
    {
    int n,s,i,j;
    struct dr k[1050];
    scanf("%d%d",&s,&n);
    for(i=0;i<n;i++)
        {
        scanf("%d%d",&k[i].a,&k[i].b);
        }
    sort(k,k+n,f);
    for(i=0;i<n;i++)
        {
        if(k[i].a>=s)
            {
            printf("NO\n");
            return 0;
            }
        else
            {
            s+=k[i].b;
            }
        }
    printf("YES\n");
    return 0;
    }



bool f(struct dr x,struct dr y)
    {
    if(x.a<=y.a)return true;
    return false;
    }