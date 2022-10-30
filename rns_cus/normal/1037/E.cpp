#include <bits/stdc++.h>
using namespace std;

#define N 200020
#define x first
#define y second

typedef pair <int, int> pii;

int n, m, k, deg[N], ans[N], u[N], v[N];
set <int> adj[N];

priority_queue <pii> pq;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d", &u[i], &v[i]);
        adj[u[i]].insert(v[i]);
        adj[v[i]].insert(u[i]);
    }
    for (int i = 1; i <= n; i ++) {
        deg[i] = adj[i].size();
        pq.push(pii(-deg[i], i));
    }
    for (int i = m; i; i --) {
        while (!pq.empty()) {
            pii p = pq.top();
            if (p.x != -deg[p.y]) {
                pq.pop();
                continue;
            }
            if (p.x <= -k) break;
            pq.pop(); n --;
            for (int t : adj[p.y]) {
                deg[t] --, adj[t].erase(p.y);
                pq.push(pii(-deg[t], t));
            }
            adj[p.y].clear();
        }
        ans[i] = n;
        if (adj[u[i]].find(v[i]) != adj[u[i]].end()) {
            deg[u[i]] --, deg[v[i]] --;
            adj[u[i]].erase(v[i]), adj[v[i]].erase(u[i]);
            pq.push(pii(-deg[u[i]], u[i]));
            pq.push(pii(-deg[v[i]], v[i]));
        }
    }
    for (int i = 1; i <= m; i ++) printf("%d\n", ans[i]);
}