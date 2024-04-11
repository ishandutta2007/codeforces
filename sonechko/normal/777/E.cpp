#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define ld long double
#define sqr(a) ((a)*(a))
map<ll,ll> mt;
pair<ll,pair<ll,ll> > a[N];
vector<ll> v;
ll w[N*8],b[N*2];
void update(ll i, ll l, ll r, ll x, ll t)
{
    if (l==r) {w[i]=t; return;}
    ll mid=(l+r)/2;
    if (x<=mid) update(i+i,l,mid,x,t); else update(i+i+1,mid+1,r,x,t);
    w[i]=max(w[i+i],w[i+i+1]);
}
ll maxi(ll i, ll l, ll r, ll tl, ll tr)
{
    if (tl<=l&&r<=tr) return w[i];
    if (l>tr||r<tl) return 0;
    ll mid=(l+r)/2;
    return max(maxi(i+i,l,mid,tl,tr),maxi(i+i+1,mid+1,r,tl,tr));
}
int main()
{
    sync;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        ll l,r,k;
        cin>>l>>r>>k;
        a[i]=mp(-r,mp(-l,k));
        v.pb(l);
        v.pb(r);
    }
    sort(v.begin(),v.end());
    sort(a+1,a+n+1);
    mt[v[0]]=1;
    for (int i=1; i<v.size(); i++)
        if (v[i]!=v[i-1]) mt[v[i]]=mt[v[i-1]]+1;
    for (int i=1; i<=n; i++)
    {
        ll r=-a[i].ff,l=-a[i].ss.ff,k=a[i].ss.ss;
        ll ans=maxi(1,1,n*2,1,mt[r]-1);
        b[mt[l]]=max(b[mt[l]],ans+k);
        update(1,1,n*2,mt[l],b[mt[l]]);
    }
    cout<<w[1]<<endl;
}