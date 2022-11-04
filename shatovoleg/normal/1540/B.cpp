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

constexpr int mod = 1e9 + 7;
vector<ll> rev;

void init(int n) {
    ++n;
    rev.resize(n, 0);
    rev[1] = 1;
    for (int i = 2; i < n; ++i) {
        rev[i] = mod - (mod / i) * rev[mod % i] % mod;
    }
}

vector<vector<int>> g;
vector<int> sz, prv;

int calc_sz(int v, int p = -1) {
    int res = 1;
    prv[v] = p;
    for (auto& x : g[v]) {
        if (x == p) continue;
        res += calc_sz(x, v);
    }
    return sz[v] = res;
}

void run() {
    int n;
    cin >> n;
    init(n);
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0) {
                dp[i][j] = 1;
                continue;
            }
            if (j == 0) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) * rev[2] % mod;
        }
    }
    g.resize(n);
    sz.resize(n);
    prv.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> tmp;
    ll res = 0;
    for (int v = 0; v < n; ++v) {
        calc_sz(v);
        for (int u = v + 1; u < n; ++u) {
            for (int uu = u; uu != -1; uu = prv[uu]) {
                tmp.pb(sz[uu]);
            }
            for (int i = len(tmp) - 1; i > 0; --i) {
                tmp[i] -= tmp[i - 1];
            }
            for (int i = 0; i < len(tmp); ++i) {
                ll cur = tmp[i] * rev[n] % mod;
                cur %= mod;
                cur *= dp[i][len(tmp) - i - 1];
                cur %= mod;
                res += cur;
            }
            tmp.clear();
        }
    }
    cout << res % mod << endl;
}