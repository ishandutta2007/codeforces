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

int n;
vector<int> graph[200005];
int a[200005], b[200005], c[200005];
int c01[200005], c10[200005];

ll ans = 0;

void dfs(int node, int prt)
{
    a[node] = min(a[node], a[prt]);
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == prt) continue;
        dfs(nxt, node);
        c01[node] += c01[nxt];
        c10[node] += c10[nxt];
    }
    if (b[node] != c[node]) {
        if (b[node] == 1) c10[node]++;
        else c01[node]++;
    }
    int minv = min(c01[node], c10[node]);
    ans += (ll)minv * (ll)a[node] * 2LL;
    c01[node] -= minv; c10[node] -= minv;
}

int main()
{
    a[0] = 1000000000;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", a + i, b + i, c + i);
    }
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v); graph[v].push_back(u);
    }
    dfs(1, 0);
    if (c01[1] || c10[1]) {
        printf("-1");
    } else {
        printf("%lld", ans);
    }
    return 0;
}