#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;


int dp[1000007];


int ispr(int x)
    {
    int i;
    if(x==1)return 0;
    for(i=2;i*i<=x;i++)
        {
        if(x%i==0)return 0;
        }
    return 1;
    }


int main()
    {
    int a,b,k;
    int i,j;
    scanf("%d%d%d",&a,&b,&k);
    for(i=0;i<=b;i++)
        {
        dp[i]=0;
        }
    for(i=a;i<=b;i++)
        {
        if(ispr(i)==0)
            {
            dp[i]=dp[i-1];
            }
        else
            {
            dp[i]=dp[i-1]+1;
            }
        //printf("%d\n",dp[i]);
        }
    if(dp[b]<k)
        {
        printf("-1\n");
        return 0;
        }
    int r,l;
    l=10000000;
    r=b-a+1;
    l=k-1;
    int sr=0;
    int fl=0;
    while(r!=l)
        {
        //printf("%d %d\n",l,r);
       // system("pause");
        sr=(r+l)/2;
        //printf("%d\n",sr);
        fl=0;
        for(i=a+sr-1;i<=b;i++)
            {
            if(dp[i]-dp[i-sr]<k)
                {
                fl=1;
                break;
                }
            }
        if(fl==1)
            {
            l=sr+1;
            }
        else r=sr;

        }

    if(l==k-1)printf("-1\n");
    else printf("%d\n",l);
    return 0;
    }