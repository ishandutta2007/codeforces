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

vector<vector<int>> g, rg;
vector<int> color;
vector<int> top_sort;

void build_top_sort(int v) {
    color[v] = -1;
    for (auto& x : g[v]) {
        if (color[x] == -2) {
            build_top_sort(x);
        }
    }
    top_sort.pb(v);
}

void paint(int v, int c) {
    color[v] = c;
    for (auto& x : rg[v]) {
        if (color[x] == -1) {
            paint(x, c);
        }
    }
}

int condensate() {
    for (int i = 0; i < len(g); ++i) {
        if (color[i] == -2) {
            build_top_sort(i);
        }
    }
    reverse(all(top_sort));
    int c = 0;
    for (auto& x : top_sort) {
        if (color[x] == -1) {
            paint(x, c++);
        }
    }
    return c;
}

void addElem(vector<pii>& g, int val) {
    g.pb({val, 1});
    for (int j = len(g) - 1; j > 0; --j) {
        if ((g[j - 1].first = gcd(g[j - 1].first, g[j].first)) == g[j].first) {
            g[j - 1].second += g[j].second;
        }
    }
    g.resize(unique(all(g), [](pii a, pii b) { return a.first == b.first; }) - g.begin());
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    vector<pii> g;
    for (int i = n - 1; i > -1; --i) {
        addElem(g, a[i]);
    }
    int mx = 0;
    for (int i = n - 1; i > -1; --i) {
        addElem(g, a[i]);
        int sm = 0;
        for (int j = 1; j < len(g); ++j) {
            sm += g[j].second;
        }
        cmax(mx, sm);
    }
    cout << mx << endl;
}