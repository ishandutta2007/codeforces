#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
template <typename T> using V = vector<T>;
constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    char c[1009][1009];
    cin >> h >> w;
    rep(i, h) cin >> c[i];

    int s[1009][1009]{};

    rep(i, h) {
        int b = 0;
        rep(j, w) if(c[i][j] == (b & 1 ? '.' : '#')) b++;
        if(b > 2) {
            cout << -1 << endl;
            return 0;
        }
        if(b != 0) rep(j, w) s[i][j] = (c[i][j] == '#' ? 1 : -1);
    }
    rep(j, w) {
        int b = 0;
        rep(i, h) if(c[i][j] == (b & 1 ? '.' : '#')) b++;
        if(b > 2) {
            cout << -1 << endl;
            return 0;
        }
        if(b != 0) rep(i, h) s[i][j] = (c[i][j] == '#' ? 1 : -1);
    }

    rep(i, h) {
        bool ok = false;
        rep(j, w) if(s[i][j] != -1) ok = true;
        if(!ok) {
            cout << -1 << endl;
            return 0;
        }
    }
    rep(j, w) {
        bool ok = false;
        rep(i, h) if(s[i][j] != -1) ok = true;
        if(!ok) {
            cout << -1 << endl;
            return 0;
        }
    }

    bool used[1009][1009]{};

    queue<pair<int, int>> que;
    int ans = 0;

    const int dx[]{0, 1, 0, -1};
    const int dy[]{1, 0, -1, 0};

    rep(i, h) rep(j, w) {
        if(!used[i][j] && c[i][j] == '#') {
            ans++;
            que.emplace(i, j);
            while(!que.empty()) {
                auto [x, y] = que.front();
                que.pop();
                rep(d, 4) {
                    int xx = x + dx[d];
                    int yy = y + dy[d];
                    if(xx < 0 || xx >= h || yy < 0 || yy >= w) continue;
                    if(used[xx][yy] || c[xx][yy] != '#') continue;
                    used[xx][yy] = true;
                    que.emplace(xx, yy);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}