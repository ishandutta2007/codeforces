#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;
const ll INF = (ll)1e18;

struct edge {
    int to, cost;
};

int n;
int sub[N];
vector<edge> G[N];
ll dp[N];
ll ans_g, ans_b = 0;

void dfs(int v, int p) {
    sub[v] = 1;
    for(auto e : G[v]) {
        if(e.to == p) continue;
        dfs(e.to, v);
        sub[v] += sub[e.to];
        ans_b += 1LL * min(sub[e.to], (n - sub[e.to])) * e.cost;

    }
}

void calc(int v, int p) {
    dp[v] = 0;
    for(auto e : G[v]) {
        if(e.to == p) continue;
        calc(e.to, v);
        dp[v] += dp[e.to];
        if(sub[e.to] % 2 == 1) {
            dp[v] += e.cost;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        ans_g = ans_b = 0;
        cin >> n;
        n *= 2;
        for(int i = 0; i < n; i++) G[i].clear();
        for(int i = 0; i < n - 1; i++) {
            int a, b, c; cin >> a >> b >> c;
            a--, b--;
            G[a].push_back({b, c});
            G[b].push_back({a, c});
        }
        dfs(0, -1);
        calc(0, -1);
        cout << dp[0] << " " << ans_b << endl;
    }
}