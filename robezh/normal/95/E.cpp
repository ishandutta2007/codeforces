#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50, INF = (int)1e9;

int n, m;
bool vis[N];
vector<int> a;
int dp[N];
vector<int> G[N];

int dfs(int v) {
    vis[v] = true;
    int res = 1;
    for(int nxt : G[v]) {
        if(!vis[nxt]) res += dfs(nxt);
    }
    return res;
}

bool is_lucky(int x) {
    while(x > 0) {
        if(x % 10 != 4 && x % 10 != 7) return false;
        x /= 10;
    }
    return true;
}

void put_in(int cost, int wei) {
    for(int j = n; j >= wei; j--) dp[j] = min(dp[j], dp[j - wei] + cost);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 0; i < n; i++) if(!vis[i]) a.push_back(dfs(i));
    sort(a.begin(), a.end());
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 0, r = 0; i < a.size(); i = r) {
        while(r < n && a[r] == a[i]) r++;
        int cnt = r - i;
        for(int k = 1; k <= cnt; k *= 2) {
            put_in(k, k * a[i]);
            cnt -= k;
        }
        if(cnt > 0) put_in(cnt, cnt * a[i]);
    }
    int res = INF;
    for(int i = 1; i <= n; i++) if(is_lucky(i)) res = min(res, dp[i]);
    cout << (res == INF ? -1 : res - 1) << endl;

}