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

inline int bpow(ll a, ll b, int mod) {
    int res = 1;
    a %= mod;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = int((1ll * a * res) % mod);
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

int mod;

int TheSmartestFunctionEver(const vector<int>& v, int n) { //  Not really yet
    ll ans = 0;
    for (int lower = 0; lower < len(v); ++lower) {
        for (int higher = 0; higher < lower; ++higher) {
            ll cur = 1ll * v[lower] * v[higher] % mod;
            if (lower - higher > n) {
                cur *= n * (n - 1) >> 1;
            } else {
                int k = lower - higher - 1;
                cur *= n * k - (k * (k + 1) >> 1);
            }
            ans += cur;
        }
        ans %= mod;
    }
    return int(ans % mod);
}

int SegmentFactorial(int l, int r) {
    int res = 1;
    for (int i = l; i <= r; ++i) {
        res = int(1ll * res * i % mod);
    }
    return res;
}

void run() {
    int n;
    cin >> n >> mod;
    int maxinv = (n * (n - 1)) >> 1;
    vector<vector<int>> dp(2, vector<int>(maxinv + 1, 0));
    dp[0][0] = 1;
    vector<int> res(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cerr << i << endl;
        res[i] = TheSmartestFunctionEver(dp[0], i + 2);
        int sm = 0;
        for (int j = 0; j <= maxinv; ++j) {
            sm += dp[0][j];
            if (j >= i + 2) {
                sm -= dp[0][j - i - 2];
            }
            if (sm >= mod) {
                sm -= mod;
            }
            if (sm < 0) {
                sm += mod;
            }
            dp[1][j] = sm;
        }
        swap(dp[0], dp[1]);
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += int(1ll * res[i] * SegmentFactorial(i + 3, n) % mod);
        if (ans >= mod) {
            ans -= mod;
        }
    }
    cout << ans << endl;
}