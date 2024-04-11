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

int k;
V<int> g[maxn];
ll sum[maxn][5];
ll num[maxn][5];
ll nump[5], sumd[5];

void dfs(int v, int p) {
    num[v][0] = 1;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);

            rep(i, k) {
                rep(j, k) {
                    int u = (i + j + 1) % k;
                    nump[u] += num[v][i] * num[to][j];
                    sumd[u] += sum[v][i] * num[to][j] + sum[to][j] * num[v][i] +
                               num[v][i] * num[to][j];
                }
            }
            rep(j, k) {
                num[v][(j + 1) % k] += num[to][j];
                sum[v][(j + 1) % k] += sum[to][j] + num[to][j];
            }
        }
    }
}

int main() {
    int n;
    cin >> n >> k;
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0, -1);

    ll ans = 0;
    rep(i, k) {
        ll val = (sumd[i] + (k - i) % k * nump[i]) / k;
        ans += val;
        // debug(i, sumd[i], nump[i], val);
    }
    cout << ans << endl;

    return 0;
}