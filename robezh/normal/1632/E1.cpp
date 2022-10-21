#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)3e5 + 50;
const int LOGN = 19;

struct RMQ {
    int n;
    int mm[N], st[LOGN][N];

    void build(int x[], int _n) {
        n = _n;
        mm[0]=-1;
        for(int i = 1; i <= n; i++) mm[i]= (i & (i-1)) == 0 ? mm[i-1] + 1 : mm[i-1];
        for(int i = 0; i < n; i++){
            st[0][i] = x[i];
        }
        for(int lg = 1; lg < LOGN; lg++){
            for(int j = 0; j + (1 << lg) - 1 < n; j++){
                st[lg][j] = max(st[lg-1][j], st[lg-1][j+(1<<(lg-1))]);
            }
        }
    }

    int rmq(int l, int r){
        int k = mm[r - l + 1];
        return max(st[k][l], st[k][r-(1<<k)+1]);
    }
} rmq;

int n;
vi G[N];
int dp[N], dep[N], pmax[N];
int m, val[N];

void dfs(int v, int p, int d) {
    dep[v] = d;
    dp[v] = 0;
    for (int nxt : G[v]) {
        if(nxt != p) {
            dfs(nxt, v, d + 1);
            dp[v] = max(dp[v], dp[nxt] + 1);
        }
    }
}

void record(int v, int p, int d) {
    int mx[2] = {0, 0};
    bool vis = false;
    for (int nxt : G[v]) {
        if(nxt == p) continue;
        int cv = dp[nxt] + 1;
        rep(j, 0, 2) if(cv > mx[j]) swap(cv, mx[j]);
    }
    val[d] = mx[1] - d;
    pmax[d] = mx[1] + d;
    if(d) pmax[d] = max(pmax[d], pmax[d - 1]);
    for (int nxt : G[v]) {
        if(nxt != p && !vis && dp[nxt] + 1 == dp[v]) {
            vis = true;
            record(nxt, v, d + 1);
        }
    }
}

bool check(int w, int res) {
    if(res >= m - 1) return true;
    if(w > res) return false;
    int x = m - 1 - (res - w);
    int curres = max(rmq.rmq((w + x + 1) / 2, x) + x + w, pmax[(w + x) / 2]);
    return curres <= res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) G[i].clear();
        rep(i, 0, n - 1) {
            int u, v; cin >> u >> v; u--, v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(0, -1, 0);
        record(0, -1, 0);
        m = dp[0] + 1;
        rmq.build(val, m);
        rep(i, 1, n + 1) {
            int l = -1, r = m - 1, mid;
            while(l + 1 < r) {
                mid = (l + r) / 2;
                if(check(i, mid)) r = mid;
                else l = mid;
            }
            cout << r << " ";
        }
        cout << '\n';
    }
}