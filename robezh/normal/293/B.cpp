#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 50, mod = (int)1e9 + 7;


int n, m, k;
int mp[N][N], path[N][N];
ll C[N][N];
ll fac[N];
int to[N];
int at[N][N];
int used[N];
int cts[(1 << 20)];
ll res = 0;
int vis[N], ccolor = 0;

void dfs(int x, int y, int cntc) {
    if(y > m) y -= m, x += 1;
    if(x == n + 1) {
//        rep(i, 1, n + 1) {
//            rep(j, 1, m + 1) cout << at[i][j] << " ";
//            cout << endl;
//        }
        res = (res + C[k - ccolor][cntc - ccolor] * fac[cntc - ccolor]) % mod;
        return ;
    }
    int cur = path[x][y - 1] | path[x - 1][y];
    if(mp[x][y] && to[mp[x][y]] != -1) {
        if(cur >> to[mp[x][y]] & 1) return ;
        path[x][y] = cur | (1 << to[mp[x][y]]);
        at[x][y] = to[mp[x][y]];
        dfs(x, y + 1, cntc);
    } else {
        bool use_new = cts[cur] + abs(n - x) + abs(m - y) < k;
        for(int i = 1; i <= min(k, cntc + 1); i++) {
            if(mp[x][y] && used[i]) continue;
            if(!(cur >> i & 1)) {
                if(mp[x][y]) to[mp[x][y]] = i, used[i] = 1;
                path[x][y] = cur | (1 << i);
                at[x][y] = i;
                dfs(x, y + 1, max(cntc, i));
                if(mp[x][y]) to[mp[x][y]] = -1, used[i] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    if(n + m - 1 > k) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < (1 << 12); i++) {
        rep(j, 0, 12) cts[i] += (i >> j & 1);
    }
    rep(i, 0, N) C[i][0] = 1;
    rep(i, 1, N) {
        rep(j, 1, i + 1) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
    fac[0] = 1;
    rep(i, 1, N) fac[i] = fac[i - 1] * i % mod;
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) cin >> mp[i][j], vis[mp[i][j]] = 1;
    }
    rep(i, 1, k + 1) ccolor += vis[i];
    memset(to, -1, sizeof(to));
    dfs(1, 1, 0);
    cout << res << '\n';


}