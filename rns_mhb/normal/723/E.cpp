#include <bits/stdc++.h>
using namespace std;
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define N 205
#define M 40005

int tot, n, m;
int now[N], head[N], nxt[M], to[M];
int deg[N];

void add_edge(int x, int y) {
    ++ tot;
    to[tot] = y; nxt[tot] = head[x]; head[x] = tot;
    return;
}

int q[M], qs;
bool vis[M], wis[M];

void dfs(int k, int p) {
    for (int &t = head[k]; t; t = nxt[t]) {
        if (vis[t] || vis[t^1]) continue;
        vis[t] = 1;
        dfs(to[t], t);
    }
    if (p) wis[p] = 1;
    return;
}

int main() {
    int T;
    for (scanf("%d", &T); T --; ) {
        memset(head, 0, sizeof head);
		memset(vis, 0, sizeof vis);
		memset(wis, 0, sizeof wis);
        memset(deg, 0, sizeof deg);
        qs = 0; tot = 1;
        scanf("%d %d", &n, &m);
        int x, y;
        f1(i, 1, m) {
        	scanf("%d %d", &x, &y);
            add_edge(x, y);
            add_edge(y, x);
            deg[x] ++, deg[y] ++;
        }
        int p = 0; int r = tot;
        f1(i, 1, n) if (deg[i] & 1) {
			if (p) {
                add_edge(p, i);
                add_edge(i, p);
                p = 0;
			}
			else p = i;
        }
        p = n;
        f1(i, 1, n) if (deg[i] & 1) p --;
        f1(i, 1, n) now[i] = head[i];
        f1(i, 1, n) if (head[i]) dfs(i, 0);
        printf("%d\n", p);
        f1(i, 1, n) {
            for (int j = now[i]; j; j = nxt[j]) {
                if (j <= r && wis[j]) printf("%d %d\n", i, to[j]);
            }
        }
    }
	return 0;
}