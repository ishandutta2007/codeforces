#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000 
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,t;
int c[MAXN];
int fa[MAXN],r[MAXN],col[MAXN];
bool valid[MAXN];
bool flag;
struct update
{
    int x,y;
    bool flipar;
    bool addrk;
};
update st[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        r[i]=0;
        col[i]=0;
    }
}
P find(int x)
{
    if(fa[x]==x) return P(x,0);
    else 
    {
        P p=find(fa[x]);
        return P(p.F,col[x]^p.S);
    }
}
bool unite(int x,int y)
{
    P p=find(x); P q=find(y);
    if(p.F==q.F) 
    {
        if(p.S==q.S) return false;
        return true;
    }
    x=p.F; y=q.F;
    if(r[x]<r[y]) 
    {
        fa[x]=y;
        st[t++]=(update){x,y,p.S==q.S,false};
        if(p.S==q.S) col[x]^=1;
    }
    else
    {
        fa[y]=x;
        st[t++]=(update){y,x,p.S==q.S,r[x]==r[y]};
        if(p.S==q.S) col[y]^=1;
        if(r[x]==r[y]) r[x]++;
    }
    return true;
}
void undo()
{
    assert(t);
    int x=st[t-1].x,y=st[t-1].y;
    //printf("undo %d %d %d\n",x,y,st[t-1].addrk);
    fa[x]=x;fa[y]=y;
    if(st[t-1].addrk) r[y]--;
    if(st[t-1].flipar) col[x]^=1;
    t--;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
map<P,int> mp;
int tot;
P save[MAXN];
vector<P> edges[MAXN];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    init(n);
    memset(valid,true,sizeof(valid));
    int s=k;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int l=c[x],r=c[y];
        if(l>r) swap(l,r);
        if(l==r)
        {
            if(!valid[l]) continue;
            if(!unite(x,y)) {valid[l]=false; s--;}
        }
        else
        {
            if(mp.find(P(l,r))==mp.end()) {mp[P(l,r)]=++tot; save[tot]=P(l,r);}
            edges[mp[P(l,r)]].push_back(P(x,y));
        }
    }
    ll ans=1LL*s*(s-1)/2;
    t=0;
    for(int i=1;i<=tot;i++)
    {
        P p=save[i];
        if(!valid[p.F]||!valid[p.S]) continue;
        for(auto e:edges[i])
        {
            if(!unite(e.F,e.S)) {ans--; break;}
        }
        while(t) undo();
    }
    printf("%lld\n",ans);
    return 0;
}