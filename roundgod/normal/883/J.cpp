#include<bits/stdc++.h>
#define maxn 230400

using namespace std;
typedef long long ll;
const ll inf=1000000000000000ll;

ll b[maxn],h[maxn],d[maxn],ans,t[maxn],n,m;
struct node{
    ll c,e;
}a[maxn];

struct seg{
    ll l,r,val,z;
}s[maxn*4];

bool cmp(node u,node v)
{
    if (u.c==v.c) return u.e<v.e;
    return u.c<v.c;
}

void build(ll p,ll l,ll r)
{
    s[p].l=l; s[p].r=r;
    if (l==r){
        s[p].val=t[l];
        s[p].z=0;
        return;
    }
    ll mid=(l+r)>>1;
    build(p<<1,l,mid);
    build((p<<1)|1,mid+1,r);
    s[p].val=min(s[p<<1].val,s[(p<<1)|1].val);
    s[p].z=0;
}

void pass(ll p)
{
    s[p].val+=s[p].z;
    if (s[p].l!=s[p].r) s[p<<1].z+=s[p].z,s[(p<<1)|1].z+=s[p].z;
    s[p].z=0;
}

void update(ll p,ll l,ll r,ll w)
{
    if (s[p].l>r||s[p].r<l) {pass(p);return;}
    if (s[p].l>=l&&s[p].r<=r) {
        s[p].z+=w;
        pass(p);
    //cout << p << ' ' << l << ' ' << r << ' ' << w << endl;
    //cout << s[p].l << ' ' << s[p].r << endl;
        return;
    }
    pass(p);
    update(p<<1,l,r,w);
    update((p<<1)|1,l,r,w);
    s[p].val=min(s[p<<1].val,s[(p<<1)|1].val);
}

ll qry(ll p,ll l,ll r)
{
    pass(p);
    if (s[p].l>r||s[p].r<l) return inf;
    if (s[p].l>=l&&s[p].r<=r) return s[p].val;
    return min(qry(p<<1,l,r),qry((p<<1)|1,l,r));
}

int main()
{
    scanf("%d%d",&n,&m);
    for (ll i=1;i<=n;i++) scanf("%lld",&b[i]);
    d[n]=b[n]; for (ll i=n-1;i;i--) d[i]=max(d[i+1],b[i]);
    for (ll i=1;i<=n;i++) t[i]=t[i-1]+b[i];
    build(1,1,n);
    for (ll i=0;i<m;i++) scanf("%lld",&a[i].e);
    for (ll i=0;i<m;i++) scanf("%lld",&a[i].c);
    sort(a,a+m,cmp);
    for (ll i=0;i<m;i++)
    {
        if (d[1]<a[i].e) continue;
        ll lf,rt,mid;
        lf=0; rt=n+1;
        while (rt-lf>1){
            mid=(lf+rt)>>1;
            if (d[mid]<a[i].e) rt=mid; else lf=mid;
        }
        if (qry(1,lf,n)>=a[i].c) update(1,lf,n,-a[i].c),ans++;
        //for (ll j=1;j<=n;j++) cout << qry(1,j,j) << ' ' ; cout << endl;
    }
    cout << ans << endl;
}