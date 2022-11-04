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

struct dsu {
    vector<int> l, s;

    dsu(int n) : l(n), s(n, 1) {
        iota(all(l), 0);
    }

    int get_root(int v) {
        if (l[v] == v) return v;
        return l[v] = get_root(l[v]);
    }

    bool Union(int u, int v) {
        u = get_root(u); v = get_root(v);
        if (u == v) return false;
        if (s[u] > s[v]) swap(u, v);
        l[u] = v;
        s[v] += s[u];
        return true;
    }
};

using ChildType = tuple<ll, int, struct Node*>;

struct Node {
    set<ChildType> childs;

    Node() = default;
    Node(set<ChildType>&& _childs) : childs(move(_childs)) {}
    Node(const Node&) = delete;
};


void Unite(set<ChildType>& a, set<ChildType>& b) {
    if (len(a) < len(b)) {
        a.swap(b);
    }
    for (auto& x : b) {
        a.insert(x);
    }
}

void Unite(set<ChildType>& a, Node* b) {
    Unite(a, b->childs);
    delete b;
}

int x;
vector<int> a;
vector<vector<pii>> g;
vector<int> ans;

pair<ll, Node*> dfs(int v, int p = -1) {
    ll sm = a[v];
    set<ChildType> edges;
    for (auto& [u, idx] : g[v]) {
        if (u == p) continue;
        auto [s, node] = dfs(u, v);
        if (sm + s >= x) {
            ans.pb(idx);
            Unite(edges, node);
            sm += s - x;
        } else {
            edges.emplace(x - s, idx, node);
        }
    }
    while (!edges.empty() && sm - get<0>(*edges.begin()) >= 0) {
        auto [diff, idx, ch] = *edges.begin();
        edges.erase(edges.begin());
        sm -= diff;
        ans.pb(idx);
        Unite(edges, ch);
    }
    return {sm, new Node(move(edges))};
}

void run() {
    int n, m;
    cin >> n >> m >> x;
    a.resize(n);
    for (auto& x : a) {
        cin >> x;
    }
    if (accumulate(all(a), 0ll) < 1ll * x * (n - 1)) {
        cout << "NO" << endl;
        return;
    }
    dsu d(n);
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (d.Union(u, v)) {
            g[u].pb({v, i});
            g[v].pb({u, i});
        }
    }
    auto [_, node] = dfs(0);
    delete node;
    cout << "YES" << endl;
    for (auto& x : ans) {
        cout << x + 1 << " ";
    }
    cout << endl;
}