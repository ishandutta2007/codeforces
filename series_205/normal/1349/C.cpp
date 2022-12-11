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

const int dx[]{0, 1, 0, -1};
const int dy[]{1, 0, -1, 0};

int n, m, t;

inline bool in(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }

bool c[1009][1009];
ll d[1009][1009];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> t;

    rep(i, n) rep(j, m) {
        char ch;
        cin >> ch;
        c[i][j] = ch - '0';
    }

    memset(d, -1, sizeof(d));

    deque<pair<int, int>> que;

    rep(i, n) rep(j, m) {
        rep(k, 4) {
            int xx = i + dx[k];
            int yy = j + dy[k];
            if(in(xx, yy) && c[i][j] == c[xx][yy]) {
                d[i][j] = 0;
                que.emplace_back(i, j);
                break;
            }
        }
    }

    while(!que.empty()) {
        auto [x, y] = que.front();
        que.pop_front();
        rep(k, 4) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if(in(xx, yy) && !~d[xx][yy]) {
                int dist = d[x][y];
                if(c[x][y] != c[xx][yy]) {
                    dist++;
                    que.emplace_back(xx, yy);
                } else
                    que.emplace_front(xx, yy);
                d[xx][yy] = dist;
            }
        }
    }

    rep(i, n) rep(j, m) if(!~d[i][j]) d[i][j] = inf;

    while(t--) {
        ll a, b, p;
        cin >> a >> b >> p;
        a--;
        b--;
        if(d[a][b] >= p)
            cout << c[a][b] << "\n";
        else
            cout << (c[a][b] ^ (p + d[a][b] & 1)) << "\n";
    }

    return 0;
}