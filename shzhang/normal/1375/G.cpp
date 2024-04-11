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

vector<int> graph[200005];
int depth[200005];

int odd_cnt = 0;
int even_cnt = 0;

void dfs(int node, int prt)
{
    depth[node] = depth[prt] + 1;
    if (depth[node] % 2) {
        odd_cnt++;
    } else {
        even_cnt++;
    }
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == prt) continue;
        dfs(nxt, node);

        /* you can do other things here, such as tree DP */
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

int n;

int main()
{
    scanf("%d", &n);
    inputtree(n);
    printf("%d", min(odd_cnt, even_cnt) - 1);
    return 0;
}