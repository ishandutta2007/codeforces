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
    string s;
    cin>>s;
    vector<pii> c;
    int x = 0,y = 0;
    for(auto j:s)
    {
        x += j=='R';
        x -= j=='L';
        y += j=='U';
        y -= j=='D';
        c.pb({x,y});
    }
    for(int i=0;i<sz(c);++i)
    {
        int x = 0,y = 0;
        for(auto j:s)
        {
            x += j=='R';
            x -= j=='L';
            y += j=='U';
            y -= j=='D';
            if(x==c[i].F && y == c[i].S)
            {
                x -= j=='R';
                x += j=='L';
                y -= j=='U';
                y += j=='D';
            }
        }
        if(x==0 && y==0)
        {
            cout<<c[i].F<<" "<<c[i].S<<"\n";
            return 0;
        }
    }
    cout<<"0 0\n";
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