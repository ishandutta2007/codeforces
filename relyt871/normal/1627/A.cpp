#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 55;
const int MAXN = 500005;

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

int n, m, r, c;
int qx[MAXN], hx, tx, qy[MAXN], hy, ty, dis[N][N];
char g[N][N];

void solve() {
    read(n); read(m); read(r); read(c);
    hx = tx = 1; hy = ty = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%s", g[i] + 1);
        for (int j = 1; j <= m; ++j) {
            if (g[i][j] == 'B') {
                dis[i][j] = 0;
                qx[++tx] = i;
                qy[++ty] = j;
            } else {
                dis[i][j] = 1000000;
            }
        }
    }
    while (hx <= tx) {
        int x = qx[hx++], y = qy[hy++];
        for (int i = 1; i <= m; ++i) {
            if (dis[x][i] > dis[x][y] + 1) {
                dis[x][i] = dis[x][y] + 1;
                qx[++tx] = x;
                qy[++ty] = i;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (dis[i][y] > dis[x][y] + 1) {
                dis[i][y] = dis[x][y] + 1;
                qx[++tx] = i;
                qy[++ty] = y;
            }
        }
    }
    printf("%d\n", (dis[r][c] == 1000000)? -1 : dis[r][c]);
}

int main() {
	int T; read(T);
	while (T--) {
        solve();
	}
	return 0;
}