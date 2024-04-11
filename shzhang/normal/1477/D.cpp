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
vector<int> graph[500005];
bool vis[500005];

set<int> unvis;

vector<int> children[500005];
int depth[500005];
int parent[500005];

bool taken[500005];

int valid_children[500005];

void dfs(int node)
{
    unvis.erase(node);
    vector<int> deleted;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (!vis[nxt]) {
            unvis.erase(nxt); deleted.push_back(nxt);
        }
    }
    vector<int> neigh;
    while (!unvis.empty()) {
        neigh.push_back(*unvis.begin());
        unvis.erase(unvis.begin());
    }
    for (int i = 0; i < deleted.size(); i++) {
        unvis.insert(deleted[i]);
    }
    for (int i = 0; i < neigh.size(); i++) {
        vis[neigh[i]] = true;
    }
    for (int i = 0; i < neigh.size(); i++) {
        children[node].push_back(neigh[i]);
        //printf("edge %d %d\n", node, neigh[i]);
        dfs(neigh[i]);
    }
}

int tdfs(int node, int prt, priority_queue<pair<int, int> >& leaves)
{
    parent[node] = prt;
    depth[node] = depth[prt] + 1;
    if (!children[node].size()) {
        leaves.push(make_pair(depth[node], node));
    }
    int retv = 1;
    for (int i = 0; i < children[node].size(); i++) {
        int child = children[node][i];
        retv += tdfs(child, node, leaves);
    }
    valid_children[node] = children[node].size();
    return retv;
}

vector<int> ans1, ans2;
int pans1[500005], pans2[500005];

void work2(int root)
{
    if (!children[root].size()) {
        ans1.push_back(root);
        ans2.push_back(root);
        return;
    }
    priority_queue<pair<int, int> > leaves;
    int remaining = tdfs(root, 0, leaves);
    while (!leaves.empty()) {
        pair<int, int> pr;
        while (!leaves.empty()) {
            pr = leaves.top();
            leaves.pop();
            if (!taken[pr.second]) break;
        }
        int leaf = pr.second;
        int node = parent[leaf];
        int delamt = 0;
        for (int i = 0; i < children[node].size(); i++) {
            if (!taken[children[node][i]]) delamt++;
        }
        if (remaining - delamt >= 3) {
            ans1.push_back(node);
            for (int i = 0; i < children[node].size(); i++) {
                if (!taken[children[node][i]]) {
                    ans1.push_back(children[node][i]);
                    ans2.push_back(children[node][i]);
                    taken[children[node][i]] = true;
                }
            }
            ans2.push_back(node);
            taken[node] = true;
            int prt = parent[node];
            valid_children[prt]--;
            if (!valid_children[prt]) {
                leaves.push(make_pair(depth[prt], prt));
            }
            remaining -= delamt + 1;
        } else {
            ans1.push_back(node);
            for (int i = 0; i < children[node].size(); i++) {
                if (!taken[children[node][i]]) {
                    ans1.push_back(children[node][i]);
                    ans2.push_back(children[node][i]);
                }
            }
            if (parent[node]) {
                ans1.push_back(parent[node]);
                ans2.push_back(parent[node]);
            }
            ans2.push_back(node);
            return;
        }
    }
}

void work()
{
    scanf("%d%d", &n, &m);
    unvis.clear(); ans1.clear(); ans2.clear();
    for (int i = 1; i <= n; i++) {
        graph[i].clear(); vis[i] = false;
        valid_children[i] = 0;
        taken[i] = false;
        children[i].clear();
        unvis.insert(i);
    }
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> roots;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            roots.push_back(i);
            vis[i] = true; dfs(i);
        }
    }
    for (int i = 0; i < roots.size(); i++) {
        work2(roots[i]);
    }
    for (int i = 0; i < n; i++) {
        pans1[ans1[i]] = i + 1;
        pans2[ans2[i]] = i + 1;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", pans1[i]);
    }
    printf("\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", pans2[i]);
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        work();
        //printf("---\n");
    }
    return 0;
}