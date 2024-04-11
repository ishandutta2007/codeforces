#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

int tin[N],tout[N],timee;
int a[N];
int n;
int v1[N*4],k1[N*4],w1[N*4];
vector<int> v[N];
int ans[N];
vector<int> ps[N];

void dfs(int l, int pr)
{
    timee++;
    tin[l]=timee;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dfs(v[l][j],l);
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

inline void update(int i, int l, int r, int tl, int tr, int x)
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
    if (v1[i+i]<v1[i+i+1]) {v1[i]=v1[i+i]; k1[i]=k1[i+i];} else
    if (v1[i+i+1]<v1[i+i]) {v1[i]=v1[i+i+1]; k1[i]=k1[i+i+1];} else
        {
            v1[i]=v1[i+i];
            k1[i]=k1[i+i]+k1[i+i+1];
        }
}

/**
pair<int,int> get(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return mp(v1[i],k1[i]);
    if (tl>r||l>tr) return mp(2e9,0);
    push(i);
    int mid=(l+r)/2;
    pair<int,int> p1=get(i+i,l,mid,tl,tr),p2=get(i+i+1,mid+1,r,tl,tr);
    if (p1.ff<p2.ff) return p1;
    if (p1.ff>p2.ff) return p2;
    return mp(p1.ff,p1.ss+p2.ss);
}
**/

void build(int i, int l, int r)
{
    v1[i]=0;
    w1[i]=0;
    k1[i]=r-l+1;
    if (l==r) return;
    int mid=(l+r)/2;
    build(i+i,l,mid);
    build(i+i+1,mid+1,r);
}

void dfss(int l, int pr)
{
    ///cout<<"! "<<l<<endl;
    for (int j=0; j<ps[l].size(); j++)
    {
        update(1,1,n,tin[ps[l][j]],tout[ps[l][j]],1);
        ///cout<<tin[ps[l][j]]<<".."<<tout[ps[l][j]]<<endl;
    }
    update(1,1,n,tin[l],tin[l],1);
    if (v1[1]==0) ans[l]=n-1-k1[1]; else ans[l]=n-1;
    update(1,1,n,tin[l],tin[l],-1);
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr) dfss(v[l][j],l);
    for (int j=0; j<ps[l].size(); j++)
        update(1,1,n,tin[ps[l][j]],tout[ps[l][j]],-1);
    ///cout<<"- "<<l<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    cin>>n>>m;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    dfs(1,0);
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        ps[l].pb(r);
        ps[l].pb(l);
        ps[r].pb(l);
        ps[r].pb(r);
    }
    build(1,1,n);
    dfss(1,0);
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}