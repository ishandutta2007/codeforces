#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int n;
int a[1050];
int dp[1050];


void input();
void solve();



int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
    }



void solve()
    {
    int i;
    dp[0]=a[0];
    for(i=1;i<n;i++)
        {
        dp[i]=-1;
        }
    for(i=0;i<n;i++)
        {
        dp[i+1]=max(dp[i+1],min(dp[i],a[i+1]));
        dp[i+2]=max(dp[i+2],min(dp[i],a[i+2]));
        }
    printf("%d\n",dp[n-1]);
    }