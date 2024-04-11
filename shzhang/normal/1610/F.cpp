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

int n, m;

vector<pair<int, int> > g1[300005], g2[300005];

int uf[300005];

int fin(int a)
{
    if (uf[a] == a) return a;
    return uf[a] = fin(uf[a]);
}

void un(int a, int b)
{
    a = fin(a); b = fin(b);
    if (a == b) return;
    uf[a] = b;
}

int from1[1200005], to1[1200005];
vector<int> path1[1200005];

bool isvalid[600005];

int absolute(int x)
{
    return x < 0 ? -x : x;
}

void find_path(vector<pair<int, int> >* graph, int* from, int* to, vector<int>* path, int idx, int start)
{
    int cur = start;
    from[idx] = start;
    while (true) {
        while (!graph[cur].empty() && !isvalid[absolute(graph[cur].back().second)])
            graph[cur].pop_back();
        if (graph[cur].empty()) break;
        pair<int, int> edge = graph[cur].back();
        path[idx].push_back(edge.second);
        isvalid[absolute(edge.second)] = false;
        graph[cur].pop_back();
        cur = edge.first;
    }
    to[idx] = cur;
}

int make_flow(vector<pair<int, int> >* graph, int* from, int* to, vector<int>* path, int startidx)
{
    set<int> odds;
    for (int i = 1; i <= n; i++) {
        if (graph[i].size() % 2) odds.insert(i);
    }
    int idx = startidx;
    while (!odds.empty()) {
        int start = *odds.begin();
        odds.erase(odds.begin());
        find_path(graph, from, to, path, idx, start);
        odds.erase(to[idx]);
        idx++;
    }
    for (int i = 1; i <= n; i++) {
        while (!graph[i].empty()) {
            find_path(graph, from, to, path, idx, i);
            idx++;
        }
    }
    return idx;
}

vector<pair<int, int> > chains[300005];
bool vis[300005];
bool isrev[1200005];

void dfs(int node, int prevedge)
{
    //printf("%d %d\n", node, prevedge);
    if (vis[node]) return;
    vis[node] = true;
    for (int i = 0; i < chains[node].size(); i++) {
        if (absolute(chains[node][i].second) != prevedge) {
            isrev[absolute(chains[node][i].second)] = (chains[node][i].second < 0);
            dfs(chains[node][i].first, absolute(chains[node][i].second));
            break;
        }
    }
}

int ans[300005];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) uf[i] = i;
    for (int i = 1; i <= m; i++) {
        isvalid[i] = true;
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        vector<pair<int, int> >* graph = (w == 1 ? g1 : g2);
        graph[u].push_back(make_pair(v, i));
        graph[v].push_back(make_pair(u, -i));
        //if (w == 1) un(u, v);
    }
    int anscnt = 0;
    for (int i = 1; i <= n; i++) {
        if (g1[i].size() % 2) anscnt++;
    }
    int last1 = make_flow(g1, from1, to1, path1, 1);
    int last2 = make_flow(g2, from1, to1, path1, last1);
    /*for (int i = 1; i < last2; i++) {
        printf("%d -> %d: ", from1[i], to1[i]);
        for (int j = 0; j < path1[i].size(); j++) {
            printf("%d ", path1[i][j]);
        }
        printf("\n");
    }*/
    for (int i = 1; i < last2; i++) {
        if (from1[i] != to1[i]) {
            chains[from1[i]].push_back(make_pair(to1[i], i));
            chains[to1[i]].push_back(make_pair(from1[i], -i));
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && chains[i].size() == 1)
            dfs(i, -1);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            dfs(i, -1);
    }
    for (int i = 1; i < last2; i++) {
        //printf("%d", isrev[i]);
        for (int j = 0; j < path1[i].size(); j++) {
            int edgeid = absolute(path1[i][j]);
            int flip = (path1[i][j] < 0 ? 1 : 0) + isrev[i];
            ans[edgeid] = (flip == 1 ? 2 : 1);
        }
    }
    printf("%d\n", anscnt);
    for (int i = 1; i <= m; i++) printf("%d", ans[i]);
    return 0;
}