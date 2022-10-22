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

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

const int MX = 1010;

int n, m;
string s[MX];

bool vis[MX][MX];

void dfs(int r, int c) {
    vis[r][c] = true;
    rep(dir, 4) {
        int nr = r + dx[dir], nc = c + dy[dir];
        if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] &&
            s[nr][nc] == '#') {
            dfs(nr, nc);
        }
    }
}

void ng() {
    puts("-1");
    exit(0);
}

bool ei[MX], ej[MX];

int main() {
    cin >> n >> m;
    rep(i, n) cin >> s[i];

    rep(i, n) {
        int mx = MX, Mx = -1;
        int cnt = 0;
        rep(j, m) {
            if (s[i][j] == '#') {
                chmin(mx, j);
                chmax(Mx, j);
                cnt++;
            }
        }
        if (mx != MX) {
            ei[i] = true;
        }
        if (mx != MX && cnt != Mx - mx + 1) {
            ng();
        }
    }

    rep(j, m) {
        int mx = MX, Mx = -1;
        int cnt = 0;
        rep(i, n) {
            if (s[i][j] == '#') {
                chmin(mx, i);
                chmax(Mx, i);
                cnt++;
            }
        }
        if (mx != MX) {
            ej[j] = true;
        }
        if (mx != MX && cnt != Mx - mx + 1) {
            ng();
        }
    }

    rep(i, n) if (!ei[i]) {
        bool ok = 0;
        rep(j, m) {
            if (!ej[j]) {
                ok = 1;
            }
        }
        if (!ok) {
            ng();
        }
    }

    rep(j, m) if (!ej[j]) {
        bool ok = 0;
        rep(i, n) {
            if (!ei[i]) {
                ok = 1;
            }
        }
        if (!ok) {
            ng();
        }
    }

    int ans = 0;

    rep(i, n) {
        rep(j, m) {
            if (s[i][j] == '#' && !vis[i][j]) {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}