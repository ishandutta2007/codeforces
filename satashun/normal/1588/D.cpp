//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

template <class T>
V<T> make_vec(size_t a) {
    return V<T>(a);
}

template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

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
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T>
void mkuni(vector<T>& v) {
    sort(ALL(v));
    v.erase(unique(ALL(v)), end(v));
}

template <class T>
vector<int> sort_by(const vector<T>& v) {
    vector<int> res(v.size());
    iota(res.begin(), res.end(), 0);
    sort(res.begin(), res.end(), [&](int i, int j) { return v[i] < v[j]; });
    return res;
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

template <class T>
void scan(vector<T>& v, T offset = T(0)) {
    for (auto& x : v) {
        cin >> x;
        x += offset;
    }
}

template <class T>
void print(T x, int suc = 1) {
    cout << x;
    if (suc == 1)
        cout << "\n";
    else if (suc == 2)
        cout << " ";
}

template <class T>
void print(const vector<T>& v, int suc = 1) {
    for (int i = 0; i < v.size(); ++i)
        print(v[i], i == int(v.size()) - 1 ? suc : 2);
}

struct prepare_io {
    prepare_io() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} prep_io;

int now;
int id[1010];
int dp[60][1 << 10], indeg[60][1 << 10];
pii pre[60][1 << 10];
bool valid[60][1 << 10];
V<int> pos[200][15];
V<pii> g[60][1 << 10];
V<char> cand;

void slv() {
    int n;
    cin >> n;
    V<string> s(n);

    rep(c, now) rep(j, n) pos[c][j].clear();

    rep(i, n) {
        cin >> s[i];
        rep(j, SZ(s[i])) { pos[id[s[i][j]]][i].pb(j); }
        pos[now - 1][i].pb(-1);
    }

    memset(dp, -1, sizeof(dp));
    memset(valid, 0, sizeof(valid));
    memset(indeg, 0, sizeof(indeg));
    rep(i, 60) rep(j, 1 << n) g[i][j].clear();

    rep(i, now) {
        rep(mask, 1 << n) {
            bool ok = 1;
            V<int> ps(n);
            rep(j, n) {
                int p = (mask >> j & 1);
                if (p >= SZ(pos[i][j])) {
                    ok = 0;
                    break;
                }
                ps[j] = pos[i][j][p];
            }
            valid[i][mask] = ok;
            if (!ok) continue;
            //  debug(i, mask, ps);
            rep(nx, now) {
                bool ok = 1;
                int nx_mask = 0;
                rep(j, n) {
                    int pt = 0;
                    while (pt < SZ(pos[nx][j]) && pos[nx][j][pt] <= ps[j]) {
                        pt++;
                    }
                    if (pt == SZ(pos[nx][j])) {
                        ok = 0;
                        break;
                    }
                    nx_mask |= pt << j;
                }
                if (ok) {
                    g[i][mask].eb(nx, nx_mask);
                    indeg[nx][nx_mask]++;
                    //   debug(i, mask, ps, nx, nx_mask);
                }
            }
        }
    }
    dp[now - 1][0] = 0;
    queue<pii> que;
    rep(i, now) rep(j, 1 << n) {
        if (valid[i][j] && indeg[i][j] == 0) {
            //    debug(i, j);
            que.emplace(i, j);
        }
    }
    while (!que.empty()) {
        pii p = que.front();
        que.pop();
        auto [c, mask] = p;
        //  debug(c, mask);
        for (auto e : g[c][mask]) {
            //  debug(c, mask, e);
            if (dp[e.fi][e.se] < dp[c][mask] + 1) {
                dp[e.fi][e.se] = dp[c][mask] + 1;
                pre[e.fi][e.se] = p;
            }
            if (--indeg[e.fi][e.se] == 0) {
                que.emplace(e);
            }
        }
    }
    int mx = 0;
    rep(i, now) rep(j, 1 << n) chmax(mx, dp[i][j]);
    print(mx);
    string ans;
    int c, mask;
    rep(i, now) rep(j, 1 << n) if (dp[i][j] == mx) { c = i, mask = j; }
    rep(i, mx) {
        ans.pb(cand[c]);
        auto [nc, nx_mask] = pre[c][mask];
        c = nc, mask = nx_mask;
    }
    reverse(ALL(ans));
    print(ans);
}

int main() {
    for (char a = 'a'; a <= 'z'; ++a) {
        cand.pb(a);
        id[a] = now++;
    }
    for (char a = 'A'; a <= 'Z'; ++a) {
        cand.pb(a);
        id[a] = now++;
    }
    now++;

    int tc;
    cin >> tc;
    while (tc--) {
        slv();
    }
    return 0;
}