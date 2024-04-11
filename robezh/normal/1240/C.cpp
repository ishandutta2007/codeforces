#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)5e5 + 50;

struct edge{
    int to, cost;
};

int n, k;
ll dp0[N], dp1[N];
vector<edge> G[N];

void dfs(int v, int p) {
    ll sum = 0;
    vector<ll> dps;
    for(auto &e : G[v]) {
        if(e.to == p) continue;
        dfs(e.to, v);
        sum += dp1[e.to];
        dps.push_back(dp0[e.to] + e.cost - dp1[e.to]);
    }
    sort(dps.begin(), dps.end(), greater<>());
    dp0[v] = sum, dp1[v] = sum;
//    cout << v + 1 << ": ";
//    for(int x : dps) cout << x << " ";
//    cout << endl;
    for(int i = 0; i < min(k, (int)dps.size()); i++) {
        if(dps[i] <= 0) continue;
        dp1[v] += dps[i];
        if(i < k - 1) dp0[v] += dps[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) G[i].clear();
        for(int i = 0; i < n - 1; i++) {
            int a, b, c;
            cin >> a >> b >> c; a--, b--;
            G[a].push_back({b, c});
            G[b].push_back({a, c});
        }
        dfs(0, -1);
        cout << max(dp0[0], dp1[0]) << "\n";
    }
}