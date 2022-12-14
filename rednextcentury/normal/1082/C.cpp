#include <bits/stdc++.h>
using namespace std;
long long len[1000000];
vector<int> adj[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        int s,r;
        cin>>s>>r;
        adj[s].push_back(r);
    }
    for (int i=1;i<=m;i++)
    {
        sort(adj[i].begin(),adj[i].end());
        reverse(adj[i].begin(),adj[i].end());
        long long sum=0;
        for (int j=0;j<adj[i].size();j++)
        {
            sum+=adj[i][j];
            if (sum>0)len[j+1]+=sum;
        }
    }
    long long mx=0;
    for (int i=1;i<=n;i++)
        mx=max(mx,len[i]);
    cout<<mx<<endl;
}