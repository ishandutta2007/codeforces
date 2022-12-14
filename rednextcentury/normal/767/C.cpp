# include <iostream>
# include <vector>
# include <stdio.h>
#include <limits.h>
#include <stack>
#include <algorithm>
using namespace std;
int can[1000003];
int id[1000002];
vector<int> adj[1000001];
int tot[1000001];
int a[1000001];
int cur[10];
int root;
int need,i1,i2;
bool sol;
void dfs(int v)
{
    tot[v]=a[v];
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        dfs(u);
        tot[v]+=tot[u];
    }
    if (tot[v]==need)
        can[v]=1,id[v]=v;
    int num=0;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (can[u]){can[v]=1,id[v]=id[u];
            if (num<2)
                cur[num++]=id[u];
        }
        if (v!=root && tot[v]==2*need && can[u])
        {
            i1=id[u],i2=v;
            sol=1;
        }
    }
    if (num==2)
    {
        sol=1;
        i1=cur[0],i2=cur[1];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x>>a[i];
        if (x!=0)
            adj[x].push_back(i);
        else root=i;
        sum+=a[i];
    }
    if (sum%3!=0)
    {
        cout<<-1<<endl;
    }
    else
    {
        need=sum/3;
        dfs(root);
        if (sol)cout<<i1<<' '<<i2<<endl;
        else cout<<-1<<endl;
    }
}