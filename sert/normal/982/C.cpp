//made by Sert
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 34;
const int N = (int)1e6 + 34;
vector<int> es[N];

int ans;
int dfs(int v, int pr) {
    int res = 1;
    for (int w: es[v]) {
        if (w == pr) continue;
        res += dfs(w, v);
    }
    if (res % 2 == 0) ans++;
    return res;
}

void solve() {
    int n, v1, v2;
    cin >> n;
    for (int i = 0; i < n; i++) es[i].clear();
    for (int i = 1; i < n; i++) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }
    if (n & 1) {
        cout << "-1\n";
        return;
    }
    ans = 0;
    dfs(0, -1);
    cout << ans - 1 << "\n";
}

int main() {
#ifdef SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    solve();
    solve();
#endif
    solve();
    return 0;
}