#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,st[MAXN],ed[MAXN],fa[MAXN],spos[MAXN],dep[MAXN],tot;
bool upd[MAXN];
vector<int> G[MAXN];
void dfs(int v,int p,int d)
{
    fa[v]=p;
    st[v]=++tot; spos[tot]=v; 
    dep[v]=d;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v,d+1);
    }
    ed[v]=tot;
}
struct segtree
{
    P maxi[4*MAXN];
    int lazy[4*MAXN];
    void pushup(int k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void pushdown(int k)
    {
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++)
        {
            maxi[i].F+=lazy[k];
            lazy[i]+=lazy[k];
        }
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0;
        if(l==r)
        {
            maxi[k]=P(dep[spos[l]],spos[l]);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            lazy[k]--; maxi[k].F+=v;
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
}seg;
ll get_min(int r,int w)
{
    int maxi=n-r-w;
    if(maxi<=n/2) return 1LL*(n-r-maxi)*(r-maxi); else return 1LL*(n-r-n/2)*(r-n/2);
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0,0);
    seg.build(1,1,n);
    int r=0,w=0;
    memset(upd,false,sizeof(upd));
    for(int i=1;i<=k;i++)
    {
        P p=seg.maxi[1];
        
            //printf("here %d %d r=%d w=%d\n",seg.maxi[1].F,seg.maxi[1].S,r,w);
        if(get_min(r+1,w+seg.maxi[1].F)<get_min(r,w))
        {
            break;
        }
        else
        {
            r++;
            w+=seg.maxi[1].F;
            int now=seg.maxi[1].S;
            while(now!=0&&!upd[now])
            {
                seg.update(1,1,n,st[now],ed[now],-1);
                upd[now]=true;
                now=fa[now];
            }
        }
    }
    //printf("r=%d w=%d\n",r,w);
    printf("%lld\n",get_min(r,w));
    return 0;
}