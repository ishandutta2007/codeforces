# include <iostream>
# include <vector>
# include <stdio.h>
#include <limits.h>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> adj[1000000];
bool vis[1000000];
int col[1000000];
int pa[1000000];
int num=0;
void dfs(int v)
{
    vis[v]=1;
    int c=1;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (vis[u])continue;
        pa[u]=v;
        while(1)
        {
            if (col[v]==c || col[pa[v]]==c)
                c++;
            else
            {
                col[u]=c;
                c++;
                break;
            }
        }
    }
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (vis[u])continue;
        dfs(u);
    }
    num=max(num,c-1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    col[1]=1;
    dfs(1);
    cout<<num<<endl;
    for (int i=1;i<=n;i++)
        cout<<col[i]<<' ';
    cout<<endl;
}