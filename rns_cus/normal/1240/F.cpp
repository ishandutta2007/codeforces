#include <bits/stdc++.h>
using namespace std;

#define N 111
#define M 1010

int n, m, k, tot, x[M], y[M], head[N], nxt[M<<1], to[M<<1], id[M<<1], col[M];
int cnt[N][M], now[M][N];
bool vis[M];

typedef pair <int, int> pii;

set <pii> s[N];

void add(int u, int v, int i) {
    tot ++; id[tot] = i;
    to[tot] = v, nxt[tot] = head[u], head[u] = tot;
}

void add_edge(int u, int v, int i) {
    add(u, v, i), add(v, u, i);
}

void insert(int u, int c) {
    int &p = cnt[u][c];
    s[u].erase(pii(p, c));
    s[u].insert(pii(++p, c));
}

void insert(int u, int v, int c) {
    insert(u, c), insert(v, c);
}

void erase(int u, int c) {
    int &p = cnt[u][c];
    s[u].erase(pii(p, c));
    s[u].insert(pii(--p, c));
}

bool check(int u, int c) {
    return cnt[u][c] <= s[u].begin() -> first + 1;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1, x; i <= n; i ++) scanf("%d", &x);
    for (int i = 1; i <= m; i ++) scanf("%d %d", &x[i], &y[i]), add_edge(x[i], y[i], i);
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= k; j ++) s[i].insert(pii(0, j));
    for (int i = 1; i <= m; i ++) {
        int u = x[i], v = y[i];
        int A = s[u].begin() -> second;
        if (check(v, A)) {
            col[i] = A;
            insert(u, v, A);
            continue;
        }
        int B = s[v].begin() -> second;
        if (check(u, B)) {
            col[i] = B;
            insert(u, v, B);
            continue;
        }
        memset(vis, 0, sizeof vis);
        for (int j = 1; j <= n; j ++) now[A][j] = now[B][j] = head[j];
        vector <int> vec;
        int z = u, w = B;
        while (1) {
            for (int &j = now[w][z]; j; j = nxt[j]) {
                if (col[id[j]] != w || vis[id[j]]) continue;
                vec.push_back(id[j]);
                vis[id[j]] = 1;
                break;
            }
            if (!now[w][z]) break;
            z = to[now[w][z]];
            w ^= A ^ B;
        }
        insert(u, A), insert(v, B), insert(z, w), erase(z, w ^ A ^ B);
        col[i] = B;
        for (auto x : vec) col[x] ^= A ^ B;
    }
    for (int i = 1; i <= m; i ++) printf("%d\n", col[i]);

    return 0;
}