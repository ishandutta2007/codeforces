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

int fib[50];

vector<int> graph[200005];
int weight[200005];

void dfs1(int node, int prt)
{
    weight[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == prt) continue;
        dfs1(nxt, node);
        weight[node] += weight[nxt];
    }
}

void dfs2(int node, int prt, int fiblvl, pair<int, int>& separator)
{
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == prt) continue;
        if (weight[nxt] == fib[fiblvl - 1] ||
            weight[nxt] == fib[fiblvl - 2]) {
                separator.first = node;
                separator.second = nxt;
            }
        dfs2(nxt, node, fiblvl, separator);
    }
}

int uf[200005];

int fin(int x)
{
    if (uf[x] == x) return x;
    return uf[x] = fin(uf[x]);
}

void un(int x, int y)
{
    x = fin(x); y = fin(y);
    if (x != y) uf[x] = y;
}

bool isfib(const vector<int>& nodes, const vector<pair<int, int> >& edges)
{
    /*for (int i = 0; i < nodes.size(); i++) {
        printf("%d ", nodes[i]);
    }
    for (int i = 0; i < edges.size(); i++) {
        printf("[%d %d]", edges[i].first, edges[i].second);
    }
    printf("\n");*/
    int n = nodes.size();
    if (edges.size() != n - 1) abort();
    if (n <= 3) return true;
    int lvl = -1;
    for (int i = 1; i <= 30; i++) {
        if (fib[i] == n) {
            lvl = i; break;
        }
    }
    if (lvl == -1) {
        return false;
    }
    for (int idx = 0; idx < edges.size(); idx++) {
        int u = edges[idx].first;
        int v = edges[idx].second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs1(nodes[0], 0);
    pair<int, int> separator; separator.first = 0;
    dfs2(nodes[0], 0, lvl, separator);
    for (int i = 0; i < n; i++) {
        uf[nodes[i]] = nodes[i];
        graph[nodes[i]].clear();
    }
    //printf("sep %d %d\n", separator.first, separator.second);
    if (separator.first == 0) {
        return false;
    }
    for (int i = 0; i < edges.size(); i++) {
        pair<int, int> e = edges[i];
        if ((e.first == separator.first && e.second == separator.second) || (e.first == separator.second && e.second == separator.first)) continue;
        un(e.first, e.second);
        //printf("<%d %d>\n", e.first, e.second);
    }
    int cnt = 0;
    vector<vector<int> > newnodesv;
    vector<vector<pair<int, int> > > newedgesv;
    for (int i = 0; i < n; i++) {
        if (uf[nodes[i]] != nodes[i]) continue;
        cnt++;
        if (cnt >= 3) abort();
        vector<int> newnodes;
        vector<pair<int, int> > newedges;
        for (int j = 0; j < edges.size(); j++) {
            pair<int, int> cur = edges[j];
            if (fin(cur.first) == nodes[i] && fin(cur.second) == nodes[i]) {
                newedges.push_back(cur);
            }
        }
        for (int j = 0; j < n; j++) {
            if (fin(nodes[j]) == nodes[i]) {
                newnodes.push_back(nodes[j]);
            }
        }
        newnodesv.push_back(newnodes);
        newedgesv.push_back(newedges);
    }
    for (int i = 0; i < newnodesv.size(); i++) {
        if (!isfib(newnodesv[i], newedgesv[i])) return false;
    }
    return true;
}

int main()
{
    fib[0] = fib[1] = 1;
    for (int i = 2; i <= 30; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    int n; scanf("%d", &n);
    vector<int> nodes;
    vector<pair<int, int> > edges;
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        edges.push_back(make_pair(u, v));
    }
    for (int i = 1; i <= n; i++) nodes.push_back(i);
    if (isfib(nodes, edges)) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}