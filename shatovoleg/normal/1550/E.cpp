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

void solve();

void run() {
    int n = 1;
    // cin >> n;
    while (n --> 0) {
        solve();
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> closest_other(n, vector<int>(k, n));
    {
        vector<int> last(k, n);
        vector<int> pref_min(k + 1, n), suff_min(k + 1, n);
        for (int i = n - 1; i > -1; --i) {
            if (s[i] != '?') {
                last[s[i] - 'a'] = i;
            }
            for (int j = 0; j < k; ++j) {
                pref_min[j + 1] = min(pref_min[j], last[j]);
            }
            for (int j = k - 1; j > -1; --j) {
                suff_min[j] = min(suff_min[j + 1], last[j]);
            }
            for (int j = 0; j < k; ++j) {
                closest_other[i][j] = min(pref_min[j], suff_min[j + 1]);
            }
        }
    }
    vector<vector<int>> closest_suitable(n + 1, vector<int>(k, n));
    vector<int> dp(1 << k);
    int l = 0, r = n / k + 1;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        for (int i = n - 1; i > -1; --i) {
            for (int j = 0; j < k; ++j) {
                closest_suitable[i][j] = closest_suitable[i + 1][j];
                if (closest_other[i][j] - i >= mid) {
                    closest_suitable[i][j] = i;
                }
            }
        }
        fill(all(dp), n + 1);
        dp[0] = 0;
        for (int msk = 0; msk < (1 << k); ++msk) {
            if (dp[msk] >= n) continue;
            for (int i = 0; i < k; ++i) {
                if (msk & (1 << i)) continue;
                if (closest_suitable[dp[msk]][i] != n) {
                    cmin(dp[msk | (1 << i)], closest_suitable[dp[msk]][i] + mid);
                }
            }
        }
        if (dp.back() != n + 1) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
}