#include "bits/stdc++.h"

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

const int INF = (is_same<int, ll>::value ? 3e18l + 666 : 1e9 + 666);
const ll INFll = 3e18l + 666;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

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
    a %= mod;
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = int(1ll * res * a % mod);
        }
        a *= a;
        a %= mod;
    }
    return res;
}

template<class T>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) {
        in >> x;
    }
    return in;
}

template<class T, class U>
istream& operator>>(istream& in, std::pair<T, U>& p) {
    return in >> p.first >> p.second;
}

template<class TLambda>
struct YPredicate {
    YPredicate(TLambda&& l) : l_(l) {}
 
    template<class... TArgs>
    auto operator()(TArgs&&... args) {
        return l_(*this, std::forward<TArgs>(args)...);
    }

private:
    TLambda l_;
};

void run();

// #define TASK "taskname"

signed main() {
#if defined(TASK) && !defined(LOCAL)
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

void run() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n);
    for (int i = 0; i < m; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        --t, --a, --b;
        g[a].pb({b, t});
        g[b].pb({a, t});
    }
    vector<char> part(n, -1);
    {
        auto dfs = YPredicate([&](auto dfs, int v, char cur = 0) -> bool {
            part[v] = cur;
            char other = cur ^ 1;
            for (auto [u, _] : g[v]) {
                if (part[u] == -1) {
                    if (!dfs(u, other)) {
                        return false;
                    }
                } else if (part[u] != other) {
                    return false;
                }
            }
            return true;
        });
        for (int i = 0; i < n; ++i) {
            if (part[i] == -1 && !dfs(i)) {
                cout << "NO\n";
                return;
            }
        }
    }
    vector<vector<int>> new_g(n);
    for (int v = 0; v < n; ++v) {
        for (auto [u, t] : g[v]) {
            if (part[v] ^ t) {
                new_g[v].pb(u);
            } else {
                new_g[u].pb(v);
            }
        }
    }
    vector<int> top_sort;
    vector<int> color(n, 0);
    auto dfs = YPredicate([&](auto dfs, int v) -> bool {
        ++color[v];
        for (auto u : new_g[v]) {
            if (color[u] == 1) {
                return false;
            }
            if (color[u] == 0 && !dfs(u)) {
                return false;
            }
        }
        ++color[v];
        top_sort.pb(v);
        return true;
    });
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0 && !dfs(i)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    vector<int> back_ind(n);
    for (int i = 0; i < n; ++i) {
        back_ind[top_sort[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cout << "LR"[(int)part[i]] << " " << back_ind[i] << "\n";
    }
}