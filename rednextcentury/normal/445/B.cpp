#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <ios>
using namespace std;
stack<int> st;
vector<int> adj[10000];
bool visited[10000];
int sg[1000][1000];
void toposort(int v)
{
    visited[v]=1;
    int n=adj[v].size();
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i];
        if (!visited[u])
            toposort(u);
    }
}
int a[1000000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int s,e;
        cin>>s>>e;
        adj[s-1].push_back(e-1);
        adj[e-1].push_back(s-1);
    }
    int ans=0;
    for (int i=0;i<n;i++)
    {
        if (!visited[i])
        toposort(i),ans++;
    }
    long long ret=pow(2.0,n-ans);
    cout<<ret<<endl;
}