#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>
#include <queue>
using namespace std;
vector<int> adj[100000];
int pa[1000000];
bool visited[100000];
void dfs(int v)
{
    visited[v]=1;
    int n=adj[v].size();
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i];
        if (visited[u])
            continue;
        pa[u]=v;
        dfs(u);
    }
}
int main()
{
    int n,r1,r2;
    cin>>n>>r1>>r2;
    int now=1;
    for (int i=1;i<n;i++)
    {
        if (now==r1)
            now++;
        int x;
        cin>>x;
        adj[now].push_back(x);
        adj[x].push_back(now);
        now++;
    }
    dfs(r2);
    for (int i=1;i<=n;i++)
    {
        if (i==r2)
            continue;
        cout<<pa[i]<<" ";
    }
    cout<<endl;
}