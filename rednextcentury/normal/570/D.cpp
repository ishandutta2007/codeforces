#include<bits/stdc++.h>
const int N=1e6+5;
using namespace std;

char col[N];
int even[N];
int odd[N];
int lev[N];
int cur[N];
int in[N][2];
void add(int v);
void del(int v);
vector<int> q[N];
vector<int> ret[N];

// Don't change
vector<int> adj[N];
int sz[N];
int cnt[N][26];
int st[N];
int en[N];
int node[N];

int tim=0;
void init(int v=1,int p=-1)
{
    sz[v]=1;
    node[tim]=v;
    st[v]=tim++;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (u==p)
            continue;
        lev[u]=1+lev[v];
        init(u,v);
        sz[v]+=sz[u];
    }
    en[v]=tim;
}
void dfs(int v=1,int p=-1,bool keep=0)
{
    int mx=-1;
    int big=-1;
    for(int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if(u!=p && sz[u] > mx)
          mx = sz[u], big = u;
    }
    for(int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if(u != p && u != big)
            dfs(u, v, 0);
    }
    if(big != -1)
        dfs(big, v, 1);
    for(int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if(u!=p && u!=big)
            for(int p = st[u]; p < en[u]; p++)
                add(node[p]);
    }
    add(v);
    for (int i=0;i<q[v].size();i++)
    {
        int h=q[v][i];
        if (odd[h-1]>1)
            ret[v][i]=0;
        else
            ret[v][i]=1;
    }
    if(keep == 0)
    {
        for(int p = st[v]; p < en[v]; p++)
            del(node[p]);
    }
}
//Change
void add(int v)
{
    cnt[lev[v]][col[v]-'a']++;
    if (cnt[lev[v]][col[v]-'a']%2==0)
        even[lev[v]]++,odd[lev[v]]--;
    else
        even[lev[v]]--,odd[lev[v]]++;
}
void del(int v)
{
    cnt[lev[v]][col[v]-'a']--;
    if (cnt[lev[v]][col[v]-'a']%2==0)
        even[lev[v]]++,odd[lev[v]]--;
    else
        even[lev[v]]--,odd[lev[v]]++;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=2;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        adj[p].push_back(i);
    }
    for (int i=1;i<=n;i++)
        cin>>col[i];
    for (int i=0;i<m;i++)
    {
        scanf("%d%d",&in[i][0],&in[i][1]);
        q[in[i][0]].push_back(in[i][1]);
        ret[in[i][0]].push_back(-1);
    }
    init();
    dfs();
    for (int i=0;i<m;i++)
    {
        if(ret[in[i][0]][cur[in[i][0]]++])
            printf("Yes\n");
        else
            printf("No\n");
    }
}