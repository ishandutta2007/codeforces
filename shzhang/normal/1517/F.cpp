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

#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int n;

vector<int> graph[305];
int depth[305];
int parent[305];
vector<int> tree[305];

void dfs(int node, int prt)
{
    depth[node] = depth[prt] + 1;
    parent[node] = prt;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == prt) continue;
        tree[node].push_back(nxt);
        dfs(nxt, node);
    }
}

int f[305][305]; // any configuration
int g[305][305]; // configuration where g is NOT a min or d = 0

#define get(arr, x, y) ((y) < 0 || (y) > bound ? 0 : arr[x][y])

void dp(int node, int bound)
{
    for (int i = 0; i < tree[node].size(); i++) {
        int child = tree[node][i];
        dp(child, bound);
    }
    for (int d = 0; d <= bound; d++) {
        int val = 1; int val2 = 1;
        for (int i = 0; i < tree[node].size(); i++) {
            int child = tree[node][i];
            val = mul(val, (get(g, child, d - 1) + get(g, child, d)) % MOD + get(f, child, d + 1));
            val2 = mul(val2, get(g, child, d) + get(f, child, d + 1));
        }
        f[node][d] = val;
        if (d == 0) {
            g[node][d] = val;
        } else {
            g[node][d] = (val - val2 + MOD) % MOD;
        }
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

int ways[305];

int main()
{
    scanf("%d", &n);
    inputtree(n);
    for (int i = 0; i <= n; i++) {
        dp(1, i);
        for (int j = 0; j <= i; j++) {
            ways[i] += g[1][j];
            if (ways[i] >= MOD) ways[i] -= MOD;
        }
        //printf("%d ", ways[i]);
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int x = (ways[i] - (i ? ways[i-1] : 0) + MOD) % MOD;
        int y = (i - 1 + MOD) % MOD;
        ans += mul(x, y);
        if (ans >= MOD) ans -= MOD;
    }
    ans += n;
    if (ans >= MOD) ans -= MOD;
    int inv2 = 499122177;
    for (int i = 1; i <= n; i++) {
        ans = mul(ans, inv2);
    }
    printf("%d", ans);
    return 0;
}