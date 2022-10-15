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

int ans[200005];

void dfs(int node, int prt)
{
    int nxtcolor = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        if (graph[node][i] == prt) continue;
        while (nxtcolor == ans[node] || nxtcolor == ans[prt]) nxtcolor++;
        ans[graph[node][i]] = nxtcolor; dfs(graph[node][i], node); nxtcolor++;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ans[1] = 1;
    dfs(1, 0);
    int k = 0;
    for (int i = 1; i <= n; i++) k = max(k, ans[i]);
    printf("%d\n", k);
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}