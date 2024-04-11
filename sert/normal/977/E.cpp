#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = (ll)2e5 + 34;
const int INF = (int)1e9 + 34;

vector<int> es[N];
bool ok, u[N];

void dfs(int v) {
    if (u[v]) return;
    u[v] = true;
    if ((int)es[v].size() != 2) ok = false;
    for (int w: es[v]) dfs(w);
}

void solve() {
    int n, m, v1, v2;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v1, &v2);
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (u[i]) continue;
        ok = true;
        dfs(i);
        if (ok) ans++;
    }
    cout << ans;
}

int main() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    //solve();
    solve();
    return 0;
}