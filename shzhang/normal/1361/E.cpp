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
#include <random>
#include <chrono>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

#define ATTEMPTS 120

int n, m;
vector<int> graph[100005];
bool vis[100005];
bool invis[100005];
vector<int> tree[100005];
vector<int> upedge[100005];
int upcnt[100005];
int psum[100005];

bool good[100005];

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int bad_edges = 0;

void dfs(int node)
{
    vis[node] = true;
    invis[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (!vis[nxt]) {
            tree[node].push_back(nxt); dfs(nxt);
        } else if (invis[nxt]) {
            upedge[node].push_back(nxt);
            upcnt[nxt]++; psum[node]++; psum[nxt]--;
        } else {
            bad_edges++;
        }
    }
    invis[node] = false;
}

int upnode[100005];

ll dfs2(int node)
{
    ll val = 0;
    for (int i = 0; i < tree[node].size(); i++) {
        val += dfs2(tree[node][i]);
        psum[node] += psum[tree[node][i]];
    }
    val -= (ll)node * (ll)upcnt[node];
    for (int i = 0; i < upedge[node].size(); i++) {
        val += (ll)upedge[node][i];
    }
    if (psum[node] == 1) upnode[node] = val;
    return val;
}

void dfs3(int node, bool root)
{
    good[node] = root || (psum[node] == 1 && good[upnode[node]]);
    for (int i = 0; i < tree[node].size(); i++) {
        dfs3(tree[node][i], false);
    }
}

bool solve(int root)
{
    dfs(root);
    if (bad_edges) return false;
    dfs2(root);
    dfs3(root, true);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (good[i]) ans.push_back(i);
    }
    if (ans.size() * 5 < n) {
        printf("-1\n");
    } else {
        for (int i = 0; i < ans.size(); i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return true;
}

void work(void)
{
    /* solve problem here */
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v);
    }
    bool found = false;
    for (int at = 1; at <= ATTEMPTS; at++) {
        for (int i = 1; i <= n; i++) vis[i] = false;
        for (int i = 1; i <= n; i++) good[i] = false;
        for (int i = 1; i <= n; i++) tree[i].clear();
        for (int i = 1; i <= n; i++) upedge[i].clear();
        for (int i = 1; i <= n; i++) upcnt[i] = 0;
        for (int i = 1; i <= n; i++) psum[i] = 0;
        bad_edges = 0;
        if (solve((rng() % n) + 1)) {
            found = true; break;
        }
    }
    if (!found) {
        printf("-1\n");
    }
    for (int i = 1; i <= n; i++) graph[i].clear();
    /* remember to clean up any global variables if needed */
}

int main()
{
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; i++) work();
    return 0;
}