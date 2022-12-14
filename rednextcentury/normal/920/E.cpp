#include<bits/stdc++.h>
using namespace std;
set<int> s;
vector<int> adj[1000000];
bool vis[1000000];
int sz;
vector<int> ret;
void dfs(int v)
{
    sz++;
    vis[v]=1;
    s.erase(s.find(v));
    int last=0;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        while(1)
        {
            set<int>::iterator it = s.upper_bound(last);
            if (it==s.end())
                break;
            int x=*it;
            if (x<u)
                dfs(x);
            else
                break;
        }
        last=u;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }
    for (int i=1;i<=n;i++)
    {
        s.insert(i);
        adj[i].push_back(n+1);
        sort(adj[i].begin(),adj[i].end());
    }
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            dfs(i);
            ret.push_back(sz);
            sz=0;
        }
    }
    cout<<ret.size()<<endl;
    sort(ret.begin(),ret.end());
    for (int i=0;i<ret.size();i++)
        cout<<ret[i]<<' ';
    cout<<endl;
}