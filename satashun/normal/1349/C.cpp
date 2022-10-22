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

const int di[4] = {0, 0, -1, 1};
const int dj[4] = {1, -1, 0, 0};

const int MX = 1010;
string s[MX];
int cmp[MX][MX];
int n, m;

void dfs(int r, int c, int k, int& sz) {
    cmp[r][c] = k;
    sz++;
    rep(dir, 4) {
        int nr = r + di[dir], nc = c + dj[dir];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && s[nr][nc] == s[r][c] &&
            cmp[nr][nc] == -1) {
            dfs(nr, nc, k, sz);
        }
    }
}

int d[MX][MX];
int sz[MX * MX];
const int INF = TEN(9);

int main() {
    cin.tie(0);
    int q;
    cin >> n >> m >> q;
    rep(i, n) { cin >> s[i]; }

    memset(cmp, -1, sizeof(cmp));
    int now = 0;

    rep(i, n) rep(j, m) {
        if (cmp[i][j] == -1) {
            int s = 0;
            dfs(i, j, now, s);
            sz[now] = s;
            now++;
        }
    }

    rep(i, n) rep(j, m) d[i][j] = INF;
    queue<pii> que;

    rep(i, n) {
        rep(j, m) {
            if (sz[cmp[i][j]] > 1) {
                que.push(mp(i, j));
                d[i][j] = 0;
            }
        }
    }

    while (!que.empty()) {
        pii p = que.front();
        que.pop();
        int r, c;
        tie(r, c) = p;
        rep(dir, 4) {
            int nr = r + di[dir], nc = c + dj[dir];
            if (nr >= 0 && nr < n & nc >= 0 && nc < m && d[nr][nc] == INF) {
                d[nr][nc] = d[r][c] + 1;
                que.push(mp(nr, nc));
            }
        }
    }

    rep(i, q) {
        int r, c;
        ll p;
        cin >> r >> c >> p;
        --r, --c;
        int b = s[r][c] - '0';
        bool f = b;

        if (d[r][c] != INF && d[r][c] <= p) {
            ll df = p - d[r][c];
            if (df & 1) {
                f ^= 1;
            }
        }
        cout << (f ? '1' : '0') << '\n';
    }
    return 0;
}