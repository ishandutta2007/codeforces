#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
    {
    int n;
    int x;
    int i,j;
    int fl=0;
    scanf("%d",&n);
    long long h;
    int p;
    long long g;
    for(i=0;i<n;i++)
        {
        cin>>h;
        g=int(sqrt(h));
        if((g*g!=h) || h==1)
            {
            printf("NO\n");
            }
        else
            {
            p=sqrt(h);
            fl=0;
            for(j=2;j*j<=p;j++)
                {
                if(p%j==0){fl=1;printf("NO\n");break;}
                }
            if(fl==0)printf("YES\n");
            }
        }
    return 0;
    }

//999966000289