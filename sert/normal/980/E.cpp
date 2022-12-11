#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 20;
const int N = (int)1e6 + 34;
const int INF = (int)1e9 + 34;

vector<int> es[N];
int depth[N], parent[N];
bool is_in[N];
int jmp[N][M];

void dfs_p(int v, int pr) {
    parent[v] = pr;
    depth[v] = depth[pr] + 1;
    for (int w: es[v]) {
        if (w == pr) continue;
        dfs_p(w, v);
    }
}

inline int dist2root(int v) {
    int w = v;
    for (int i = M - 1; i >= 0; i--) {
        int c = jmp[w][i];
        if (!is_in[c]) w = c;
    }
    return depth[v] - depth[w] + 1;
}

void solve() {
    int n, k, v1, v2;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &v1, &v2);
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }
    int root = n - 1;
    depth[root] = -1;
    dfs_p(root, root);

    for (int i = 0; i < n; i++) {
        jmp[i][0] = parent[i];
    }
    for (int j = 1; j < M; j++) {
        for (int i = 0; i < n; i++) {
            jmp[i][j] = jmp[jmp[i][j - 1]][j - 1];
        }
    }
    is_in[root] = true;

    int num_in = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (is_in[i]) continue;
        int dist = dist2root(i);
        if (num_in + dist > n - k) continue;
        num_in += dist;
        int v = i;
        while (!is_in[v]) {
            is_in[v] = true;
            v = parent[v];
        }
    }

    for (int i = 0; i < n; i++) {
        if (!is_in[i]) printf("%d ", i + 1);
    }
    printf("\n");
}

int main() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    //solve();
    //solve();
    //solve();
    //solve();
    solve();
    return 0;
}