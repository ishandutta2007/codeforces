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


const int INF = (is_same<int, ll>::value ? 1e18l + 666 : 1e9 + 666);
const ll INFll = 1e18 + 666;
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

inline constexpr int bpow(ll a, ll b, int mod) {
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

void run();

signed main() {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

void run() {
    int n, m;
    cin >> n >> m;
    vector<string> fld(n);
    for (auto& x : fld) {
        cin >> x;
    }
    vector<vector<int>> g(n * m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (fld[i][j] == '.') continue;
            vector<int> neighbors;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (abs(di) + abs(dj) != 1) continue;
                    if (fld[i + di][j + dj] == '.') {
                        neighbors.pb((i + di) * m + j + dj);
                    }
                }
            }
            if (len(neighbors) & 1) {
                cout << "NO\n";
                return;
            }
            for (int i = 0; i < len(neighbors); i += 2) {
                int u = neighbors[i], v = neighbors[i + 1];
                g[u].pb(v);
                g[v].pb(u);
            }
        }
    }

    vector<int> color(n * m, -1);
    function<bool(int, int)> paint = [&](int v, int c) {
        color[v] = c;
        for (auto& x : g[v]) {
            if (color[x] == -1) {
                if (!paint(x, c ^ 1)) {
                    return false;
                }
            } else if (color[x] != (c ^ 1)) {
                return false;
            }
        }
        return true;
    };

    int c = 0;
    for (int i = 0; i < n * m; ++i) {
        if (fld[i / m][i % m] == '.' && color[i] == -1 && !paint(i, c++ << 1)) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (fld[i][j] == 'X') {
                int cnt = 0;
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        if (abs(di) + abs(dj) != 1) continue;
                        cnt += (fld[i + di][j + dj] == '.');
                    }
                }
                cout << (cnt >> 1) * 5 << ' ';
            } else {
                cout << 1 + (color[i * m + j] & 1) * 3 << ' ';
            }
        }
        cout << endl;
    }
}