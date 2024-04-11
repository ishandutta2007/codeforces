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

vector<int> tree[300005];
int parent[300005];
int ancestor[300005][19];
int depth[300005];
int dfsorder[300005];
int end_dfsorder[300005];

int dfsnxt = 1;

int n, m;

int from[300005], to[300005];
bool topdown[300005];

void dfs(int node)
{
    depth[node] = depth[parent[node]] + 1;
    dfsorder[node] = dfsnxt++;
    for (int i = 0; i < tree[node].size(); i++) {
        int child = tree[node][i];
        dfs(child);
    }
    end_dfsorder[node] = dfsnxt - 1;
}

int lca(int A, int B)
{
    if (depth[A] < depth[B]) swap(A, B);
    for (int i = 0; i <= 18; i++) {
        if ((depth[A] - depth[B]) & (1 << i)) A = ancestor[A][i];
    }
    if (A == B) return A;
    for (int i = 18; i >= 0; i--) {
        if (ancestor[A][i] != ancestor[B][i]) {
            A = ancestor[A][i];
            B = ancestor[B][i];
        }
    }
    return parent[A];
}

bool cmp(int p1, int p2)
{
    return depth[from[p1]] > depth[from[p2]];
}

#define lowbit(x) ((x)&(-(x)))

int rquery(int* arr, int v)
{
    int ans = 0;
    while (v) {
        ans += arr[v]; v -= lowbit(v);
    }
    return ans;
}

void modify(int* arr, int loc, int val)
{
    //printf("%d %lld\n", loc, val);
    while (loc <= n) {
        arr[loc] += val; loc += lowbit(loc);
    }
}

int query(int* arr, int l, int r)
{
    return rquery(arr, r) - rquery(arr, l-1);
}

int opcnt[300005];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; i++) {
        int prt; scanf("%d", &prt);
        parent[i] = prt;
        tree[prt].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        ancestor[i][0] = parent[i];
    }
    for (int pwr = 1; pwr <= 18; pwr++) {
        for (int i = 1; i <= n; i++) {
            ancestor[i][pwr] = ancestor[ancestor[i][pwr-1]][pwr-1];
        }
    }
    vector<int> topdowns;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", from + i, to + i);
        if (depth[from[i]] > depth[to[i]]) swap(from[i], to[i]);
        int lcanode = lca(from[i], to[i]);
        int plen = depth[from[i]] + depth[to[i]] - 2 * depth[lcanode];
        if (plen <= 1) {
            printf("-1"); return 0;
        }
        if (lcanode == from[i]) {
            topdown[i] = true;
            topdowns.push_back(i);
        }
    }
    sort(topdowns.begin(), topdowns.end(), cmp);
    int ans = 0;
    for (int idx = 0; idx < topdowns.size(); idx++) {
        int i = topdowns[idx];
        //printf("processing %d: %d %d\n", i, from[i], to[i]);
        int plen = depth[to[i]] - depth[from[i]];
        int lnode = to[i];
        for (int b = 0; b <= 18; b++) {
            if ((1 << b) & (plen - 1)) lnode = ancestor[lnode][b];
        }
        int ops = query(opcnt, dfsorder[lnode], end_dfsorder[lnode]) - query(opcnt, dfsorder[to[i]], end_dfsorder[to[i]]);
        if (ops) continue;
        //printf("add %d\n", lnode);
        ans++;
        modify(opcnt, dfsorder[lnode], 1);
    }
    for (int i = 1; i <= m; i++) {
        if (topdown[i]) continue;
        int exc_cnt = query(opcnt, dfsorder[from[i]], end_dfsorder[from[i]]) + query(opcnt, dfsorder[to[i]], end_dfsorder[to[i]]);
        if (exc_cnt == ans) {
            ans++; break;
        }
    }
    printf("%d", ans);
    return 0;
}