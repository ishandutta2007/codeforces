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

#define LOG2_N 19

vector<int> graph[500005];
int depth[500005];
int parent[500005];
int ancestor[500005][LOG2_N];

int maxdep[500005];

int diameter = 0;

void dfs(int node, int prt)
{
    depth[node] = depth[prt] + 1;
    parent[node] = prt;
    maxdep[node] = depth[node];
    vector<int> maxdeps;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == prt) continue;
        dfs(nxt, node);

        /* you can do other things here, such as tree DP */
        maxdeps.push_back(maxdep[nxt]);
        maxdep[node] = max(maxdep[node], maxdep[nxt]);
    }
    maxdeps.push_back(depth[node]); maxdeps.push_back(depth[node]);
    sort(maxdeps.begin(), maxdeps.end());
    reverse(maxdeps.begin(), maxdeps.end());
    diameter = max(diameter, maxdeps[0] + maxdeps[1] - 2 * depth[node]);
}

int lca(int A, int B)
{
    if (depth[A] < depth[B]) swap(A, B);
    for (int i = 0; i < LOG2_N; i++) {
        if ((depth[A] - depth[B]) & (1 << i)) A = ancestor[A][i];
    }
    if (A == B) return A;
    for (int i = LOG2_N - 1; i >= 0; i--) {
        if (ancestor[A][i] != ancestor[B][i]) {
            A = ancestor[A][i];
            B = ancestor[B][i];
        }
    }
    return parent[A];
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
    for (int i = 1; i <= siz; i++) ancestor[i][0] = parent[i];
    for (int pwr = 1; pwr < LOG2_N; pwr++) {
        for (int i = 1; i <= siz; i++) {
            ancestor[i][pwr] = ancestor[ancestor[i][pwr-1]][pwr-1];
        }
    }
}

int n, a, b, da, db;

void work(void)
{
    diameter = 0;
    scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
    for (int i = 1; i <= n; i++) graph[i].clear();
    inputtree(n);
    //printf("%d ", diameter);
    if (db <= 2 * da || depth[a] + depth[b] - 2 * depth[lca(a, b)] <= da) {
        printf("Alice\n"); return;
    }
    if (diameter <= 2 * da) {
        printf("Alice\n");
    } else {
        printf("Bob\n");
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}