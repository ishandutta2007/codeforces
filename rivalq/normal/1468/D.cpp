#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

int _runtimeTerror_()
{
    ll n,x,y,m;
    cin>>n>>m>>x>>y;
    vector<ll> a(m);
    for(int i=0;i<m;++i)
        cin>>a[i];
    sort(all(a));
    ll d = 0;
    if(x<y)
        d += x-1;
    if(x>y)
        d += n-x;
    ll dif = abs(x-y);
    ll num = dif - 1;
    ll t = d + dif;
    assert(num>=0);
    ll mx = -1;
    amin(num,m);
    ll ans = 0;
    vector<ll> p(m+3,0);
    for(int i=0;i<num;++i)
    {
        if(a[i]>t)
            continue;
        ll x = t-a[i];
        p[i+1] += 1;
        p[min(i+x+1,m+1)] -= 1;
    }
    ll sum = 0;
    for(int i=0;i<=m;++i)
    {
        sum += p[i];
        amax(ans,sum);
    }
    cout<<ans<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}