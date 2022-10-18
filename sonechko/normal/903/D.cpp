#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long double

const int N = 2e5 + 11;

ll a[N];
vector<pair<ll,ll> > vv;
pair<ll,ll> v[N*4];
map<ll,ll> mt;
void update(int i, int l, int r, int x, ll t)
{
    if (l==r) {v[i].ff=t; v[i].ss=1; return;}
    int mid=(l+r)/2;
    if (x<=mid) update(i*2,l,mid,x,t); else update(i*2+1,mid+1,r,x,t);
    v[i].ff=v[i*2].ff+v[i*2+1].ff;
    v[i].ss=v[i*2].ss+v[i*2+1].ss;
}
pair<ll,ll> sum(int i, int l, int r, int tl, int tr)
{
    if (tl<=l&&r<=tr) return v[i];
    if (tl>r||l>tr) return mp(0,0);
    int mid=(l+r)/2;
    pair<ll,ll> p1=sum(i*2,l,mid,tl,tr);
    pair<ll,ll> p2=sum(i*2+1,mid+1,r,tl,tr);
    return mp(p1.ff+p2.ff,p1.ss+p2.ss);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        vv.pb(mp(a[i],i));
    }
    sort(vv.begin(),vv.end());
    ll ans=0;
    for (int i=0; i<vv.size(); i++)
    {
        pair<ll,ll> pp1=sum(1,1,n,1,vv[i].ss);
        pair<ll,ll> pp2=sum(1,1,n,vv[i].ss,n);

        ans+=pp1.ss*vv[i].ff-pp1.ff;
        ans-=pp2.ss*vv[i].ff-pp2.ff;
        update(1,1,n,vv[i].ss,vv[i].ff);
    }
    for (int i=1; i<=n; i++)
    {
        ans-=mt[a[i]-1];
        ans+=mt[a[i]+1];
        mt[a[i]]++;
    }
    cout.precision(0);
    cout<<fixed;
    cout<<ans<<endl;
}