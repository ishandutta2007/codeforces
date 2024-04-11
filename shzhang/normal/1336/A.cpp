#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>

using namespace std;

#define ll long long

int n, k;

vector<int> graph[200005];
int prt[200005]; int childcnt[200005];
int depth[200005]; int weight[200005];

priority_queue<pair<int, int> > pq;

void dfs(int node, int parent)
{
    prt[node] = parent; weight[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == parent) continue;
        childcnt[node]++; depth[nxt] = depth[node] + 1;
        dfs(nxt, node); weight[node] += weight[nxt];
    }
    if (!childcnt[node]) pq.push(make_pair(depth[node] - weight[node] + 1, node));
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v); graph[v].push_back(u);
    }
    dfs(1, 0);
    ll ans = 0;
    for (int i = 1; i <= k; i++) {
        pair<int, int> pr = pq.top(); pq.pop();
        ans += (ll)pr.first;
        childcnt[prt[pr.second]]--;
        if (!childcnt[prt[pr.second]]) {
            pq.push(make_pair(depth[prt[pr.second]] - weight[prt[pr.second]] + 1, prt[pr.second]));
        }
    }
    printf("%lld", ans);
    return 0;
}