#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<pair<int, int>>> graph;
vector<int> parent, etp, leafOrder;

void dfs(int v, int p, int epar) {
    if (etp[v] != -2) return;
    etp[v] = epar;
    parent[v] = p;
    for (auto [c, eid] : graph[v]) {
        dfs(c, v, eid);
    }
    leafOrder.push_back(v);
}

int main() {
    int n, m; ll x; scanf("%d %d %lld", &n, &m, &x);
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    graph.assign(n, vector<pair<int, int>>());
    for (int i = 0; i < m; ++i) {
        int a, b; scanf("%d %d", &a, &b); --a; --b;
        graph[a].emplace_back(b, i);
        graph[b].emplace_back(a, i);
    }
    ll total = 0;
    for (ll v : a) total += v;
    if (total < (n - 1) * x) {
        printf("NO\n");
        return 0;
    }
    parent.assign(n, -2);
    etp.assign(n, -2);
    dfs(0, -1, -1);
    vector<int> ansBack, ansFront;
    for (int v : leafOrder) {
        if (v == 0) continue;
        if (a[v] >= x) {
            ansFront.push_back(etp[v]);
            a[parent[v]] += a[v] - x;
        } else {
            ansBack.push_back(etp[v]);
        }
    }
    reverse(begin(ansBack), end(ansBack));
    ansFront.insert(end(ansFront), begin(ansBack), end(ansBack));
    printf("YES\n");
    for (int v : ansFront) printf("%d\n", v + 1);
    return 0;
}