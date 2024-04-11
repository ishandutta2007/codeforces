#include <bits/stdc++.h>
using namespace std;

#define N 100100

typedef long long ll;

int n, dep[N], pa[N];
vector <int> adj[N];
vector <int> cnt[100], vec;

ll a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%I64d", &a[i]);
        for (int j = 0; j < 60; j ++) if (a[i] >> j & 1) cnt[j].push_back(i);
    }
    for (int i = 0; i < 60; i ++) if (cnt[i].size() >= 2) {
        if (cnt[i].size() >= 3) return puts("3"), 0;
        int x = cnt[i][0], y = cnt[i][1];
        adj[x].push_back(y), adj[y].push_back(x); vec.push_back(x);
    }
    for (int i = 1; i <= n; i ++) sort(adj[i].begin(), adj[i].end()), adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    int ans = N;
    for (auto x : vec) {
        memset(dep, -1, sizeof dep);
        queue <int> q;
        q.push(x), dep[x] = pa[x] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto v : adj[u]) {
                if (v == pa[u]) continue;
                if (~dep[v]) {
                    ans = min(ans, dep[u] + dep[v] + 1);
                }
                else dep[v] = dep[u] + 1, pa[v] = u, q.push(v);
            }
        }
    }
    if (ans == N) ans = -1; printf("%d\n", ans);
}