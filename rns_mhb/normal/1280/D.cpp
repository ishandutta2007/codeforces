#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, ll> pil;

#define N 3010

vector <int> adj[N];

pil dp[N][N], tmp[N];
int v[N], sz[N];

void merge(int x, int y) {
    for(int i = 0; i < sz[x] + sz[y]; i ++) tmp[i] = pil(-1, 0);
    for(int i = 0; i < sz[x]; i ++) for(int j = 0; j < sz[y]; j ++) {
        tmp[i+j] = max(tmp[i+j], pil(dp[x][i].first+dp[y][j].first, dp[x][i].second+dp[y][j].second));
        tmp[i+j+1] = max(tmp[i+j+1], pil(dp[x][i].first+dp[y][j].first+(dp[y][j].second>0), dp[x][i].second));
    }
    sz[x] += sz[y];
    for(int i = 0; i < sz[x]; i ++) dp[x][i] = tmp[i];
}

void dfs(int x, int p) {
    sz[x] = 1;
    dp[x][0] = pil(0, v[x]);
    for(int i = 0; i < adj[x].size(); i ++) {
        int y = adj[x][i];
        if(y == p) continue;
        dfs(y, x);
        merge(x, y);
    }
}

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) v[i] = 0, adj[i].clear();
    for(int i = 1, x; i <= n; i ++) {
        scanf("%d", &x);
        v[i] -= x;
    }
    for(int i = 1, x; i <= n; i ++) {
        scanf("%d", &x);
        v[i] += x;
    }
    for(int i = 1, x, y; i < n; i ++) {
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    cout << dp[1][m-1].first + (dp[1][m-1].second>0) << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t --) solve();
}