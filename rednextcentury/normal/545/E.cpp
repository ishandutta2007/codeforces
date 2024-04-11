#include<bits/stdc++.h>
using namespace std;
vector<int> id[1000000];
vector<int> adj[1000000];
vector<long long> len[1000000];
long long dist[1000000];
bool vis[1000000];
struct state
{
    int v;
    int id;
    long long len;
    long long y;
};
bool operator<(state a,state b)
{
    if (a.len==b.len)
        return a.y<b.y;
    return a.len<b.len;
}
state S(int a,int b,long long c,long long y)
{
    state x;
    x.v=a,x.id=b,x.len=c;
    x.y=y;
    return x;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int s,e;
        long long v;
        scanf("%d%d%I64d",&s,&e,&v);
        adj[s].push_back(e);
        adj[e].push_back(s);
        len[s].push_back(v);
        len[e].push_back(v);
        id[s].push_back(i);
        id[e].push_back(i);
    }
    int f;
    cin>>f;
    multiset<state> s;
    vector<int> ret;
    s.insert(S(f,0,0,0));
    long long tt=0;
    while(!s.empty())
    {
        state cur=*s.begin();
        s.erase(s.begin());
        if (vis[cur.v])continue;
        vis[cur.v]=1;
        tt+=cur.y;
        if (cur.id!=0)
            ret.push_back(cur.id);
        dist[cur.v]=cur.len;
        for (int i=0;i<adj[cur.v].size();i++)
            s.insert(S(adj[cur.v][i],id[cur.v][i],dist[cur.v]+len[cur.v][i],len[cur.v][i]));
    }
    printf("%I64d\n",tt);
    for (int i=0;i<ret.size();i++)
        printf("%d ",ret[i]);
    printf("\n");
}