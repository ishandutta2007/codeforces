#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;


int n,m;

long long a[100007];
long long b=0;

void input();


int main()
    {
    input();

    return 0;
    }




void input()
    {
    scanf("%d%d",&n,&m);
    int i;
    long long y;
    long long x;
    int ind;
    int t;
    for(i=1;i<=n;i++)
        {
        scanf("%I64d",&a[i]);
        }
    for(i=0;i<m;i++)
        {
        scanf("%d",&t);
        if(t==1)
            {
            scanf("%d%I64d",&ind,&x);
            a[ind]=x-b;
            }
        if(t==2)
            {
            scanf("%I64d\n",&y);
            b+=y;
            }
        if(t==3)
            {
            scanf("%d",&ind);
            printf("%I64d\n",a[ind]+b);
            }
        }
    }