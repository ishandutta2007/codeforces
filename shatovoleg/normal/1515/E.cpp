// #pragma GCC optimize("Ofast,unroll-all-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
// #pragma GCC target("popcnt")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
// #define int ll


const int INF = (is_same<int, ll>::value ? 1e18 + 666 : 1e9 + 666);
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

// const int MEM_SIZE = 5e8;
// char mem[MEM_SIZE];
// int cur_mem_ptr = 0;

// void* operator new(size_t n) {
//     cur_mem_ptr += n;
//     return mem + cur_mem_ptr - n;
// }

// void operator delete(void*) noexcept {}
// void operator delete(void*, size_t) noexcept {}

template<class t1, class t2>
inline bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
inline bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

inline int bpow(int a, int b, int mod) {
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
    }
    return res;
}

#ifndef LOCAL
void UseFiles(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#else
void UseFiles(const string&) {}
#endif

void run();

signed main() {
    // UseFiles("taskname");
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

void run() {
    int n, mod;
    cin >> n >> mod;
    ll mod2 = 1ll * mod * mod;
    vector<int> fact(n + 1, 1), rev(n + 1, 0), rfact(n + 1, 1);
    rev[1] = 1;
    for (int i = 2; i <= n; ++i) {
        rev[i] = (int)(mod - (1ll * (mod / i) * rev[mod % i]) % mod);
        fact[i] = (int)((1ll * fact[i - 1] * i) % mod);
        rfact[i] = (int)((1ll * rfact[i - 1] * rev[i]) % mod);
    }
    int s = ((n - 1) >> 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(s + 1, 0));
    vector<int> pw2(n + 1, 0);
    pw2[1] = 1;
    for (int i = 2; i <= n; ++i) {
        pw2[i] = (pw2[i - 1] << 1);
        if (pw2[i] >= mod) {
            pw2[i] -= mod;
        }
    }
    vector<int> magic(n + 1);
    for (int i = 0; i <= n; ++i) {
        magic[i] = (int)(1ll * pw2[i] * rfact[i] % mod);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = magic[i];
        for (int j = 1; j <= s; ++j) {
            for (int space = 1; space + 1 < i; ++space) {
                dp[i][j] += dp[space][j - 1] * magic[i - space - 1];
                if (dp[i][j] >= mod2) {
                    dp[i][j] -= mod2;
                    if (dp[i][j] >= mod2) {
                        dp[i][j] -= mod2;
                    }
                }
            }
            dp[i][j] %= mod;
        }
    }
    int ans = 0;
    // cerr << dp[n][s] << endl;
    for (int i = 0; i <= s; ++i) {
        ans += (int)(dp[n][i] * fact[n - i] % mod);
        if (ans >= mod) {
            ans -= mod;
        }
    }
    cout << ans << endl;
}