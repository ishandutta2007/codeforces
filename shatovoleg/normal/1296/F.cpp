// #pragma GCC optimize("Ofast,unroll-all-loops")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define mp make_pair
#define int ll

#define debug(x) cout << #x << " = " << x << endl;

const int INF = (is_same<int, ll>::value ? 1e18 + 666 : 1e9 + 666);

// const int MEM_SIZE = 1e8;
// char mem[MEM_SIZE];
// int cur_mem_ptr = 0;

// void* operator new(size_t n) {
//     cur_mem_ptr += n;
//     return mem + cur_mem_ptr - n;
// }

// void operator delete(void*) noexcept {}
// void operator delete(void*, size_t) noexcept {}

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
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
    // UseFiles("squads");
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

vector<vector<pii>> g;

bool get_path(int u, int v, vector<int> &e, int p = -1) {
    if (u == v) {
        return true;
    }
    for (auto &[x, num] : g[u]) {
        if (x == p) {
            continue;
        }
        if (get_path(x, v, e, u)) {
            e.pb(num);
            return true;
        }
    }
    return false;
}

void run() {
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb({v, i});
        g[v].pb({u, i});
    }
    vector<int> wght(n - 1, 1);
    int m;
    cin >> m;
    vector<array<int, 3>> constraints(m);
    for (auto &[u, v, w] : constraints) {
        cin >> u >> v >> w;
        --u, --v;
    }
    for (auto &[u, v, w] : constraints) {
        vector<int> e;
        get_path(u, v, e);
        for (auto &x : e) {
            cmax(wght[x], w);
        }
    }
    for (auto &[u, v, w] : constraints) {
        vector<int> e;
        get_path(u, v, e);
        int mn = (int)1e6;
        for (auto &x : e) {
            cmin(mn, wght[x]);
        }
        if (mn != w) {
            cout << -1 << endl;
            return;
        }
    }
    for (auto &x : wght) {
        cout << x << " ";
    }
    cout << endl;
}