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

// TEMPLATE STARTS BELOW
// REMEMBER TO CHANGE ARRAY SIZES AS NEEDED

#define LOG2_N 19

vector<int> graph[500005];
int depth[500005];
int parent[500005];
int ancestor[500005][LOG2_N];

void dfs(int node, int prt)
{
    depth[node] = depth[prt] + 1;
    parent[node] = prt;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == prt) continue;
        dfs(nxt, node);

        /* you can do other things here, such as tree DP */
    }
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

void buildtree(int siz, int root = 1)
{
    dfs(root, 0);
    for (int i = 1; i <= siz; i++) ancestor[i][0] = parent[i];
    for (int pwr = 1; pwr < LOG2_N; pwr++) {
        for (int i = 1; i <= siz; i++) {
            ancestor[i][pwr] = ancestor[ancestor[i][pwr-1]][pwr-1];
        }
    }
}

int uf[500005];

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

int n, m, k;

int dis(pair<int, int> a)
{
    return depth[a.first] + depth[a.second]
        - 2 * depth[lca(a.first, a.second)];
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return dis(a) < dis(b);
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) uf[i] = i;
    vector<pair<int, int> > eedges;
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        if (fin(u) == fin(v)) {
            eedges.push_back(make_pair(u, v));
        } else {
            un(u, v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    buildtree(n);
    int indep_size = (k / 2) + (k % 2);
    if (eedges.empty()) {
        vector<int> odd, even;
        for (int i = 1; i <= n; i++) {
            if (depth[i] % 2) odd.push_back(i);
            else even.push_back(i);
        }
        printf("1\n");
        if (odd.size() >= indep_size) {
            for (int i = 0; i < indep_size; i++) {
                printf("%d ", odd[i]);
            }
        } else {
            for (int i = 0; i < indep_size; i++) {
                printf("%d ", even[i]);
            }
        }
        return 0;
    }
    sort(eedges.begin(), eedges.end(), cmp);
    pair<int, int> cur = eedges[0];
    int clen = dis(cur) + 1;
    vector<int> path;
    int l = cur.first;
    int r = cur.second;
    int lcanode = lca(l, r);
    //printf("%d %d %d\n", l, r, lcanode);
    while (l != lcanode) {
        path.push_back(l); l = parent[l];
    }
    vector<int> right;
    while (r != lcanode) {
        right.push_back(r); r = parent[r];
    }
    right.push_back(lcanode);
    reverse(right.begin(), right.end());
    for (int i = 0; i < right.size(); i++) {
        path.push_back(right[i]);
    }
    if (clen <= k) {
        printf("2\n%d\n", clen);
        for (int i = 0; i < path.size(); i++) {
            printf("%d ", path[i]);
        }
    } else {
        printf("1\n");
        for (int i = 1; i <= indep_size; i++) {
            printf("%d ", path[2 * i - 2]);
        }
    }
    return 0;
}