#include <bits/stdc++.h>
using namespace std;

#define N 500005
#define K 22
#define INF 1000000000

template <class T> void chkmax(T &a, T b) { if (a < b) a = b; }

int n, timp;
int p[N], mask[N], ans[N];
int bag[(1<<K)+5];
char ch;
vector<int> v[N];
int ver[N], dt[N], ft[N], sz[N], hson[N], h[N];

void dfs(int x) {
    dt[x] = ++timp;
    ver[timp] = x;
    int mx = -1;
    sz[x] = 1;
    for (int i = 0; i < v[x].size(); i ++) {
        int y = v[x][i];
        dfs(y);
        if (mx < sz[y]) mx = sz[y], hson[x] = y;
        sz[x] += sz[y];
    }
    ft[x] = timp;
}

void update(int z, int x) {
    chkmax(ans[x], bag[mask[z]] + h[z] - 2 * h[x]);
    for (int i = 0; i < K; i ++) {
        chkmax(ans[x], bag[mask[z]^(1<<i)] + h[z] - 2 * h[x]);
    }
}

void dsu(int x, bool keep) {
    for (int i = 0; i < v[x].size(); i ++) {
        int y = v[x][i];
        if (y == hson[x]) continue;
        dsu(y, 0);
    }
    if (hson[x] != -1) {
        dsu(hson[x], 1);
        ans[x] = ans[hson[x]];
    }
    for (int i = 0; i < v[x].size(); i ++) {
        int y = v[x][i];
        if (y == hson[x]) continue;
        chkmax(ans[x], ans[y]);
        for (int j = dt[y]; j <= ft[y]; j ++) {
            update(ver[j], x);
        }
        for (int j = dt[y]; j <= ft[y]; j ++) {
            int z = ver[j];
            chkmax(bag[mask[z]], h[z]);
        }
    }
    update(x, x);
    chkmax(bag[mask[x]], h[x]);
    if (!keep) {
        for (int i = dt[x]; i <= ft[x]; i ++) {
            int y = ver[i];
            bag[mask[y]] = -INF;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i ++) {
        scanf("%d %c", &p[i], &ch);
        v[p[i]].push_back(i);
        h[i] = h[p[i]] + 1;
        mask[i] = mask[p[i]] ^ (1 << (ch - 'a'));
    }
    memset(hson, -1, sizeof hson);
    dfs(1);
    for (int i = 0; i < (1 << K); i ++) bag[i] = -INF;
    dsu(1, 1);
    for (int i = 1; i <= n; i ++) printf("%d ", ans[i]);
}