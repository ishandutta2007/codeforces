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
const double PI = acos(-1);
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

void no() {
    cout << "NO" << endl;
    exit(0);
}

using P = pair<int, int>;

int n, m, a[3];
vector<int> G[5009];

int color[5009];
P dfs(int v, int c) {
    color[v] = c;
    P res(0, 0);
    (c == 1 ? res.first : res.second) = 1;
    for(const int &u : G[v]) {
        if(color[u] == c) no();
        if(!color[u]) {
            auto [x, y] = dfs(u, -c);
            res.first += x;
            res.second += y;
        }
    }
    return res;
}

int ans[5009];

bool used[5009];
void dfs2(int v, int c) {
    used[v] = true;
    if(color[v] * c == 1) ans[v] = 2;
    for(const int &u : G[v])
        if(!used[u]) dfs2(u, c);
}

vector<pair<P, int>> vp;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    rep(i, 3) cin >> a[i];
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    rep(i, n) if(!color[i]) vp.emplace_back(dfs(i, 1), i);

    V<bitset<5009>> b(vp.size() + 1);
    b[0][0] = 1;

    rep(i, vp.size()) b[i + 1] =
        b[i] << vp[i].first.second | b[i] << vp[i].first.first;

    if(!b[vp.size()][a[1]]) no();

    cout << "YES" << endl;

    int c2 = a[1];
    int x = vp.size();
    while(x--) {
        if(c2 >= vp[x].first.first && b[x][c2 - vp[x].first.first]) {
            dfs2(vp[x].second, 1);
            c2 -= vp[x].first.first;
        } else {
            dfs2(vp[x].second, -1);
            c2 -= vp[x].first.second;
        }
    }

    int c1 = a[0];
    rep(i, n) {
        if(ans[i] == 0) {
            if(c1 > 0) {
                ans[i] = 1;
                c1--;
            } else
                ans[i] = 3;
        }
        cout << ans[i];
    }
    cout << endl;

    return 0;
}