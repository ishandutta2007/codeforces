#include <bits/stdc++.h>
using namespace std;
#define N 100100
typedef pair<int, int> pii;
#define inf 1e18

int n, m, p[N];
long long d[N];
vector <pii> adj[N];
priority_queue <int> q;

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i ++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(pii(v, w));
        adj[v].push_back(pii(u, w));
    }
    for (int i = 1; i <= n; i ++) d[i] = inf;
    d[1] = 0, q.push(1);
    while (!q.empty()) {
        int u = q.top(), v, i, len;
        len = adj[u].size(), q.pop();
        for (i = 0; i < len; i ++) {
            v = adj[u][i].first;
            if (d[v] > d[u] + adj[u][i].second)
                d[v] = d[u] + adj[u][i].second, p[v] = u, q.push(v);
        }
    }
    if (d[n] < inf) {
        stack <int> v = stack <int> ();
        int i = n; while (i = p[i]) v.push(i);
        while (!v.empty()) printf("%d ", v.top()), v.pop();
        printf("%d\n", n);
    }
    else puts("-1");
    return 0;
}