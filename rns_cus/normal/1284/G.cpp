#include <bits/stdc++.h>
using namespace std;

#define N 2010

int n, m, node;
char s[22][22];

inline int idx(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) return 0;
    return (x - 1) * m + y;
}

bool block[N], black[N];

int tot_edge;
int head[N], d[N], nxt[N*N], to[N*N], pa[N];

void init(int n) {
    for (int i = 1; i <= n; i ++) head[i] = 0;
    tot_edge = 0;
}

void add_edge(int x, int y) {
    tot_edge ++;
    to[tot_edge] = y;
    nxt[tot_edge] = head[x], head[x] = tot_edge;
    return;
}

bool in[N];
int e, x[N], y[N];

int rt[N], deg[N];

int find_rt(int u) {
    return rt[u] == u ? u : rt[u] = find_rt(rt[u]);
}

void link(int u, int v) {
    u = find_rt(u), v = find_rt(v);
    if (u != v) rt[u] = v;
}

void init() {
    for (int i = 1; i <= node; i ++) rt[i] = i;
}

void build_graph() {
    init(e + 2); init();
    vector <int> X, Y, vec;
    for (int i = 1; i <= e; i ++) {
        if (y[i] == 1) continue;
        if (in[i]) X.push_back(i), link(x[i], y[i]);
        else Y.push_back(i);
    }
    for (auto v : Y) {
        int p = x[v], q = y[v];
        if (deg[p] < 2 && deg[q] < 2) add_edge(e + 2, v);
        else {
            for (auto u : X) {
                int s = x[u], t = y[u];
                if (black[s]) deg[s] --;
                else deg[t] --;
                if (deg[p] < 2 && deg[q] < 2) add_edge(u, v);
                if (black[s]) deg[s] ++;
                else deg[t] ++;
            }
        }
        if (find_rt(x[v]) != find_rt(y[v])) add_edge(v, e + 1);
        else vec.push_back(v);
    }
    for (auto u : X) {
        init();
        for (auto v : X) if (v != u) link(x[v], y[v]);
        for (auto v : vec) if (find_rt(x[v]) != find_rt(y[v])) add_edge(v, u);
    }
}

queue <int> Q;
vector <int> seq;
bool spfa(int n) {
    for (int i = 1; i <= n; i ++) d[i] = -1, pa[i] = -1;
    while (!Q.empty()) Q.pop();
    Q.push(n);
    d[n] = 0;
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        for (int i = head[x]; i; i = nxt[i]) {
            int y = to[i];
            if (d[y] >= 0) continue;
            d[y] = d[x] + 1, pa[y] = x;
            Q.push(y); if (y == n - 1) break;
        }
    }
    seq.clear(); n --;
    if (pa[n] < 0) return 0; n = pa[n];
    while (n < e + 2) seq.push_back(n), n = pa[n];
    reverse(seq.begin(), seq.end());
    return 1;
}

void expand() {
    int rlt = 0, sz = seq.size();
    for (int i = 0; i < sz; i ++) {
        int u = seq[i];
        in[u] ^= 1;
        int p = x[u], q = y[u];
        if (black[p]) deg[p] += in[u] ? 1 : -1;
        else deg[q] += in[u] ? 1 : -1;
    }
}

bool con[N][N];

int main() {
    int T; block[0] = 1;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m); e = 0;
        for (int i = 1; i <= n; i ++) scanf("%s", s[i] + 1); node = n * m;
        for (int i = 1; i <= node; i ++) rt[i] = i, deg[i] = 0;
        for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) {
            int c = idx(i, j);
            if (s[i][j] == 'X') {
                block[c] = 1;
                black[c] = 0;
                continue;
            }
            block[c] = 0, black[c] = i + j + 1 & 1;
            int d = idx(i - 1, j);
            if (!block[d]) {
                link(c, d);
                e ++, x[e] = c, y[e] = d;
            }
            d = idx(i, j - 1);
            if (!block[d]) {
                link(c, d);
                e ++, x[e] = c, y[e] = d;
            }
        }
        int p = find_rt(1); black[1] = 0;
        for (int i = 2; i <= node; i ++) if (!block[i] && find_rt(i) != p) p = -1;
        if (p < 0) {puts("NO"); continue;}
        int k, cnt = 0;
        for (int i = 1; i <= node; i ++) if (black[i]) cnt ++;
        cnt <<= 1;
        for (k = 0; k < cnt; k ++) {
            build_graph();
            if (!spfa(e + 2)) break;
            expand();
        }

        if (k < cnt) {for (int i = 1; i <= e; i ++) in[i] = 0;puts("NO"); continue;}
        typedef pair <int, int> pii;
        vector <pii> vec;
        init();
        for (int i = 1; i <= e; i ++) if (in[i]) vec.emplace_back(x[i], y[i]), link(x[i], y[i]);
        for (int i = 1; i <= e; i ++) if (!in[i]) {
            int u = find_rt(x[i]), v = find_rt(y[i]);
            if (u != v) rt[u] = v, vec.emplace_back(x[i], y[i]);
        }
        for (auto p : vec) con[p.second][p.first] = 1;
        puts("YES");
        for (int i = 0; i < 2 * n - 1; puts(""), i ++) for (int j = 0; j < 2 * m - 1; j ++) {
            int x = i >> 1, y = j >> 1; x ++, y ++;
            if (i & j & 1) putchar(' ');
            else if (~(i | j) & 1) putchar(s[x][y]);
            else if (i & 1) putchar(con[idx(x,y)][idx(x+1,y)] ? '?' : ' ');
            else putchar(con[idx(x,y)][idx(x,y+1)] ? '?' : ' ');
        }
        for (auto p : vec) con[p.second][p.first] = 0;
        for (int i = 1; i <= e; i ++) in[i] = 0;
    }

    return 0;
}