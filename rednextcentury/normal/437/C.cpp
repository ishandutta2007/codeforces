# include <iostream>
# include <string>
# include <map>
# include <stdio.h>
# include <cmath>
# include <cstdio>
# include <queue>
# include <algorithm>
# include <stack>
# include <cstring>
# include <iomanip>
# include<ios>
using namespace std;
vector<int> a[10000];
int b[10000];
bool visited[10000];
stack<int> st;
void toposort(int v)
{
    visited[v]=1;
    for (int i=0;i<a[v].size();i++)
    {
        int u=a[v][i];
        if (!visited[u])
            toposort(u);
    }
    
    st.push(v);
}
int ans[10000];
int adj[1000][1000];
long long solve(int n)
{
    long long cost=0;
    for (int i=0;i<n;i++)
    {
        for (int x=0;x<n;x++)
        {
            if (adj[ans[i]][x])
            {
                cost+=b[x];
                adj[ans[i]][x]=0;
                adj[x][ans[i]]=0;
            }
        }
    }
    return cost;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u][v]=1;
        adj[v][u]=1;
        if (b[u]>b[v])
        {
            a[u].push_back(v);
        }
        else if (b[v]>b[u])
            a[v].push_back(u);
    }
    for (int i=0;i<n;i++)
    {
        if (!visited[i])
    toposort(i);
    }
    for (int i=0;i<n;i++)
    {
        ans[i]=st.top();st.pop();
    }
    cout<<solve(n)<<endl;
}