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

int n, m;

set<int> g[N];

int ans;

int get(int v) {
    if (g[v].empty() || *(--g[v].end()) < v) {
        return 1;
    } else {
        return 0;
    }
}

void addEdge(int u, int v) {
    ans -= get(u);
    ans -= get(v);
    g[u].insert(v);
    g[v].insert(u);
    ans += get(u);
    ans += get(v);
}

void delEdge(int u, int v) {
    ans -= get(u);
    ans -= get(v);
    g[u].erase(v);
    g[v].erase(u);
    ans += get(u);
    ans += get(v);   
}


signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> m;
    ans = n;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        addEdge(u, v);
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            addEdge(u, v);
        } else if (t == 2) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            delEdge(u, v);
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}