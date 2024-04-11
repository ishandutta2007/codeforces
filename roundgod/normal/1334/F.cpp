#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,t;
ll a[MAXN],p[MAXN],b[MAXN];
ll l,r;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
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
struct segtree
{
    ll lazy[4*MAXN],val[4*MAXN];
    void pushup(int k)
    {
        val[k]=min(val[k*2],val[k*2+1]);
    }
    void add(int k,ll v)
    {
        val[k]+=v;
        lazy[k]+=v;
    }
    void pushdown(int k)
    {
        for(int i=k*2;i<=k*2+1;i++)
            add(i,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r)
    {
        lazy[k]=0;
        if(l==r)
        {
            if(l==0) val[k]=0; else val[k]=INF;
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,ll v)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {add(k,v); return;}
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    ll query(int k,int l,int r,int pos)
    {
        if(l==r) return val[k];
        pushdown(k);
        int mid=(l+r)/2;
        if(pos<=mid) return query(k*2,l,mid,pos); else return query(k*2+1,mid+1,r,pos);
    }
}seg;
vector<int> ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
    b[m+1]=INF;
    seg.build(1,0,m);
    for(int i=1;i<=n;i++)
    {
        int id=lower_bound(b,b+m+2,a[i])-b;
        if(a[i]==b[id])
        {
            ll x=seg.query(1,0,m,id-1),y=seg.query(1,0,m,id),z=y+p[i];
            if(x<y&&x<z) seg.update(1,0,m,id,id,x-y);
            else if(z<y) seg.update(1,0,m,id,id,z-y);
        }
        else if(p[i]<0) seg.update(1,0,m,id,id,p[i]);
        seg.update(1,0,m,0,id-1,p[i]);
        if(p[i]<0) seg.update(1,0,m,id+1,m,p[i]);
    }
    ll ans=seg.query(1,0,m,m);
    if(ans>=10000000000000000LL) puts("NO");
    else
    {
        puts("YES");
        printf("%lld\n",ans);
    }
    return 0;
}