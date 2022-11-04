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

void run() {
    constexpr int mod = 998'244'353;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        char tp;
        cin >> tp;
        if (tp == '+') {
            cin >> x;
        } else {
            x = -1;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] == -1) continue;
        vector<int> dp(n, 0);
        dp[0] = 1;
        auto forwardKek = [&dp, mod, n]() {
            for (int i = n - 1; i > 0; --i) {
                if ((dp[i] += dp[i - 1]) >= mod) {
                    dp[i] -= mod;
                }
            }
        };
        auto backwardKek = [&dp, mod, n]() {
            for (int i = 0; i + 1 < n; ++i) {
                if ((dp[i] += dp[i + 1]) >= mod) {
                    dp[i] -= mod;
                }
            }
        };
        int mul = 1;
        for (int j = 0; j < i; ++j) {
            if (v[j] == -1) {
                if ((dp[0] <<= 1) >= mod) {
                    dp[0] -= mod;
                }
                backwardKek();
            } else if (v[j] <= v[i]) {
                forwardKek();
            } else {
                if ((mul <<= 1) >= mod) {
                    mul -= mod;
                }
            }
        }
        for (int j = i + 1; j < n; ++j) {
            if (v[j] == -1) {
                backwardKek();
            } else if (v[j] < v[i]) {
                forwardKek();
            } else {
                if ((mul <<= 1) >= mod) {
                    mul -= mod;
                }
            }
        }
        ll cur = accumulate(all(dp), 0ll) % mod;
        cur *= mul;
        cur %= mod;
        cur *= v[i];
        cur %= mod;
        ans += cur;
    }
    cout << ans % mod << endl;
}