#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 150005
#define MAXM 805
#define INF 1000000000000000000LL
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,tot,t;
vector<int> G[MAXN];
int deg[MAXN],st[MAXN],ed[MAXN],fa[MAXN],sz[MAXN];
int bigid[MAXN];
int save[MAXN][MAXM];
int blockadd[MAXM];
int inv,addall;
vector<int> bigdeg;
vector<int> tmp;
const int threshold=200;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD; if(a<0) a+=MOD;}
void dec(int &a,int b) {a-=b; if(a>=MOD) a-=MOD; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void dfs_sz(int v,int p)
{
    sz[v]=1; tmp.push_back(v);
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs_sz(to,v);
        sz[v]+=sz[to];
    }
}
void dfs(int v,int p)
{
    st[v]=++t; fa[v]=p;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
    }
    ed[v]=t;
}
struct segtree
{
    int sum[4*MAXN],len[4*MAXN],lazy[4*MAXN];
    void pushup(int k)
    {
        sum[k]=sum[k*2];
        add(sum[k],sum[k*2+1]);
    }
    void sadd(int k,int v)
    {
        add(sum[k],1LL*len[k]*v%MOD);
        add(lazy[k],v);
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        sadd(k*2,lazy[k]); sadd(k*2+1,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        len[k]=r-l+1;lazy[k]=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(x>r||l>y) return;
        if(l>=x&&r<=y)
        {
            sadd(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query(int k,int l,int r,int pos)
    {
        if(l==r) return sum[k];
        pushdown(k);
        int mid=(l+r)/2;
        if(pos<=mid) return query(k*2,l,mid,pos); else return query(k*2+1,mid+1,r,pos);
    }
}seg;
int main()
{
    scanf("%d%d",&n,&q); inv=pow_mod(n,MOD-2);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        if(deg[i]>=threshold)
        {
            bigid[i]=++tot;
            bigdeg.push_back(i);
            for(auto to:G[i])
            {
                dfs_sz(to,i);
                for(auto v:tmp) save[v][tot]=sz[to];
                tmp.clear();
            }
        }
    }
    dfs_sz(1,0);
    tmp.clear();
    seg.build(1,1,n);
    addall=0;
    for(int i=0;i<q;i++)
    {
        int type,v,d;
        scanf("%d%d",&type,&v);
        if(type==1)
        {
            scanf("%d",&d);
            add(addall,1LL*n*d%MOD);
            if(deg[v]<threshold)
            {
                for(auto to:G[v])
                {
                    if(to!=fa[v])
                    {
                        int toadd=1LL*sz[to]*d%MOD;
                        toadd=(MOD-toadd)%MOD;
                        seg.update(1,1,n,st[to],ed[to],toadd);
                    }
                    else
                    {
                        int toadd=1LL*(n-sz[v])*d%MOD;
                        dec(addall,toadd);
                        seg.update(1,1,n,st[v],ed[v],toadd);
                    }
                }
            }
            else add(blockadd[bigid[v]],d);
        }
        else
        {
            int ans=seg.query(1,1,n,st[v]);
            add(ans,addall);
            for(int j=1;j<=tot;j++)
            {
                dec(ans,1LL*blockadd[j]*save[v][j]%MOD);
            }
            ans=1LL*ans*inv%MOD;
            printf("%d\n",ans);
        }
    }
    return 0;
}