#include <bits/stdc++.h>

using namespace std;

#define N 2010
#define X first
#define Y second
#define inf 1000000000000000LL
typedef long long LL;
typedef pair <LL, int> pii;

priority_queue <pii> q;

int n, m;
LL dis[N][N], f[N];
int T[N], C[N], vis[N];
int src, dst, tot, I;

int head[N], to[N], nxt[N], w[N];

void add(int x, int y, int z) {
    nxt[++ tot] = head[x]; head[x] = tot; to[tot] = y; w[tot] = z;
    nxt[++ tot] = head[y]; head[y] = tot; to[tot] = x; w[tot] = z;
}

LL run() {
    if(src == dst) return 0;
    for(int i= 1; i <= n; i ++) vis[i] = 0, f[i] = inf;
    f[src] = 0;
    while(!q.empty()) q.pop();
    q.push(pii(0, src));
    while(!q.empty()) {
        pii tp = q.top(); q.pop();
        if(tp.Y == dst) return f[tp.Y];
        if(vis[tp.Y]) continue;
        vis[tp.Y] = 1;
        LL tt = - tp.X + C[tp.Y];
        for(int j = 1; j <= n; j ++) if(!vis[j] && dis[tp.Y][j] <= T[tp.Y]) {
            if(f[j] > tt) {
                f[j] = tt;
                q.push(pii(-tt, j));
            }
        }
    }
    return -1;
}

void init() {
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) dis[i][j] = inf;
        dis[i][i] = 0;
        while(!q.empty()) q.pop();
        q.push(pii(0, i));
        while(!q.empty()) {
            pii tp = q.top(); q.pop();
            if(vis[tp.Y] == i) continue;
            vis[tp.Y] = i;
            for(int j = head[tp.Y]; j; j = nxt[j]) {
                int x = to[j];
                LL tt = - tp.X + w[j];
                if(dis[i][x] > tt) {
                    dis[i][x] = tt;
                    q.push(pii(-tt, x));
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    scanf("%d%d", &src, &dst);
    for(int i = 1; i <= m; i ++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    for(int i = 1; i <= n; i ++) scanf("%d%d", T + i, C + i);
    init();
    printf("%I64d\n", run());
    return 0;
}