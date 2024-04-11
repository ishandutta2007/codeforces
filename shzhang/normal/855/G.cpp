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

#define LOG2_N 17
#define P2(x) ((ll)(x) * (ll)((x) - 1))

int n, q;

ll ans = 0;

vector<int> graph[100005];
int depth[100005];
int parent[100005];
int weight[100005];
int ancestor[100005][LOG2_N];

int comp[100005];
vector<int> comp_members[100005];
int comp_root[100005];
ll ansv[100005];

void merge_comp(int a, int b)
{
    //debug("merge %d %d", a, b);
    if (comp_members[a].size() > comp_members[b].size())
        swap(a, b);
    ans -= (ll)(comp_members[a].size()) * ansv[a];
    ans -= (ll)(comp_members[b].size()) * ansv[b];
    for (int i = 0; i < comp_members[a].size(); i++) {
        int x = comp_members[a][i];
        comp_members[b].push_back(x);
        //assert(comp[x] == a);
        comp[x] = b;
    }
    if (depth[comp_root[a]] < depth[comp_root[b]]) {
        //debug("first case");
        ll up_p2_sum = P2(n-1) - ansv[a] - P2(weight[comp_root[b]]);
        ansv[b] += P2(n - weight[comp_root[b]]) - up_p2_sum;
        comp_root[b] = comp_root[a];
    } else {
        //debug("second case");
        ll down_p2_sum = P2(n-1) - ansv[a] - P2(n - weight[comp_root[a]]);
        ansv[b] += P2(weight[comp_root[a]]) - down_p2_sum;
    }
    ans += (ll)(comp_members[b].size()) * ansv[b];
    comp_members[a].clear();
    /*for (int i = 1; i <= n; i++) {
        printf("%lld ", ansv[i]);
    }*/
    //printf("%lld\n", ans);
}

void merge_chain(int from, int to)
{
    while (comp[from] != comp[to]) {
        from = comp_root[comp[from]];
        merge_comp(comp[from], comp[parent[from]]);
    }
}

void dfs(int node, int prt)
{
    ansv[node] += P2(n - 1);
    depth[node] = depth[prt] + 1;
    parent[node] = prt;
    weight[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == prt) continue;
        dfs(nxt, node);
        weight[node] += weight[nxt];
        /* you can do other things here, such as tree DP */
        ansv[node] -= P2(weight[nxt]);
    }
    ll above = n - weight[node];
    ansv[node] -= P2(above);
    ans += ansv[node];
}

int lca(int A, int B)
{
    if (depth[A] < depth[B]) swap(A, B);
    for (int i = 0; i < LOG2_N; i++) {
        if ((depth[A] - depth[B]) & (1 << i)) A = ancestor[A][i];
    }
    if (A == B) return A;
    for (int i = LOG2_N - 1; i >= 0; i--) {
        if (ancestor[A][i] != ancestor[B][i]) {
            A = ancestor[A][i];
            B = ancestor[B][i];
        }
    }
    return parent[A];
}

void inputtree(int siz, int root = 1)
{
    for (int i = 1; i < siz; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(root, 0);
    for (int i = 1; i <= siz; i++) ancestor[i][0] = parent[i];
    for (int pwr = 1; pwr < LOG2_N; pwr++) {
        for (int i = 1; i <= siz; i++) {
            ancestor[i][pwr] = ancestor[ancestor[i][pwr-1]][pwr-1];
        }
    }
}

int main()
{
    scanf("%d", &n); inputtree(n);
    for (int i = 1; i <= n; i++) {
        comp[i] = i;
        comp_members[i].push_back(i);
        comp_root[i] = i;
    }
    printf("%lld\n", ans);
    scanf("%d", &q);
    for (int qry = 1; qry <= q; qry++) {
        int u, v; scanf("%d%d", &u, &v);
        int lcanode = lca(u, v);
        merge_chain(u, lcanode);
        merge_chain(v, lcanode);
        printf("%lld\n", ans);
    }
    return 0;
}