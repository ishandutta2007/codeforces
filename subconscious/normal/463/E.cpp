#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
const int maxn = 1e5+5;

int N, Q, val[maxn];
int f[maxn], vis[maxn];
int en, first[maxn*2], jump[maxn*2], edge[maxn*2];

inline int gcd (int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int getfar(int u, int x) {
    if (gcd(val[u], val[x]) > 1)
        return u;
    else if (u == 1)
        return -1;
    else
        return getfar(f[u], x);
}

void add_edge (int u, int v) {
    jump[en] = first[u];
    edge[en] = v;
    first[u] = en++;
}

void bfs (int s) {
    queue<int> que;

    que.push(s);
    vis[s] = 1;
    while (!que.empty()) {
        int u = que.front();
        que.pop();

        for (int i = first[u]; i != -1; i = jump[i]) {
            int v = edge[i];
            if (vis[v])
                continue;

            que.push(v);
            f[v] = u;
            vis[v] = 1;
        }
    }
}

void init () {
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i++)
        scanf("%d", &val[i]);

    int u, v;
    en = 0;
    memset(first, -1, sizeof(first));
    for (int i = 1; i < N; i++) {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }

    bfs(1);
}

int main () {
    init();

    int k, u;
    for (int i = 0; i < Q; i++) {
        scanf("%d", &k);
        if (k == 1) {
            scanf("%d", &u);
            printf("%d\n", u == 1 ? -1 : getfar(f[u], u));
        } else {
            scanf("%d", &u);
            scanf("%d", &val[u]);
        }
    }
    return 0;
}