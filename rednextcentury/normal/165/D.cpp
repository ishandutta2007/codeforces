#include <bits/stdc++.h>
using namespace std;

#define root 0
#define N 101000
#define LN 18

vector <int> adj[N], costs[N], indexx[N];
int baseArray[N], ptr;
int chainNo, chainInd[N], chainHead[N], posInBase[N];
int depth[N], pa[LN][N], otherEnd[N], subsize[N];
int st[N*6], qt[N*6],dist[N];
void make_tree(int cur, int s, int e)
{
	if (s+1==e)
        st[cur]=baseArray[s];
    else
    {
        make_tree(cur*2,s,(s+e)/2);
        make_tree(cur*2+1,(s+e)/2,e);
        st[cur]=max(st[cur*2],st[cur*2+1]);
    }
}
void update_tree(int cur, int s, int e, int x, int val)
{
	if(s > x || e <= x)
        return;
	if( s==x && x+1==e)
		st[cur]=val;
    else
    {
        update_tree(cur*2, s, (s+e)/2, x, val);
        update_tree(cur*2+1, (s+e)/2,e, x, val);
        st[cur] = max(st[cur*2],st[cur*2+1]);
    }
}
int query_tree(int cur, int s, int e, int S, int E)
{
	if(s >= E || e <= S)
		return -1;
	if(s >= S && e <= E)
        return st[cur];
	return max(query_tree(cur*2, s, (s+e)/2, S, E),query_tree(cur*2+1, (s+e)/2, e, S, E));
}
int query_up(int u, int v)
{
    int U,V=chainInd[v],ret=-1;
    while(1)
    {
        U=chainInd[u];
        if (U==V)
        {

            ret=max(ret,query_tree(1,0,ptr,posInBase[v]+1,posInBase[u]+1));
            break;
        }
        else
        {

            ret=max(ret, query_tree(1,0,ptr,posInBase[chainHead[U]],posInBase[u]+1));
            u = chainHead[U];
            u = pa[0][u];
        }
    }
    return ret;
}
int LCA(int u, int v)
{
    if (depth[u]<depth[v])
        swap(u,v);
    int x=depth[u]-depth[v];
    for (int i=0;i<LN;i++)
        if ((1<<i) & x)
            u=pa[i][u];
    if (u==v)return v;
    for (int i=LN-1;i>=0;i--)
    {
        if (pa[i][u]!=pa[i][v])
            u=pa[i][u],v=pa[i][v];
    }
    return pa[0][v];
}
int query(int u, int v)
{
	int x=LCA(u,v);
	return max(query_up(u,x),query_up(v,x));
}
void change(int i, int val)
{
	int u = otherEnd[i];
	update_tree(1, 0, ptr, posInBase[u], val);
}
void HLD(int v,int cost,int prev)
{
    if (chainHead[chainNo]==-1)
        chainHead[chainNo]=v;
    chainInd[v]=chainNo;
    posInBase[v]=ptr;
    baseArray[ptr++]=cost;
    int best=-1,ans=-1;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (u==prev)
            continue;
        if (subsize[u]>ans)
            ans=subsize[u],best=i;
    }
    if (ans!=-1)
        HLD(adj[v][best],costs[v][best],v);
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (i==best || u==prev)
            continue;
        chainNo++;
        HLD(u,costs[v][i],v);
    }
}
void dfs(int v,int _p)
{
    subsize[v]=1;
    for (int i=0;i<adj[v].size();i++)
    {
        if (adj[v][i]!=_p)
        {
            int u=adj[v][i];
            depth[u]=depth[v]+1;
            otherEnd[indexx[v][i]]=u;
            dfs(u,v);
            pa[0][u]=v;
            subsize[v]+=subsize[u];
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n; i++)
    {
        chainHead[i] = -1;
        for(int j=0; j<LN; j++)
            pa[j][i] = -1;
    }
    for(int i=1; i<n; i++)
    {
        int u, v, c=0;
        scanf("%d%d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        costs[u].push_back(c);
        indexx[u].push_back(i-1);
        adj[v].push_back(u);
        costs[v].push_back(c);
        indexx[v].push_back(i-1);
    }
    chainNo = 0;
    dfs(root, -1);
    HLD(root, -1, -1);
    make_tree(1, 0, ptr);
    for(int i=1; i<LN; i++)
        for(int j=0; j<n; j++)
            if(pa[i-1][j] != -1)
                pa[i][j] = pa[i-1][pa[i-1][j]];
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int t;
        scanf("%d",&t);
        if (t==3)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            u--,v--;
            if (query(u,v)==1)
                printf("-1\n");
            else
                printf("%d\n",depth[u]+depth[v]-2*depth[LCA(u,v)]);
        }
        else
        {
            int i;
            scanf("%d",&i);
            change(i-1,t-1);
        }
    }
}