#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 1e6 + 11;

int n,p[N];
ll tt,x[N],t[N],s[N],ans[N],mx1[N],mx2[N],kx1[N],kx2[N];
vector<int> v[N];

ll v1[N*4],v2[N*4];

void update(int i, int l, int r, int x, ll t)
{
    if (l==r) {v1[i]+=t*1ll*l; v2[i]+=t; return;}
    int mid=(l+r)/2;
    if (x<=mid) update(i*2,l,mid,x,t); else update(i*2+1,mid+1,r,x,t);
    v1[i]=v1[i*2]+v1[i*2+1];
    v2[i]=v2[i*2]+v2[i*2+1];
}

pair<ll,ll> kol(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return mp(v1[i],v2[i]);
    if (tl>r||l>tr) return mp(0,0);
    int mid=(l+r)/2;
    pair<ll,ll> p1=kol(i*2,l,mid,tl,tr),p2=kol(i*2+1,mid+1,r,tl,tr);
    return mp(p1.ff+p2.ff,p1.ss+p2.ss);
}

void dfs(int l, ll ts)
{
    ts+=s[l]*2;
    update(1,1,1000000,t[l],x[l]);
    int l1=0,r1=1e6;
    while (r1-l1>1)
    {
        int mid=(l1+r1)/2;
        if (kol(1,1,1000000,1,mid).ff>tt-ts) r1=mid-1; else l1=mid;
    }
    if (kol(1,1,1000000,1,r1).ff<=tt-ts) l1=r1;
    //cout<<l<<" - "<<l1<<endl;
    ll res=kol(1,1,1000000,1,l1).ss;
    ll g=max(0ll,(tt-ts-kol(1,1,1000000,1,l1).ff)/(l1+1));
    if (l1==1000000) g=0;
    res+=g;
    //cout<<res<<endl;
    ans[l]=res;
    mx1[l]=res;
    mx2[l]=res;
    kx1[l]=l;
    kx2[l]=l;
    for (int j=0; j<v[l].size(); j++)
    {
        dfs(v[l][j],ts);
        if (mx2[v[l][j]]>mx1[l]) {mx2[l]=mx1[l]; kx2[l]=kx1[l];
        mx1[l]=mx2[v[l][j]]; kx1[l]=v[l][j];} else
        if (mx2[v[l][j]]>mx2[l]) {mx2[l]=mx2[v[l][j]]; kx2[l]=v[l][j];}
    }
    ts-=s[l]*2;
    update(1,1,1000000,t[l],-x[l]);
}

void dfss(int l)
{
    if (kx2[l]==l)
    {
        cout<<ans[l]<<endl;
        exit(0);
    }
    dfss(kx2[l]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>tt;
    for (int i=1; i<=n; i++)
        cin>>x[i];
    for (int i=1; i<=n; i++)
        cin>>t[i];
    for (int i=2; i<=n; i++)
    {
        cin>>p[i]>>s[i];
        v[p[i]].pb(i);
    }
    dfs(1,0);
    kx2[1]=kx1[1];
    dfss(1);
}