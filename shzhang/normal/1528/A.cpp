#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

vector<int> graph[100005];
int depth[100005];
int parent[100005];

ll f[100005][2];
ll l[100005], r[100005];

ll diff(ll x, ll y)
{
    return max(x-y, y-x);
}

void dfs(int node, int prt)
{
    depth[node] = depth[prt] + 1;
    parent[node] = prt;
    f[node][0] = f[node][1] = 0;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == prt) continue;
        dfs(nxt, node);

        f[node][0] += max(diff(l[node], l[nxt]) + f[nxt][0],
                        diff(l[node], r[nxt]) + f[nxt][1]);
        f[node][1] += max(diff(r[node], l[nxt]) + f[nxt][0],
                        diff(r[node], r[nxt]) + f[nxt][1]);
    }
}

void inputtree(int siz, int root = 1)
{
    for (int i = 1; i < siz; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(root, 0);
}

int main()
{
    int t; scanf("%d", &t);
    for (int d = 1; d <= t; d++) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) graph[i].clear();
        for (int i = 1; i <= n; i++) {
            scanf("%lld%lld", l + i, r + i);
        }
        inputtree(n);
        printf("%lld\n", max(f[1][0], f[1][1]));
    }
    return 0;
}