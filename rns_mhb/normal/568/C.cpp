#include <bits/stdc++.h>
using namespace std;
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define N 505

int n, m, rt;

#define M 200050
int nn;
int head[N], to[M], nxt[M];
int tat[N], ttat[N], tot;
bool vis[N][N];

void add_edge(int x, int y) {
	++ tot;
	to[tot] = y; nxt[tot] = head[x]; head[x] = tot;
	return;
}
void dfs(int k) {
	vis[rt][k] = 1;
	for (int i = head[k]; i; i = nxt[i]) {
		if (vis[rt][to[i]] == 1) continue;
		dfs(to[i]);
	}
	return;
}
bool solve() {
	for (int i = 2; i <= nn; i ++) rt = i, dfs(rt);
	for (int i = 2; i <= nn; i += 2) {
		if (vis[i][i^1] && vis[i^1][i]) return 1;
		if (vis[i][i^1]) tat[i/2] = 1;
		else if (vis[i^1][i]) tat[i/2] = 0;
	}
	return 0;
}
void go(int k) {
	for (int i = 2; i <= nn; i ++) {
		if (vis[k][i]) tat[i/2] = i & 1;
	}
	return;
}
void ggo(int k) {
	for (int i = 2; i <= nn; i ++) {
		if (vis[k][i]) ttat[i/2] = i & 1;
	}
	return;
}

char s[30], t[205], st[205];
int vc[300], ls;
string ans;

void func(int now) {
    if (now == n + 1) {
        if (ans > st + 1) ans = st + 1;
        return;
    }
    f0(j, 'a', 'a' + ls) {
        if (ttat[now] < 0 || ttat[now] == vc[j]) {
            ttat[now] = vc[j];
            st[now] = j;
            ggo(now * 2 + vc[j]);
            return func(now+1);
        }
    }
    return;
}

int main() {
    scanf("%s", s);
    ls = strlen(s);
    f0(i, 0, ls) vc[i+'a'] = s[i] == 'C';
    scanf("%d %d", &n, &m);
	int x, y, xx, yy;
    char sx[2], sy[2];
    nn = 2 * n + 1;
    while (m --) {
        scanf("%d %s %d %s", &x, sx, &y, sy);
        xx = sx[0] == 'C';
        yy = sy[0] == 'C';
        vis[2*x+xx][2*y+yy] = 1;
        vis[2*y+1-yy][2*x+1-xx] = 1;
    }
    f1(i, 1, nn) f1(j, 1, nn) {
		if (vis[i][j]) add_edge(i, j), vis[i][j] = 0;
    }
    memset(tat, -1, sizeof tat);
    memset(vis, 0, sizeof vis);
    scanf("%s", t + 1);
    if (solve()) puts("-1");
    else {
        ans += 'z' + 1;
        f1(i, 1, n) {
			f1(j, 1, n) ttat[j] = tat[j];
			f0(j, t[i]+1, 'a'+ls) {
				if (ttat[i] < 0 || vc[j] == ttat[i]) {
                    ttat[i] = vc[j]; ggo(i*2+vc[j]);
					st[i] = j;
					func(i+1);
					break;
				}
			}
            if (tat[i] >= 0 && tat[i] != vc[t[i]]) break;
            if (tat[i] == -1) {
				tat[i] = vc[t[i]];
				go(i * 2 + tat[i]);
            }
            st[i] = t[i];
            if (i == n) ans = st + 1;
        }
        if (ans[0] == 'z' + 1) puts("-1");
        else cout << ans << endl;
    }
	return 0;
}