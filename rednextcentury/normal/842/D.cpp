#include<bits/stdc++.h>
using namespace std;
int num[7000000];
int adj[7000000][2];
int V=0;
int cur[22];
int q[22];
int N=19;
int vis[1000000];
void Insert(int v,int id)
{
    if (id==N+1)
    {
        num[v]++;
        return;
    }
    if (adj[v][cur[id]]==0)
        adj[v][cur[id]]=++V;
    int u=adj[v][cur[id]];
    Insert(u,id+1);
    num[v]++;
}
void Add(int X)
{
    for (int i=N;i>=0;i--)
    {
        cur[i]=X%2;
        X/=2;
    }
    Insert(0,0);
}
int Count(int v,int id)
{
    if (v==0 && id!=0)
        return 0;
    if (id==N+1)
        return num[v];
    int x=adj[v][0];
    int y=adj[v][1];
    if (q[id]==0)
    {
        if (cur[id]==0)
        {
            return Count(x,id+1);
        }
        else
        {
            return num[x]+Count(y,id+1);
        }
    }
    else
    {
        if (cur[id]==0)
        {
            return Count(y,id+1);
        }
        else
        {
            return num[y]+Count(x,id+1);
        }
    }
}
int cntLess(int X)
{
    for (int i=N;i>=0;i--)
    {
        cur[i]=X%2;
        X/=2;
    }
    return Count(0,0);
}
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (++vis[a[i]]==1)
            Add(a[i]);
    }
    num[0]=0;
    int X=0;
    int Y=0;
    for (int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        X^=x;
        Y=X;
        for (int i=N;i>=0;i--)
        {
            q[i]=X%2;
            X/=2;
        }
        X=Y;
        int l=0,r=300004;
        int ret=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if (cntLess(mid)<=mid)
                ret=mid,r=mid-1;
            else
                l=mid+1;
        }
        cout<<ret<<endl;
    }
}