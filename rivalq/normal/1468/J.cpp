#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define int long long
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

const int N = 200005;

int p[N],r[N];
int parent(int i)
{
    if(i==p[i])
        return i;
    return p[i] = parent(p[i]);
}
void merge(int x,int y)
{
    x = parent(x),y = parent(y);
    if(x == y)
        return ;
    if(r[x]>r[y])
        swap(x,y);
    p[x] = y;
    r[y] += r[x];
}
int _runtimeTerror_()
{
    int n,m,k;
    cin>>n>>m>>k;
    ll ans = INF;
    vector<pair<int,pii>> edk,edg;
    for(int i=0;i<m;++i)
    {
        int x,y,w;
        cin>>x>>y>>w;
        if(w<=k)
            edk.pb({w,{x,y}});
        else
            edg.pb({w,{x,y}});
    }
    sort(all(edg));
    sort(all(edk));
    auto clear = [&]()
    {
        for(int i=1;i<=n;++i)
            p[i] = i,r[i] = 0;
    };
    clear();
    int cnt = 0;
    for(auto &j:edk)
    {
        if(parent(j.S.F) != parent(j.S.S))
            ++cnt,merge(j.S.F,j.S.S);
    }
    if(cnt == n-1)
    {
        amin(ans,k - edk.back().F);
        if(!edg.empty())
        {
            amin(ans,edg[0].F-k);
        }
    }
    ll val = 0;
    for(auto j:edg)
    {
        if(cnt == n-1)
            break;
        if(parent(j.S.F) != parent(j.S.S))
            ++cnt,merge(j.S.F,j.S.S),val += j.F-k;
        if(cnt == n-1)
        {
            amin(ans,val);
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}

signed main()
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