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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif

const int N=100005;
int lpf[N],mobius[N];

void _lpf_()
{
    lpf[1]=1;
    for(int i=2;i<=N-2;++i)
    {
        if(!lpf[i])
        {
            for(int j=i;j<=N-2;j+=i)
            {
                if(!lpf[j])
                    lpf[j]=i;
            }
        }
    }
}
void Mobius()
{
    mobius[1]=1;
    for(int i=2;i<=N-2;++i)
    {
        if(lpf[i/lpf[i]]==lpf[i])
            mobius[i]=0;
        else
            mobius[i]=-1*mobius[i/lpf[i]];
    }
}

vector<ll> divs[N];

ll f[N];


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    ll ans = 0; 

    vector<ll> dp(n+1);
    const int B = 200;
    for(int i=n;i>=1;--i) {
        vector<ll> tmp;
        for(int j=i;j<=n;j+=i) {
            tmp.push_back(a[j]);
        }
        if(sz(tmp) <= B) {
            int n = sz(tmp);
            ll val = 0;
            for(int i=0;i<n;++i) {
                for(int j=i+1;j<n;++j) {
                    val += __gcd(tmp[i], tmp[j]);
                }
            }
            dp[i] = val;
            continue;
        }
        int x = sz(tmp);
        for(int i=0;i<x;++i) {
            for(auto &j:divs[tmp[i]]) {
                ++f[j];
            }
        }
        ll val = 0;
        for(int j=1e5;j>=1;--j) {
            f[j] = f[j] * (f[j] - 1)/2;
            for(int k=2*j;k<=1e5;k+=j) {
                f[j] -= f[k];
            }
            val += j * f[j];
        }
        for(int i=0;i<x;++i) {
            for(auto &j:divs[tmp[i]]) {
                f[j] = 0;
            }
        }
        dp[i] = val;
    }

    for(int i=n;i>=1;--i) {
        for(int j=2*i;j<=n;j+=i) {
            dp[i] -= dp[j];
        }
        ans += i * dp[i];
    }   


    ans *= 2;
    for(int i=1;i<=n;++i) {
        ans += a[i] * i;
    }
    ans %= M;
    cout << ans << "\n";
    return 0;
}

int main()
{
    _lpf_();
    Mobius();
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS = 1;
    for(int i=1;i<=1e5;++i) {
        for(int j=i;j<=1e5;j+=i) {
            divs[j].push_back(i);
        }
    }
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}