#include <bits/stdc++.h>
using namespace std;

#define N 125
#define M 10005

const int MV = N << 1, ME = N * N * 2;

const int inf = 1e9;

struct max_flow {

    struct edge {
        int to, cap, nxt;
    } edge[ME];

    int nodes, src, dst, cnt;

    int head[MV];

    void init() {
        memset(head, -1, sizeof head);
        cnt = 0;
    }

    void add(int x, int y, int w) {
        edge[cnt].to = y, edge[cnt].cap = w, edge[cnt].nxt = head[x];
        head[x] = cnt ++;
        edge[cnt].to = x, edge[cnt].cap = 0, edge[cnt].nxt = head[y];
        head[y] = cnt ++;
    }

    int level[MV], gap[MV], q[MV];
    bool vis[MV];

    void bfs() {
        memset(level, 0, sizeof level);
        memset(gap, 0, sizeof gap);
        memset(vis, 0, sizeof vis);
        int h = 0, t = 0;
        q[t++] = dst;
        vis[dst] = 1;
        while (h < t) {
            int x = q[h++];
            for (int i = head[x]; ~i; i = edge[i].nxt) {
                int y = edge[i].to;
                if (!vis[y]) {
                    level[y] = level[x] + 1;
                    gap[level[y]] ++;
                    q[t++] = y;
                    vis[y] = 1;
                }
            }
        }
    }

    int last[MV];

    int dfs(int x, int f) {
        if (x == dst) return f;
        int sap = 0;
        for (int i = last[x]; ~i; i = edge[i].nxt) {
            int y = edge[i].to;
            if (edge[i].cap > 0 && level[x] == level[y] + 1) {
                last[x] = i;
                int tmp = dfs(y, min(f - sap, edge[i].cap));
                edge[i].cap -= tmp;
                edge[i^1].cap += tmp;
                sap += tmp;
                if (sap == f) return sap;
            }
        }
        if (level[src] >= nodes) return sap;
        if (!(-- gap[level[x]])) level[src] = nodes;
        gap[++level[x]] ++;
        last[x] = head[x];
        return sap;
    }

    int maxflow(int _src, int _dst, int _nodes) {
        src = _src, dst = _dst, nodes = _nodes;
        bfs();
        memcpy(last, head, sizeof last);
        int rlt = 0;
        while (level[src] < nodes) rlt += dfs(src, inf);
        return rlt;
    }
} G;

template <class T> bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
int n, k;
int p[N], c[N], l[N];

int pcnt, prime[M];
bool vis[M];

void ppm() {
    for (int i = 2; i < M; i ++) {
        if (!vis[i]) prime[pcnt++] = i;
        for (int j = 0; j < pcnt && prime[j] * i < M; j ++) {
            vis[i*prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int id0[N], id1[N], cnt0, cnt1;

bool test(int lvl) {
    if (lvl == n + 1) return 1;
    cnt0 = 0, cnt1 = 0;
    int ps = 0, mx = 0;
    for (int i = 1; i <= n; i ++) {
        if (l[i] > lvl) continue;
        if (c[i] == 1) {
            if (chkmax(mx, p[i])) ps = i;
        }
    }
    if (ps) id1[cnt1++] = ps;
    for (int i = 1; i <= n; i ++) {
        if (l[i] > lvl) continue;
        if (c[i] == 1) continue;
        if (c[i] & 1) id1[cnt1++] = i;
        else id0[cnt0++] = i;
    }
    int src = cnt0 + cnt1 + 1, dst = cnt0 + cnt1 + 2;
    G.init();
    int tot = 0;
    for (int i = 0; i < cnt0; i ++) {
        G.add(src, i + 1, p[id0[i]]);
        tot += p[id0[i]];
    }
    for (int i = 0; i < cnt1; i ++) {
        G.add(cnt0 + i + 1, dst, p[id1[i]]);
        tot += p[id1[i]];
    }
    for (int i = 0; i < cnt0; i ++)
    for (int j = 0; j < cnt1; j ++) {
        if (!vis[c[id0[i]]+c[id1[j]]]) {
            G.add(i + 1, cnt0 + j + 1, inf);
        }
    }
    return tot - G.maxflow(src, dst, dst) >= k;
}

int main() {
    ppm();
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i ++) {
        scanf("%d %d %d", &p[i], &c[i], &l[i]);
    }
    int st = 1, en = n + 1;
    while (st < en) {
        int mid = st + en >> 1;
        if (test(mid)) en = mid;
        else st = mid + 1;
    }
    if (st == n + 1) return puts("-1"), 0;
    printf("%d\n", st);
    return 0;
}