#include <bits/stdc++.h>
// #include <atcoder/all>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
const double PI = acos(-1);
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
/*-------------------------------------------*/

int n, m;
vector<pair<int, int>> G[200];

int c[200]{};

void dfs(int v, int co) {
    c[v] = co;
    for(auto [to, type] : G[v]) {
        if(co == c[to]) {
            cout << "No"
                 << "\n";
            exit(0);
        }
        if(!c[to]) dfs(to, -co);
    }
}

int used[200], mn[200], mx[200];

void dfs2(int v) {
    used[v] = 1;
    for(auto [to, type] : G[v]) {
        chmin(mx[to], mx[v] + (type == -1 ? -1 : 1));
        chmax(mn[to], mn[v] + (type == 1 ? 1 : -1));
        if(!used[to]) dfs2(to);
        chmin(mx[v], mx[to] + (type == 1 ? -1 : 1));
        chmax(mn[v], mn[to] + (type == -1 ? 1 : -1));
    }
}

void dfs3(int v) {
    used[v] = 1;
    for(auto [to, type] : G[v]) {
        chmin(mx[to], mx[v] + (type == -1 ? -1 : 1));
        if(!used[to]) dfs3(to);
        chmin(mx[v], mx[to] + (type == 1 ? -1 : 1));
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, -c);
    }

    dfs(0, 1);

    fill(ALL(mx), 1 << 30);
    fill(ALL(mn), -(1 << 30));
    mn[0] = mx[0] = 0;

    rep(i, n) {
        memset(used, 0, sizeof(used));
        dfs2(0);
    }

    rep(i, n) if(mx[i] < mn[i]) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes\n";

    int ans = 0;
    vector<int> v(n);
    rep(i, n) {
        memset(used, 0, sizeof(used));
        fill(mx, mx + 200, 1 << 30);
        mx[i] = 0;
        rep(j, n) {
            memset(used, 0, sizeof(used));
            dfs3(i);
        }
        bool flag = false;
        rep(j, n) {
            if(chmax(ans, mx[j])) flag = true;
        }
        if(flag) rep(j, n) v[j] = mx[j];
    }

    cout << ans << endl;
    rep(i, n) cout << v[i] << " \n"[i + 1 == n];

    return 0;
}