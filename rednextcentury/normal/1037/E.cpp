#include <bits/stdc++.h>
using namespace std;
int num;
int n;
vector<int> adj[1000000];
queue<int> q;
int k;
int deg[1000000];
bool added[1000000];
map<pair<int,int> ,int> mp;
void Del()
{
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        num--;
        added[v]=0;
        for (int i=0;i<adj[v].size();i++)
        {
            if (added[adj[v][i]] && ++mp[{adj[v][i],v}]==1)
            {
                if (--deg[adj[v][i]]==k-1)
                {
                    q.push(adj[v][i]);
                }
            }
        }
    }
}
int a[1000000];
int b[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    int m;
    cin>>n>>m>>k;
    for (int i=0;i<m;i++)
    {
        cin>>a[i]>>b[i];
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
        deg[a[i]]++,deg[b[i]]++;
    }
    for (int i=1;i<=n;i++)
    {
        added[i]=1;
        if (deg[i]<k)q.push(i);
    }
    num=n;
    Del();
    vector<int> ret;
    for (int i=m-1;i>=0;i--)
    {
        ret.push_back(num);
        if (added[a[i]] && added[b[i]])
        {
            mp[{a[i],b[i]}]=1;
            mp[{b[i],a[i]}]=1;
            if (--deg[a[i]]==k-1)q.push(a[i]);
            if (--deg[b[i]]==k-1)q.push(b[i]);
        }
        Del();
    }
    for (int i=ret.size()-1;i>=0;i--)
        cout<<ret[i]<<endl;
}