#include<stdio.h>
# include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000000];
int a[1000000];
int main()
{
    int n,m;
    cin>>n>>m;
    long long ret=0;
    for (int i=0;i<m;i++)
    {
        cin>>a[i];
        if (i>0)
            ret+=abs(a[i]-a[i-1]);
    }
    for (int i=1;i<m;i++)
    {
            if (a[i-1]==a[i])continue;
            adj[a[i]].push_back(a[i-1]);
            adj[a[i-1]].push_back(a[i]);
    }
    long long ans=ret;
    for (int i=1;i<=n;i++)
    {
        if (adj[i].size()==0)continue;
        sort(adj[i].begin(),adj[i].end());
        long long sum;
        sum=adj[i][adj[i].size()/2];
        long long x=ret;
        for (int j=0;j<adj[i].size();j++)
        {
            if (i==adj[i][j])continue;
            x-=abs(i-adj[i][j]);
            x+=abs(sum-adj[i][j]);
        }
        ans=min(ans,x);
    }
    cout<<ans<<endl;
}