#include <bits/stdc++.h>
using namespace std;
int a[10000];
int adj[1001][1001];
int dist[10001];
int n,d;
bool vis[1000000];
bool check(int m)
{
    priority_queue<pair<int,int> > q;
    q.push(make_pair(m,1));
    for (int i=1;i<=n;i++)vis[i]=0;
    while(!q.empty())
    {
        int v=q.top().second;
        int len=q.top().first;
        q.pop();
        if (v==n)return 1;
        if (vis[v])continue;
        vis[v]=1;
        for (int i=1;i<=n;i++)
        {
            if (i==v)continue;
            if (len>=adj[i][v])
                q.push(make_pair(len-adj[i][v]+a[i],i));
        }
    }
    return 0;
}
int bs(int l,int r)
{
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid))
            ans=mid,r=mid-1;
        else
            l=mid+1;
    }
    return ans;
}
int x[1000],y[1000];
int main()
{
    cin>>n>>d;
    for (int i=2;i<=n-1;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            adj[i][j]=(abs(x[i]-x[j])+abs(y[i]-y[j]))*d;
    check(2000);
    cout<<bs(1,2000000000)<<endl;
}