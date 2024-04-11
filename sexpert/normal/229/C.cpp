#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;
ll deg[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    ll ans = (ll)n*(n - 1)*(n - 2)/6;
    ll bad = 0;
    for(int u = 1; u <= n; u++)
        bad += deg[u] * (n - 1 - deg[u]);
    bad /= 2;
    cout << ans - bad << '\n';
}