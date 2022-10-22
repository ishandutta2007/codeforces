#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

const int maxn = 200010;

V<pii> g[maxn];
int indeg[maxn][10][10];
bool ng[10][10][10][10];

void dfs(int p, V<int>& c) {}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        g[a].eb(c, b);
    }

    rep(i, n) {
        sort(ALL(g[i]));
        int sz = g[i].size();
        rep(j, sz) {
            int to = g[i][j].se;
            indeg[to][sz][j + 1]++;
        }
    }

    rep(i, n) {
        int sz = g[i].size();
        rep(j, sz) {
            int to = g[i][j].se;
            indeg[to][sz][j + 1]--;
            rep(p, 10) {
                rep(q, 10) {
                    if (indeg[to][p][q] > 0) {
                        ng[sz][j + 1][p][q] = ng[p][q][sz][j + 1] = 1;
                    }
                }
            }
            indeg[to][sz][j + 1]++;
        }
    }

    int ans = 0;
    V<int> c(k + 1, -1);
    auto dfs = [&](auto&& self, int i) -> void {
        if (i == k + 1) {
            ans++;
            return;
        }

        for (int j = 1; j <= i; ++j) {
            c[i] = j;
            bool ok = 1;
            for (int p = 1; p <= i; ++p) {
                if (ng[i][j][p][c[p]]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                self(self, i + 1);
            }
        }
    };

    dfs(dfs, 1);

    cout << ans << endl;

    return 0;
}