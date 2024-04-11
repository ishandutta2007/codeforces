#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adj[1000000];
int degree[1000000];
int in[1000000];
int p[1000000];
vector<int> g2[1000000];
int cnt[1000000];
void dfs(int v)
{
    for (auto u:adj[v])
    {
        dfs(u);
    }
    if (p[v]==0)return;
    int d = degree[v];
    d-=cnt[v];
    if (d%2)
        g2[p[v]].push_back(v),in[v]++;
    else
        g2[v].push_back(p[v]),cnt[p[v]]++,in[p[v]]++;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int root;
    for (int i=1;i<=n;i++)
    {
        cin>>p[i];
        if (p[i]==0)
            root=i;
        else
            adj[p[i]].push_back(i),degree[i]++,degree[p[i]]++;
    }
    dfs(root);
    priority_queue<pair<int,int> > q;
    for (int i=1;i<=n;i++)
        if (in[i]==0)
            q.push({-(degree[i]%2),i});
    vector<int> ret;
    for (int pp=1;pp<=n;pp++)
    {
        auto P = q.top();
        q.pop();
        int v = P.second;
        if (P.first!=0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        ret.push_back(v);
        for (auto u:g2[v])
        {
            in[u]--;
            degree[u]--;
            if (in[u]==0)
                q.push({-(degree[u]%2),u});
        }
    }
    cout<<"YES"<<endl;
    for (auto x:ret)cout<<x<<endl;

}