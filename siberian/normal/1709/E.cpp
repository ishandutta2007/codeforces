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
int n;
int a[N];
vector<int> g[N];
int sz[N];

unordered_set<int> subtree[N];

void dfsSz(int v, int p) {
    sz[v] = 1;
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        dfsSz(to, v);
        sz[v] += sz[to];
    }
}

int ans = 0;
int pathVal[N];

void dfsSolve(int v) {
    pathVal[v] ^= a[v];
    // cerr << "v = " << v << " pathVal[v] = " << pathVal[v] << endl; 
    for (auto to : g[v]) {
        pathVal[to] = pathVal[v];
        dfsSolve(to);    
    }
    if (g[v].empty()) {
        subtree[v].insert(pathVal[v]);
        return;
    }
    bool first = true;
    bool clear = false;
    for (auto to : g[v]) {
        if (clear) {
            break;
        }
        if (first) {
            first = false;
            subtree[v].swap(subtree[to]);
            if (subtree[v].count(pathVal[v] ^ a[v])) {
                clear = true;
                break;
            }
            subtree[v].insert(pathVal[v]);
        } else {
            for (auto val : subtree[to]) {
                if (subtree[v].count(val ^ a[v])) {
                    clear = true;
                    break;
                }
            }
            if (clear) {
                break;
            }
            for (auto val : subtree[to]) {
                subtree[v].insert(val);
            }
        }
    }
    // cerr << "v = " << v << " clear = " << clear << " subtree = " << endl;
    // for (auto i : subtree[v]) {
    //     cerr << i << " ";
    // }
    // cerr << endl;
    if (clear) {
        subtree[v].clear();
        ++ans;
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfsSz(0, -1);
    for (int i = 1; i < n; ++i) {
        sort(all(g[i]), [&] (int lhs, int rhs) -> bool {
            return sz[lhs] < sz[rhs];
        });
        g[i].pop_back();
        reverse(all(g[i]));
    }
    pathVal[0] = 0;
    dfsSolve(0);
    cout << ans << endl;
    return 0;
}