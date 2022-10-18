#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int tin[N],tout[N],timee,deep[N];
int a[N];
ll v1[N*4],w1[N*4],v2[N*4],w2[N*4];
vector<int> vv[N];

void dfs(int l, int pr)
{
    deep[l]=deep[pr]+1;
    timee++;
    tin[l]=timee;
    for (int j=0; j<vv[l].size(); j++)
        if (vv[l][j]!=pr) dfs(vv[l][j],l);
    tout[l]=timee;
}

inline void push(int i, int l, int r, int mid)
{
    if (!w1[i]&&!w2[i]) return;
    w1[i+i]+=w1[i];
    w1[i+i+1]+=w1[i];
    v1[i+i]+=w1[i]*1ll*(mid-l+1);
    v1[i+i+1]+=w1[i]*1ll*(r-mid);
    w1[i]=0;
    w2[i+i]+=w2[i];
    w2[i+i+1]+=w2[i];
    v2[i+i]+=w2[i]*1ll*(mid-l+1);
    v2[i+i+1]+=w2[i]*1ll*(r-mid);
    w2[i]=0;
}

inline void update(int i, int l, int r, int tl, int tr, ll x, ll y)
{
    if (tl<=l&&r<=tr)
    {
        v1[i]+=(r-l+1)*1ll*x;
        w1[i]+=x;
        v2[i]+=(r-l+1)*1ll*y;
        w2[i]+=y;
        return;
    }
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    push(i,l,r,mid);
    update(i+i,l,mid,tl,tr,x,y);
    update(i+i+1,mid+1,r,tl,tr,x,y);
    v1[i]=v1[i+i]+v1[i+i+1];
    v2[i]=v2[i+i]+v2[i+i+1];
}

inline pair<ll,ll> get(int i, int l, int r, int x)
{
    if (x<l||x>r) return mp(0,0);
    if (l==r) return mp(v1[i],v2[i]);
    int mid=(l+r)/2;
    push(i,l,r,mid);
    if (x<=mid) return get(i+i,l,mid,x); else return get(i+i+1,mid+1,r,x);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        vv[l].pb(r);
        vv[r].pb(l);
    }
    dfs(1,0);
    for (int i=1; i<=m; i++)
    {
        int t;
        cin>>t;
        if (t==1)
        {
            int l,x;
            cin>>l>>x;
            ///cout<<tin[l]<<".."<<tout[l]<<endl;
            if (deep[l]%2==0) update(1,1,n,tin[l],tout[l],x,0);
            else update(1,1,n,tin[l],tout[l],0,x);
        } else
        {
            int l;
            cin>>l;
            pair<ll,ll> p=get(1,1,n,tin[l]);
            ///cout<<l<<" - "<<p.ff<<" "<<p.ss<<endl;
            if (deep[l]%2==0) cout<<p.ff-p.ss+a[l]<<"\n";
            else cout<<p.ss-p.ff+a[l]<<"\n";
        }
    }
}