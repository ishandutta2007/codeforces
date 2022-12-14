#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int p[1000000];
vector<int> adj[1000000];
int lev[1000000];
int num[1000000];
void dfs(int v)
{
    num[lev[v]]++;
    num[lev[v]]%=2;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        lev[u]=lev[v]+1;
        dfs(u);
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i=2;i<=n;i++)
    {
        cin>>p[i];
        adj[p[i]].push_back(i);
    }
    dfs(1);
    int ret=0;
    for (int i=0;i<=n;i++)
        ret+=num[i];
    cout<<ret<<endl;
}