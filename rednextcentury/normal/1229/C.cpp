#include <bits/stdc++.h>
using namespace std;
long long ret=0;
long long contrib[1000000];
long long in[1000000];
long long out[1000000];
void update(int v)
{
    long long newContrib = in[v]*out[v];
    ret-=contrib[v];
    contrib[v]=newContrib;
    ret+=contrib[v];
}
vector<int> I[1000000];
void query(int v)
{
    for (auto x:I[v])
    {
        I[x].push_back(v);
        in[x]++;
        out[x]--;
        update(x);
    }
    I[v].clear();
    out[v]+=in[v];
    in[v]=0;
    update(v);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        if (u<v)swap(u,v);
        I[v].push_back(u);
        out[u]++,in[v]++;
    }
    for (int i=1;i<=n;i++)update(i);
    cout<<ret<<endl;
    int q;
    cin>>q;
    while(q--)
    {
        int v;
        cin>>v;
        query(v);
        cout<<ret<<endl;
    }
}