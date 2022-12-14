# include<iostream>
#include<bits/stdc++.h>
#define EPS 1e-6
#include <stdio.h>
using namespace std;
int a[1000];
long long dp[10000];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    dp[0]=1;
    for (int i=1;i<=n;i++)
    {
        int num=a[i];
        for (int j=i-1;j>=0;j--)
        {
            if (num==1)
                dp[i]+=dp[j];
            num+=a[j];
        }
    }
    cout<<dp[n]<<endl;
}