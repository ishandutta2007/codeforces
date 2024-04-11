#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define y1 skfn

const int N = 3e6 + 11;
const int MOD = 1e9 + 7;
#define mod %MOD


map<ll,int> mt;
bool use[N];
ll p[N];
vector<ll> t;
ll a[N];

ll kor(ll x)
{
    ll l=0,r=2e9;
    while (r-l>1)
    {
        ll mid=(l+r)/2ll;
        if (mid*mid<=x) l=mid; else r=mid;
    }
    if (r*r<=x) return r;
    return l;
}

ll cub(ll x)
{
    ll l=0,r=2e6;
    while (r-l>1)
    {
        ll mid=(l+r)/2ll;
        if (mid*mid*mid<=x) l=mid; else r=mid;
    }
    if (r*r*r<=x) return r;
    return l;
}

bool good(ll x)
{
    ll p=kor(x);
    ll d=kor(p);
    if (d*d*d*d==x) {if (mt[d]==0) t.pb(d); mt[d]+=4; return true;}
    if (p*p==x) {if (mt[p]==0) t.pb(p); mt[p]+=2; return true;}
    ll c=cub(x);
    if (c*c*c==x) {if (mt[c]==0) t.pb(c); mt[c]+=3; return true;}
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
    if (good(a[i])) {} else
    {
        bool d=0;
        for (int j=1; j<=n; j++)
            if (a[i]!=a[j])
        {
            ll gg=__gcd(a[i],a[j]);
            if (gg>1)
            {
                mt[gg]++;
                mt[a[i]/gg]++;
                if (mt[gg]==1) t.pb(gg);
                if (mt[a[i]/gg]==1) t.pb(a[i]/gg);
                d=1;
                break;
            }
        }
        if (d==0)
        {
        mt[a[i]]++;
        mt[2000000000000000000+a[i]]++;
        if (mt[a[i]]==1) t.pb(a[i]);
        if (mt[2000000000000000000+a[i]]==1) t.pb(a[i]);
        }
    }
    ll ans=1;
    for (int j=0; j<t.size(); j++)
    {
        ans*=(mt[t[j]]+1);
        ans%=998244353;
    }
    cout<<ans<<endl;
  }

/**
1 300 000
**/