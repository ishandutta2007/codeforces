#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 5e5 + 11;

int tin[N],tout[N],timee;
ll deep[N];
int a[N];
int n;
ll v1[N*4],w1[N*4];
vector<pair<int,ll> > vv[N];
vector<pair<int,pair<int,int> > > v[N];
ll ans[N];

void dfs(int l)
{
    timee++;
    tin[l]=timee;
    for (int j=0; j<vv[l].size(); j++)
    {
        deep[vv[l][j].ff]=deep[l]+vv[l][j].ss;
        dfs(vv[l][j].ff);
    }
    tout[l]=timee;
}

inline void push(int i)
{
    if (!w1[i]) return;
    w1[i+i]+=w1[i];
    w1[i+i+1]+=w1[i];
    v1[i+i]+=w1[i];
    v1[i+i+1]+=w1[i];
    w1[i]=0;
}

inline void update(int i, int l, int r, int tl, int tr, ll x)
{
    if (tl<=l&&r<=tr)
    {
        v1[i]+=x;
        w1[i]+=x;
        return;
    }
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    push(i);
    update(i+i,l,mid,tl,tr,x);
    update(i+i+1,mid+1,r,tl,tr,x);
    v1[i]=min(v1[i+i],v1[i+i+1]);
}

ll get(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v1[i];
    if (tl>r||l>tr) return 2e18;
    push(i);
    int mid=(l+r)/2;
    return min(get(i+i,l,mid,tl,tr),get(i+i+1,mid+1,r,tl,tr));
}

void build(int i, int l, int r)
{
    if (l==r)
    {
        if ((int)vv[l].size()==0) v1[i]=deep[l];
        else v1[i]=2e18;
        ///cout<<l<<".."<<r<<" - "<<v1[i]<<endl;
        return;
    }
    int mid=(l+r)/2;
    build(i+i,l,mid);
    build(i+i+1,mid+1,r);
    v1[i]=min(v1[i+i],v1[i+i+1]);
    ///cout<<l<<".."<<r<<" = "<<v1[i]<<endl;
}

void dfss(int l)
{
    for (int j=0; j<v[l].size(); j++)
        ans[v[l][j].ff]=get(1,1,n,v[l][j].ss.ff,v[l][j].ss.ss);
    for (int j=0; j<vv[l].size(); j++)
    {
        int to=vv[l][j].ff;
        int c1=tin[to],c2=tout[to];
        update(1,1,n,1,c1-1,vv[l][j].ss);
        update(1,1,n,c1,c2,-vv[l][j].ss);
        update(1,1,n,c2+1,n,vv[l][j].ss);
        dfss(vv[l][j].ff);
        update(1,1,n,1,c1-1,-vv[l][j].ss);
        update(1,1,n,c1,c2,vv[l][j].ss);
        update(1,1,n,c2+1,n,-vv[l][j].ss);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    cin>>n>>m;
    for (int i=2; i<=n; i++)
    {
        int l,p;
        cin>>l>>p;
        vv[l].pb(mp(i,p));
    }
    dfs(1);
    build(1,1,n);
    for (int i=1; i<=m; i++)
    {
        int x,l,r;
        cin>>x>>l>>r;
        v[x].pb(mp(i,mp(l,r)));
    }
    dfss(1);
    for (int i=1; i<=m; i++)
        cout<<ans[i]<<"\n";
}