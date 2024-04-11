#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             10000000
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


const int N = 502;

int dp[N][N][N];


int f[N][2];

int _runtimeTerror_()
{
    int n,m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    vector<int> pi(m+1,0);
    for(int i=1;i<m;++i) {
        int j = pi[i-1];
        while(j > 0 && b[i] != b[j]) {
            j = pi[j - 1];
        }
        if(b[i] == b[j]) {
            ++j;
        }
        else {
            j = 0;
        }
        pi[i] = j;
    }
    f[0][0] = b[0] == '0';
    f[0][1] = b[0] == '1';
    for(int i=1;i<m;++i) {
        int j = i;
        while(j > 0 && '0' != b[j]) {
            j = pi[j - 1];
        }
        if(b[j] == '0') {
            ++j;
        }
        else {
            j = 0;
        }
        f[i][0] = j;
        j = i;
        while(j > 0 && '1' != b[j]) {
            j = pi[j - 1];
        }
        // if(i == 1) {
        //     debug(j);
        // }
        if(b[j] == '1') {
            ++j;
        }
        else {
            j = 0;
        }
        f[i][1] = j;
    }
    // for(int i=0;i<m;++i) {
    //     debug(f[i][0], f[i][1], pi[i]);
    // }
    for(int i=0;i<=n;++i) {
        for(int j=0;j<=m;++j) {
            for(int k=0;k<=n-m+1;++k) {
                dp[i][j][k] = INF;
            }
        }
    }
    // debug(f[1][1]);
    dp[0][0][0] = 0;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            for(int k=0;k<=n-m+1;++k) {
                if(j == m - 1) {
                    int z = f[j][0];
                    if(z == m) {
                        amin(dp[i+1][pi[m-1]][k + 1], dp[i][j][k] + (a[i] != '0'));
                    }
                    else {
                        amin(dp[i+1][f[j][0]][k], dp[i][j][k] + (a[i] != '0'));
                    }
                    z = f[j][1];
                    if(z == m) {
                        amin(dp[i+1][pi[m-1]][k + 1], dp[i][j][k] + (a[i] != '1'));
                    }
                    else {
                        amin(dp[i+1][f[j][1]][k], dp[i][j][k] + (a[i] != '1'));
                    }
                }
                else {
                    // debug(i,j,k);
                    amin(dp[i+1][f[j][0]][k], dp[i][j][k] + (a[i] != '0'));
                    amin(dp[i+1][f[j][1]][k], dp[i][j][k] + (a[i] != '1'));
                }
            }
        }
    }
    // debug(dp[1][1][0]);
    // for(int i=0;i<=n;++i) {
    //     for(int j=0;j<=m;++j) {
    //         for(int k=0;k<=n-m+1;++k) {
    //             debug(i,j,k,dp[i][j][k]);
    //         }
    //     }
    // }
    // debug(f[2][1]);
    // debug(dp[1][2][0]);
    for(int i=0;i<=n-m+1;++i) {
        ll ans = INF;
        for(int j=0;j<m;++j) {
            amin(ans, dp[n][j][i]);
        }
        if(ans >= 1000) {
            ans = -1;
        }
        cout << ans << " ";
    }
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
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}