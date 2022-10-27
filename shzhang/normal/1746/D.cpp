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

int n; ll k;
int parent[200005];
vector<int> children[200005];
ll s[200005];
ll g[200005];
ll flow[200005];
ll fhigh[200005];

void dfs1(int node, ll lcnt)
{
    g[node] = lcnt;
    int childcnt = (int)children[node].size();
    for (int i = 0; i < childcnt; i++) {
        int child = children[node][i];
        dfs1(child, lcnt / childcnt);
    }
}

void dfs2(int node)
{
    if (children[node].empty()) {
        flow[node] = g[node] * s[node];
        fhigh[node] = (g[node] + 1) * s[node];
        return;
    }
    flow[node] = fhigh[node] = 0;
    for (int i = 0; i < children[node].size(); i++) {
        dfs2(children[node][i]);
    }
    ll paths = 0;
    vector<ll> addval;
    for (int i = 0; i < children[node].size(); i++) {
        int child = children[node][i];
        flow[node] += flow[child];
        paths += g[child];
        addval.push_back(fhigh[child] - flow[child]);
    }
    sort(addval.begin(), addval.end());
    reverse(addval.begin(), addval.end());
    for (int i = 0; i < g[node] - paths; i++) {
        flow[node] += addval[i];
    }
    flow[node] += s[node] * g[node];
    fhigh[node] = flow[node];
    fhigh[node] += s[node];
    fhigh[node] += addval[g[node] - paths];
}

void work()
{
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        children[i].clear();
    }
    for (int i = 2; i <= n; i++) {
        scanf("%d", parent + i);
        children[parent[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) scanf("%lld", s + i);
    dfs1(1, k);
    //for (int i = 1; i <= n; i++) printf("%lld ", g[i]);
    dfs2(1);
    printf("%lld\n", flow[1]);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}