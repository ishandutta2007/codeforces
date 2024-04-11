#include <cstdio>
#include <vector>
#include <set>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>

using namespace std;

#define ll long long

struct Edge {
    int to, id;
};

int n;
vector<Edge> graph[100005];

ll length[100005];
ll mult[100005];
ll weight[100005];

double ans = 0.0;

void dfs(int node, int prt)
{
    weight[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        int child = graph[node][i].to;
        if (child == prt) continue;
        dfs(child, node); weight[node] += weight[child];
    }
    for (int i = 0; i < graph[node].size(); i++) {
        Edge e = graph[node][i];
        if (e.to == prt) continue;
        ll usiz = n - weight[e.to];
        ll dsiz = weight[e.to];
        mult[e.id] = ((usiz * (usiz - 1LL)) / 2LL) * dsiz + ((dsiz * (dsiz - 1LL)) / 2LL) * usiz;
        ans += ((double)mult[e.id] * (double)length[e.id]) / (double)(((ll)n * (ll)(n-1) * (ll)(n-2)) / 6LL);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d%lld", &u, &v, length + i);
        Edge e; e.to = v; e.id = i;
        graph[u].push_back(e); e.to = u;
        graph[v].push_back(e);
    }
    int q;
    dfs(1, 0);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int r, w;
        scanf("%d%d", &r, &w);
        ans -= ((double)mult[r] * (double)length[r]) / (double)(((ll)n * (ll)(n-1) * (ll)(n-2)) / 6LL);
        length[r] = w;
        ans += ((double)mult[r] * (double)length[r]) / (double)(((ll)n * (ll)(n-1) * (ll)(n-2)) / 6LL);
        printf("%.10f\n", ans * 2.0);
    }
    return 0;
}