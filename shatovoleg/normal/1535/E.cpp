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

void solve();

void run() {
    int n = 1;
    // cin >> n;
    while (n --> 0) {
        solve();
    }
}

constexpr int maxlog = 19;

void solve() {
    int q;
    cin >> q;
    ++q;
    vector<int> a(q, 0), c(q, 0), d(q, 0);
    cin >> a[0] >> c[0];
    vector<vector<int>> up(q, vector<int>(maxlog, -1));
    fill(all(up[0]), 0);
    auto jump = [&up](int v, int h) {
        for (int i = maxlog - 1; i >= 0; --i) {
            if ((1 << i) <= h) {
                h -= (1 << i);
                v = up[v][i];
            }
        }
        return v;
    };
    auto getFirstNonZero = [&up, &a](int v) {
        for (int i = maxlog - 1; i >= 0; --i) {
            if (a[up[v][i]] > 0) {
                v = up[v][i];
            }
        }
        return v;
    };
    for (int i = 1; i < q; ++i) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int p;
            int n = i;
            cin >> p >> a[n] >> c[n];
            up[n][0] = p;
            for (int i = 1; i < maxlog; ++i) {
                up[n][i] = up[up[n][i - 1]][i - 1];
            }
            d[n] = d[p] + 1;
        } else {
            int v, w;
            cin >> v >> w;
            int h = d[v] - d[getFirstNonZero(v)];
            ll bought = 0, totalCost = 0;
            for (int i = h; i >= 0 && w > 0; --i) {
                int u = jump(v, i);
                int k = min(w, a[u]);
                bought += k;
                totalCost += 1ll * k * c[u];
                w -= k;
                a[u] -= k;
            }
            cout << bought << " " << totalCost << endl;
        }
    }
}