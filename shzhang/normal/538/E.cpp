#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

int n;

vector<int> graph[200005];
int f_min[200005];
int f_max[200005];
int wt[200005];
bool searched[200005];

bool dfs(int node, bool ismaxnode)
{
    if (searched[node]) return false;
    searched[node] = true;
    bool isleaf = true;
    vector<int> children;
    for (int i = 0; i < graph[node].size(); i++) {
        if (dfs(graph[node][i], !ismaxnode)) {
            wt[node] += wt[graph[node][i]];
            isleaf = false; children.push_back(graph[node][i]);
        }
    }
    f_min[node] = 100000000;
    if (ismaxnode) {
        f_min[node] = wt[node];
        for (int i = 0; i < children.size(); i++) {
            int child = children[i];
            f_max[node] = max(f_max[node], wt[node] - wt[child] + f_max[child]);
            f_min[node] -= wt[child] - f_min[child];
        }
    } else {
        f_max[node] = wt[node];
        for (int i = 0; i < children.size(); i++) {
            int child = children[i];
            f_min[node] = min(f_min[node], f_min[child]);
            f_max[node] -= wt[child] - f_max[child];
        }
        f_max[node] -= children.size() - 1;
    }
    if (isleaf) f_min[node] = f_max[node] = wt[node] = 1;
    return true;
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
    dfs(1, true);
    printf("%d %d", f_max[1], f_min[1]);
    return 0;
}