#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;


long long n;

long long nod(long long x,long long y)
    {
    if(y==0)return x;
    else return nod(y,x%y);
    }


long long nok(long long x,long long y)
    {
    return x*y/nod(x,y);
    }
int main()
    {
    scanf("%d",&n);
    if(n==1)printf("1\n");
    if(n==2)printf("2\n");
    if(n==3)printf("6\n");
    if(n<4)return 0;
    if(n%2==1)
        {
        cout<<n*(n-1)*(n-2)<<"\n";
        return 0;
        }
    long long i,j,t;
    long long best=0;
    long long h;
    for(i=n-50;i<=n;i++)
        {
        for(j=n-50;j<=n;j++)
            {
            for(t=n-50;t<=n;t++)
                {
                if(i>0 && j>0 && t>0)
                    {
                    h=nok(nok(i,j),t);
                    if(best<h)best=h;
                    }
                }
            }
        }
    cout<<best<<"\n";
    return 0;
    }