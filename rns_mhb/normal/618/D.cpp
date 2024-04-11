#include <bits/stdc++.h>
using namespace std;

#define N 200005

int n, x, y, u, v, ans;

vector<int> adj[N];

int dfs(int v, int p = -1) {
	int s = 0;
	for (auto u : adj[v]) if (u != p) s += dfs(u,v);
	if (!s) return 1;
	else if (s == 1) return ans ++, 1;
	return ans += 2, 0;
}

int main() {
    scanf("%d %d %d", &n, &x, &y);
    for (int i = 0; i < n - 1; i ++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (x >= y) {
        int typ;
        for (typ = 1; typ <= n;) {
            if (adj[typ].size() == n - 1) break;
            else typ ++;
        }
        if (typ != n + 1) printf("%I64d", 1ll * y * (n - 2) + x);
        else printf("%I64d", 1ll * y * (n - 1));
    }
    else {
        dfs(1);
        printf("%I64d", 1ll * x * ans + 1ll * y * (n - 1 - ans));
    }
}