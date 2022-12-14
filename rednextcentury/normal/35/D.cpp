#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int a[1000000];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,X;
    cin>>n>>X;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[i]=x*(n-i);
    }
    for (int i=0;i<n;i++)
    {
        for (int j=X;j>=0;j--)
        {
            if (a[i]<=j)
                dp[j]=max(dp[j],dp[j-a[i]]+1);
        }
    }
    cout<<dp[X]<<endl;
}