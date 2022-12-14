#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int num[1000000];
int dp[1000000];
vector<int> vec[1000000];
vector<int> vec2[1000000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,c;
    cin>>n>>c;
    for (int i=1;i<=n;i++)
        cin>>a[i],vec2[a[i]].push_back(0),vec[a[i]].push_back(i-1),vec2[a[i]].push_back(1),vec[a[i]].push_back(i);
    for (int i=1;i<=n;i++)
    {
        if (a[i]==c)num[i]=num[i-1]+1;
        else num[i]=num[i-1];
    }
    int ret=num[n];
    for (int i=1;i<=500000;i++)
    {
        dp[0]=0;
        int mn=0;
        int sum=0;
        for (int j=0;j<vec[i].size();j++)
        {
            sum+=vec2[i][j];
            dp[j+1]=sum-num[vec[i][j]];
            ret=max(ret,num[n]+dp[j+1]-mn);
            mn=min(mn,dp[j+1]);
        }
    }
    cout<<ret<<endl;
}