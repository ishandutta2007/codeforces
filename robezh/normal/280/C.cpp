#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

int n;
vector<int> G[N];
double res = 0;

void dfs(int v, int d, int p) {
    res += 1.0 / d;
    for(int nxt : G[v]) if(nxt != p) dfs(nxt, d + 1, v);
}

int main() {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, 1, -1);
    cout << fixed << setprecision(10) << res << endl;

}