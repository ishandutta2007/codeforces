#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int N = 2e5 + 10;
const int LOG = 30;

struct Node{
    int nxt[2];
    int term;
    int sz;
    Node() : term(-1), sz(0)
    {
        fill(nxt, nxt + 2, -1);
    }
};

Node trie[N * LOG];
int topTrie = 1;

int getNode() {
    return topTrie++;
}

void upd(int val, int term, int add) {
    int cur = 0;
    for (int bit = LOG - 1; bit >= 0; --bit) {
        int curBit = (val >> bit) & 1;
        int& curNxt = trie[cur].nxt[curBit]; 
        if (curNxt == -1) {
            curNxt = getNode();
        }
        trie[cur].sz += add;
        cur = curNxt;
    }
    trie[cur].sz += add;
    trie[cur].term = term;
}

pair<int, int> get(int val) {
    int cur = 0;
    int ans = 0;
    for (int bit = LOG - 1; bit >= 0; --bit) {
        int curBit = (val >> bit) & 1;
        int curNxt = trie[cur].nxt[curBit];
        if (curNxt == -1 || !trie[curNxt].sz) {
            curNxt = trie[cur].nxt[curBit ^ 1];
            ans ^= (1 << bit);
        }
        cur = curNxt;
    }
    return {ans, trie[cur].term};
}

int n;
int a[N];

int par[N];
vector<int> comps[N];
int cntComps;

int getPar(int v) {
    if (v == par[v]) return v;
    return par[v] = getPar(par[v]);
}

bool connect(int a, int b) {
    return getPar(a) == getPar(b);
}

void uni(int a, int b) {
    a = getPar(a);
    b = getPar(b);
    if (a == b) return;
    if (comps[a].size() < comps[b].size()) swap(a, b);
    par[b] = a;
    for (auto i : comps[b]) {
        comps[a].push_back(i);
    } 
}

bool isRoot(int v) {
    return getPar(v) == v;
}

struct Edge{
    int from, to, cost;
};

ll ans;

bool used[N];

Edge edges[N];
int topEdges;

void relax() {
    for (int i = 0; i < n; ++i) {
        used[i] = isRoot(i);
    }

    auto updComp = [&] (int comp, int add) {
        for (auto val : comps[comp]) {
            upd(val, comp, add);
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!used[i]) continue;
        updComp(i, 0);
    }

    topEdges = 0;

    for (int i = 0; i < n; ++i) {
        if (!used[i]) continue;
        updComp(i, -1);
        Edge best = {0, 0, INT_MAX};
        for (auto val : comps[i]) {
            auto fans = get(val);
            Edge cur = {i, fans.second, fans.first};
            if (cur.cost < best.cost) {
                best = cur;
            }
        }
        edges[topEdges++] = best;
        updComp(i, 1);
    }

    for (int i = 0; i < topEdges; ++i) {
        if (!connect(edges[i].from, edges[i].to)) {
            uni(edges[i].from, edges[i].to);
            ans += edges[i].cost;
            --cntComps;
        }
    }
}

void solve() {
    cntComps = n;
    iota(par, par + n, 0);
    for (int i = 0; i < n; ++i) {
        comps[i] = {a[i]};
        upd(a[i], i, 1);
    }
    ans = 0;
    while (cntComps > 1) {
        relax();
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    n = unique(a, a + n) - a;
    solve();
    cout << ans << '\n';
    return 0;
}