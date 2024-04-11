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
vector<int> graph2[200005];
bool isA[200005];
bool isblack[200005];

int acnt[200005], bcnt[200005];

bool good = true;

set<int> blacks;

void dfs(int node, int prt, bool is_a)
{
    isA[node] = is_a;
    acnt[node] = (int)isA[node];
    isblack[node] = (bool)((graph[node].size() + (is_a ? 1 : 0)) % 2);
    bcnt[node] = (int)isblack[node];
    if (isblack[node]) blacks.insert(node);
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == prt) continue;
        dfs(nxt, node, !is_a);
        acnt[node] += acnt[nxt];
        bcnt[node] += bcnt[nxt];
    }
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == prt) continue;
        if (acnt[nxt] == bcnt[nxt] + 1) {
            graph2[node].push_back(nxt);
        } else if (acnt[nxt] == bcnt[nxt] - 1) {
            graph2[nxt].push_back(node);
        } else {
            good = false;
        }
    }

}

void dfs2(int node)
{
    if (!blacks.count(node)) {
        return;
    }
    int nxt = graph2[node].back();
    dfs2(nxt);
    blacks.erase(node);
    blacks.insert(nxt);
    printf("%d %d\n", node, nxt);
    graph2[node].pop_back();
}

void work()
{
    int n; scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0, true);
    if (!good || acnt[1] != bcnt[1]) {
        printf("NO\n");
    } else {
        printf("YES\n");
        while (!blacks.empty()) {
            int cur = *blacks.begin();
            if (graph2[cur].empty()) {
                blacks.erase(cur); continue;
            }
            dfs2(cur);
        }
    }
    for (int i = 1; i <= n; i++) graph[i].clear();
    for (int i = 1; i <= n; i++) graph2[i].clear();
    blacks.clear();
    good = true;
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}