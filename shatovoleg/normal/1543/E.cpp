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
    int n;
    cin >> n;
    while (n --> 0) {
        solve();
    }
}

void InplaceIntersect(vector<int>& v, const vector<int>& other) {
    v.resize(set_intersection(all(v), all(other), v.begin()) - v.begin());
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(1 << n);
    for (int i = 0; i < (n << (n - 1)); ++i) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (auto& x : g) {
        sort(all(x));
    }
    vector<int> p(1 << n, -1), bp(1 << n, -1);
    p[0] = bp[0] = 0;
    for (int i = 1; i < (1 << n); ++i) {
        vector<int> st = {-1};
        for (int j = 0; j < n; ++j) {
            if (!(i & (1 << j))) continue;
            if (st == vector<int>{-1}) {
                st = g[p[i ^ (1 << j)]];
                continue;
            }
            InplaceIntersect(st, g[p[i ^ (1 << j)]]);
        }
        for (auto& x : st) {
            if (bp[x] == -1) {
                p[i] = x;
                bp[x] = i;
                break;
            }
        }
        assert(p[i] != -1);
    }
    for (auto& x : p) {
        cout << x << " ";
    }
    cout << '\n';
    if (n & (n - 1)) {
        cout << "-1\n";
        return;
    }
    vector<int> c(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
        int clr = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                clr ^= j;
            }
        }
        c[p[i]] = clr;
    }
    for (auto& x : c) {
        cout << x << " ";
    }
    cout << '\n';
}