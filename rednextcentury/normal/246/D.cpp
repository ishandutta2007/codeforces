#include<iostream>
# include <cmath>
#include <algorithm>
#include <set>
#include<ios>
using namespace std;
set<int> adj[1000000];
int color[1000000];
bool vis[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++) cin>>color[i],vis[color[i]]=1;
    for (int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if (color[a-1]==color[b-1])
            continue;
        adj[color[a-1]].insert(color[b-1]);
        adj[color[b-1]].insert(color[a-1]);
    }
    int ans=-1;
    int idx;
    for (int i=0;i<=100000;i++)
    {
            if (vis[i] && (int)adj[i].size()>ans)
                ans=(int)adj[i].size(),idx=i;
    }
    cout<<idx<<endl;
}