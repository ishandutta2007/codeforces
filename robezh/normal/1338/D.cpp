#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define what(x) cerr << #x << " is " << x << endl;

const int N = (int)1e5 + 50;

int n;
set<int> G[N];
int val[2][N];
int dp[N][2];
int res = 0;

void dfs(int v, int p = -1) {
    dp[v][0] = val[0][v];
    dp[v][1] = val[1][v];
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        dfs(nxt, v);
        dp[v][0] = max(dp[v][0], val[0][v] + max(dp[nxt][1], dp[nxt][0]));
        dp[v][1] = max(dp[v][1], val[1][v] + dp[nxt][0]);
    }
}

void reroot(int v, int p = -1, int up0 = 0, int up1 = 0) {
    vi mx = {up0, 0};
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        int cur = dp[nxt][0];
        for(int j = 0; j < 2; j++) if(cur > mx[j]) swap(cur, mx[j]);
    }

    res = max(res, val[1][v] + mx[0] + mx[1]);

    vi mx2 = {max(up0, up1), 0};
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        int cur = max(dp[nxt][0], dp[nxt][1]);
        for(int j = 0; j < 2; j++) if(cur > mx2[j]) swap(cur, mx2[j]);
    }
    res = max(res, val[0][v] + mx2[0] + mx2[1]);

    for(int nxt : G[v]) {
        if(nxt == p) continue;
        int nxt0 = (max(dp[nxt][0], dp[nxt][1]) == mx2[0] ? mx2[1] : mx2[0]) + val[0][v];
        int nxt1 = (dp[nxt][0] == mx[0] ? mx[1] : mx[0]) + val[1][v];
        reroot(nxt, v, nxt0, nxt1);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].insert(b);
        G[b].insert(a);
    }
    for(int i = 0; i < n; i++) {
        val[1][i] = 1;
    }
    int root = 0;
    for(int i = 0; i < n; i++) {
        val[0][i] = max(0, (int)G[i].size() - 2);
    }

    dfs(root);
    reroot(root);
    cout << res << '\n';
}