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
//vector<int> cut_child[200005], link_child[200005];
int n;

int leafcnt = 0, cutcnt = 0;

bool dfs(int node, int prt)
{
    bool ret = false;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == prt) continue;
        if (!dfs(nxt, node)) {
            //link_child[node].push_back(nxt);
            ret = true;
        } else {
            //cut_child[node].push_back(nxt);
            cutcnt++;
        }
    }
    if (!ret) leafcnt++;
    return ret;
}

void work()
{
    leafcnt = cutcnt = 0;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        //cut_child[i].clear();
        //link_child[i].clear();
    }
    printf("%d\n", leafcnt - cutcnt);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}