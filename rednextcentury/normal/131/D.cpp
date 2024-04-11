# include <iostream>
# include <stdio.h>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <iomanip>
# include <queue>
# include <ios>
# include <vector>
# include <algorithm>
using namespace std;
int v1,v2;
int p[3001];
vector<int> adj[3001];;
int path1[3001];
int path2[3001];
int cycle[3001];
bool visited[3001];
map<int,int> m;
map<int,int> k;
int ans[3001];
bool dfs(int s)
{
    visited[s]=1;
    int n=adj[s].size();
    for (int i=0;i<n;i++)
    {
        if (visited[adj[s][i]]==1 && p[s]!=adj[s][i])
        {
            v1=s;
            v2=adj[s][i];
            return 1;
        }
        else if(visited[adj[s][i]]==0) 
        {
            p[adj[s][i]]=s;
            if (dfs(adj[s][i]))
                return 1;
        }
    }
    return 0;
}
void bfs(int s)
{
    
    bool v[3001]={0};
    queue<int> q;
    queue<int> t;
    t.push(0);
    q.push(s);
    v[s]=1;
    while (!q.empty())
    {
        int now=q.front();
        int h=t.front();
        t.pop();
        q.pop();
        if (k[now]==1)
        {
            ans[s]=h;
            break;
        }
        int n=adj[now].size();
        for (int i=0;i<n;i++)
        {
            if (v[adj[now][i]]==0)
            {
                v[adj[now][i]]=1;
                q.push(adj[now][i]);
                t.push(h+1);
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    dfs(0);
    int loc1=0;
    while (v1!=0)
    {
        path1[loc1++]=v1;
        m[v1]++;
        v1=p[v1];
    }
    int loc2=0;
    bool g=0;
    while (v2!=0)
    {
        path2[loc2++]=v2;
        if (m[v2]>0 && g==0)
        {
            g=1;
            cycle[0]=v2;
        }
        v2=p[v2];
    }
    k[cycle[0]]=1;
    int loc=1;
    for (int i=0;i<loc1;i++)
    {
        if (path1[i]==cycle[0])
            break;
        cycle[loc++]=path1[i];
        k[path1[i]]=1;
    }
    for (int i=0;i<loc2;i++)
    {
        if (path2[i]==cycle[0])
            break;
        cycle[loc++]=path2[i];
        k[path2[i]]=1;
    }
    for (int i=0;i<n;i++)
    {
        if (k[i]==0)
            bfs(i);
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}