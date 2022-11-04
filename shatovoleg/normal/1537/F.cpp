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
    int n;
    cin >> n;
    while (n --> 0) solve();
}

vector<vector<int>> g;
vector<int> color;

bool checkBipartie(int v, int c) {
    color[v] = c;
    c ^= 1;
    for (auto& x : g[v]) {
        if (color[x] == -1) {
            if (!checkBipartie(x, c)) {
                return false;
            }
        } else if (color[x] != c) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.assign(n, vector<int>());
    color.assign(n, -1);
    vector<int> s(n);
    for (auto& x : s) {
        cin >> x;
    }
    vector<int> t(n);
    for (auto& x : t) {
        cin >> x;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    if ((accumulate(all(s), 0ll) + accumulate(all(t), 0ll)) % 2 != 0) {
        cout << "NO" << endl;
        return;
    }
    if (checkBipartie(0, 0)) {
        ll d1 = 0, d2 = 0;
        for (int i = 0; i < n; ++i) {
            if (color[i]) {
                d1 -= s[i];
                d2 -= t[i];
            } else {
                d1 += s[i];
                d2 += t[i];
            }
        }
        if (d1 != d2) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}