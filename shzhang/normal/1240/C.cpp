#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int n, k;

struct Edge {
    int to, wt;
};

vector<Edge> graph[500005];
vector<int> tree[500005];

bool searched[500005];

#define ll long long

ll f[500005][2];

Edge mkedge(int to, int wt)
{
    Edge e;
    e.to = to;
    e.wt = wt;
    return e;
}

int childwt[500005];
ll value[500005];

bool cmp(int a, int b)
{
    return value[a] > value[b];
}

void dfs(int node)
{
    searched[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        if (!searched[graph[node][i].to]) {
            dfs(graph[node][i].to);
            childwt[graph[node][i].to] = graph[node][i].wt;
            tree[node].push_back(graph[node][i].to);
            value[graph[node][i].to] = f[graph[node][i].to][1] - f[graph[node][i].to][0] + (ll)childwt[graph[node][i].to];
        }
    }
    sort(tree[node].begin(), tree[node].end(), cmp);
    f[node][0] = f[node][1] = 0;
    //if (node == 3) printf("VALUE IS %lld\n", value[4]);
    for (int i = 0; i < tree[node].size(); i++) f[node][0] += f[tree[node][i]][0];
    for (int i = 0; i < tree[node].size(); i++) f[node][1] += f[tree[node][i]][0];
    for (int i = 0; i < tree[node].size() && i < k && value[tree[node][i]] > 0; i++) {
        f[node][0] += value[tree[node][i]];
    }
    for (int i = 0; i < tree[node].size() && i < k-1 && value[tree[node][i]] > 0; i++) {
        f[node][1] += value[tree[node][i]];
    }
}

int main()
{
    int q;
    scanf("%d", &q);
    for (int data = 1; data <= q; data++) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) searched[i] = false;
        for (int i = 1; i <= n; i++) graph[i].clear();
        for (int i = 1; i <= n; i++) tree[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            graph[u].push_back(mkedge(v, w));
            graph[v].push_back(mkedge(u, w));
        }
        dfs(1);
        //printf("%lld %lld\n", f[3][0], f[3][1]);
        printf("%lld\n", f[1][0]);
    }
    return 0;
}