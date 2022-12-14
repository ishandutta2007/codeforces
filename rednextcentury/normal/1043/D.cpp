#include<bits/stdc++.h>
using namespace std;
int after[1000000];
int agree[1000000];
int a[11][200001];
int group[1000005];
vector<int> G[1000005];
void Merge(int u,int v)
{
    for (int i=0;i<G[u].size();i++)
    {
        G[v].push_back(G[u][i]);
        group[G[u][i]]=v;
    }
    G[u].clear();
}
void dsu(int x,int y)
{
    int u=group[x],v=group[y];
    if (u==v)return;
    if (G[u].size()<G[v].size())
        Merge(u,v);
    else Merge(v,u);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
            cin>>a[i][j];
    }
    for (int i=0;i+1<n;i++)
    {
        after[a[0][i]]=a[0][i+1];
        agree[a[0][i]]=1;
    }
    after[a[0][n-1]]=-1;
    agree[a[0][n-1]]=-1;
    for (int i=1;i<m;i++)
    {
        for (int j=0;j+1<n;j++)
        {
            if (after[a[i][j]]==a[i][j+1])
                agree[a[i][j]]++;
        }
    }
    for (int i=1;i<=n;i++)
    {
        G[i].push_back(i);
        group[i]=i;
    }
    for (int i=1;i<=n;i++)
    {
        if (agree[i]==m)dsu(i,after[i]);
    }
    long long ret=0;
    for (int i=1;i<=n;i++)
    {
        long long cur = G[i].size();
        ret+=(cur)*(cur+1)/2;
    }
    cout<<ret<<endl;
}