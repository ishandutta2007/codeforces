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

const int maxm = 10010;
const int maxg = 1010;
const ll INF = TEN(18);

ll ds[maxm][maxg];

int main() {
    int n, m;
    cin >> n >> m;
    V<int> d(m);
    rep(i, m) { cin >> d[i]; }
    sort(ALL(d));
    int g, r;
    cin >> g >> r;

    rep(i, maxm) rep(j, maxg) ds[i][j] = INF;
    ds[0][0] = 0;

    V<int> use;
    use.pb(0);
    ll cyc = 0;

    while (!use.empty()) {
        queue<pii> que;
        for (int v : use) {
            que.push(mp(v, 0));
        }
        V<int> nxt;

        while (!que.empty()) {
            pii p = que.front();
            que.pop();
            int id, tm;

            tie(id, tm) = p;
            ll cs = cyc * (g + r) + tm;

            if (tm == g) {
                nxt.pb(id);
            }

            if (id > 0) {
                int t = tm + (d[id] - d[id - 1]);
                if (t <= g && ds[id - 1][t] == INF) {
                    ds[id - 1][t] = cs + (d[id] - d[id - 1]);
                    que.push(mp(id - 1, t));
                }
            }
            if (id + 1 < m) {
                int t = tm + (d[id + 1] - d[id]);
                if (t <= g && ds[id + 1][t] == INF) {
                    ds[id + 1][t] = cs + (d[id + 1] - d[id]);
                    que.push(mp(id + 1, t));
                }
            }
        }
        cyc++;
        use = nxt;
    }

    ll ans = INF;
    rep(i, maxg) {
        if (ds[m - 1][i] != INF) {
            chmin(ans, ds[m - 1][i]);
        }
    }

    if (ans == INF) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}