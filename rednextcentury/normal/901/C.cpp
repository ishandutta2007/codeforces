#include<bits/stdc++.h>
using namespace std;
#define N 1000005
long long tim=0;
long long vis[N];
long long tin[N], tout[N], isBridge[N], minAncestor[N];
vector<pair<long long, long long> > g[N];
vector<long long> adj[N];
void DFS(long long k, long long par)
{
	vis[k]=1;
	tin[k]=++tim;
	minAncestor[k]=tin[k];
	for(auto it:g[k])
	{
		if(it.first==par)
			continue;
		if(vis[it.first])
		{
			minAncestor[k]=min(minAncestor[k], tin[it.first]);
			continue;
		}
		DFS(it.first, k);
		minAncestor[k]=min(minAncestor[k], minAncestor[it.first]);
		if(minAncestor[it.first]>tin[k])
			isBridge[it.second]=1;
	}
	tout[k]=tim;
}
vector<long long> cur;
void dfs(long long v,long long pa)
{
    vis[v]=1;
    cur.push_back(v);
    for (auto u:adj[v])
    {
        if (vis[u])continue;
        dfs(u,v);
    }
}
long long id[N],sz[N];
long long cnt[N],L[N],val[N];
long long tree[N*5];
long long lazy[N*5];
void lzy(long long x,long long l,long long r)
{
    long long len = r-l+1;
    tree[x]+=len*lazy[x];
    lazy[x*2]+=lazy[x];
    lazy[x*2+1]+=lazy[x];
    lazy[x]=0;
}
void upd(long long x,long long l,long long r,long long s,long long e)
{
    lzy(x,l,r);
    if (s>r || e<l)return;
    if (l>=s&&r<=e)
    {
        lazy[x]++;
        lzy(x,l,r);
        return;
    }
    else
    {
        upd(x*2,l,(l+r)/2,s,e);
        upd(x*2+1,(l+r)/2+1,r,s,e);
        tree[x]=tree[x*2]+tree[x*2+1];
    }
}
long long query(long long x,long long l,long long r,long long s,long long e)
{
    lzy(x,l,r);
    if (s>r || e<l)return 0;
    if (l>=s && r<=e)
        return tree[x];
    return query(x*2,l,(l+r)/2,s,e)+query(x*2+1,(l+r)/2+1,r,s,e);
}
struct Query
{
    long long l,r;
    long long id;
};
bool operator<(Query A,Query B)
{
    return A.r<B.r;
}
vector<Query> Q;
long long ret[N];
int main()
{
    long long n,m;
    scanf("%lld%lld",&n,&m);
    for (long long i=1;i<=m;i++)
    {
        long long u,v;
        scanf("%lld%lld",&u,&v);
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    for (long long i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            DFS(i,-1);
        }
    }
    for (long long i=1;i<=n;i++)
    {
        for (auto x:g[i])
        {
            if (isBridge[x.second])continue;
            adj[i].push_back(x.first);
        }
    }
    memset(vis,0,sizeof(vis));
    long long num=1;
    for (long long i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            cur.clear();
            dfs(i,-1);
            if (cur.size()>1)
            {
                for (auto x:cur)
                {
                    assert(adj[x].size()==2);
                    id[x]=num;
                }
                sz[num]=cur.size();
                assert(sz[num]%2);
                num++;
            }
        }
    }

    sz[0]=1e9;
    long long l=1;
    long long active=0;
    for (long long r=1;r<=n;r++)
    {
        cnt[id[r]]++;
        if (cnt[id[r]]==sz[id[r]])active++;
        while(active)
        {
            if (cnt[id[l]]==sz[id[l]])active--;
            cnt[id[l]]--;
            l++;
        }
        L[r]=l;
        val[r]=r-l+1;
    }
    long long q;
    scanf("%lld",&q);
    for (long long i=1;i<=q;i++)
    {
        Query x;
        scanf("%lld%lld",&x.l,&x.r);
        x.id = i;
        Q.push_back(x);
    }
    sort(Q.begin(),Q.end());
    long long r=1;
    for (auto x:Q)
    {
        while(r<=x.r)
        {
            assert(L[r]<=r);
            upd(1,1,n,L[r],r);
            r++;
        }
        ret[x.id] = query(1,1,n,x.l,x.r);
    }
    for (long long i=1;i<=q;i++)
        printf("%lld\n",ret[i]);
}