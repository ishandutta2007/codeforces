#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

#define ll long long

int n, m;
vector<int> graph[300005];
vector<pair<int, int> > tree1[300005];
int parent[300005];
bool vis[300005];
int depth[300005];
int upamt[300005];
int far[300005];

void dfs1(int node)
{
    vis[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        int child = graph[node][i];
        if (vis[child]) {
            if (child == parent[node]) continue;
            upamt[node] = max(upamt[node], depth[node] - depth[child]);
            continue;
        }
        tree1[node].push_back(make_pair(child, 0));
        parent[child] = node;
        depth[child] = depth[node] + 1;
        dfs1(child);
    }
}

void dfs2(int node)
{
    for (int i = 0; i < tree1[node].size(); i++) {
        pair<int, int>& pr = tree1[node][i];
        dfs2(pr.first);
        if (!upamt[pr.first]) {
            //printf("%d %d\n", node, pr.first);
            pr.second = 1;
        }
        upamt[node] = max(upamt[node], upamt[pr.first] - 1);
    }
}

int ans = 0;

void dfs3(int node)
{
    vector<int> paths;
    for (int i = 0; i < tree1[node].size(); i++) {
        pair<int, int>& pr = tree1[node][i];
        dfs3(pr.first);
        int plen = far[pr.first] + pr.second;
        far[node] = max(far[node], plen);
        paths.push_back(plen);
    }
    sort(paths.begin(), paths.end());
    if (paths.size() == 1) {
        ans = max(ans, paths[0]);
    } else if (paths.size() >= 2) {
        ans = max(ans, paths[paths.size() - 1] + paths[paths.size() - 2]);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs1(1);
    dfs2(1);
    dfs3(1);
    printf("%d", ans);
    return 0;
}