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

void inputtree(int siz, int root = 1)
{
    dfs(root, 0);
    for (int i = 1; i <= siz; i++) ancestor[i][0] = parent[i];
    for (int pwr = 1; pwr < LOG2_N; pwr++) {
        for (int i = 1; i <= siz; i++) {
            ancestor[i][pwr] = ancestor[ancestor[i][pwr-1]][pwr-1];
        }
    }
}

int x[300005], y[300005];
int freq[300005];

int q;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) uf[i] = i;
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        if (fin(u) != fin(v)) {
            un(u, v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    inputtree(n);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d%d", x + i, y + i);
        freq[x[i]]++; freq[y[i]]++;
    }
    int oddcnt = 0;
    for (int i = 1; i <= n; i++) {
        if (freq[i] % 2) oddcnt++;
    }
    if (oddcnt) {
        printf("NO\n%d", oddcnt / 2); return 0;
    }
    printf("YES\n");
    for (int qr = 1; qr <= q; qr++) {
        int lcanode = lca(x[qr], y[qr]);
        vector<int> up, down;
        while (x[qr] != lcanode) {
            up.push_back(x[qr]);
            x[qr] = parent[x[qr]];
        }
        while (y[qr] != lcanode) {
            down.push_back(y[qr]);
            y[qr] = parent[y[qr]];
        }
        printf("%d\n", (int)up.size() + (int)down.size() + 1);
        for (int i = 0; i < up.size(); i++) {
            printf("%d ", up[i]);
        }
        printf("%d ", lcanode);
        reverse(down.begin(), down.end());
        for (int i = 0; i < down.size(); i++) {
            printf("%d ", down[i]);
        }
        printf("\n");
    }
    return 0;
}