#include <bits/stdc++.h>
using namespace std;
#define N 1010

int n, m, f[N*N], col[N][N], color, vis[N*N], T, cnt;
char s[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int i, int j) {
    col[i][j] = color;
    cnt ++;
    for (int k = 0; k < 4; k ++) {
		int I = i + dx[k], J = j + dy[k];
		if (I < 0 || I >= n || J < 0 || J >= m) continue;
		if (s[I][J] == '.' && !col[I][J]) dfs(I, J);
    }
}

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++) scanf("%s", s[i]);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) if (s[i][j] == '.' && !col[i][j]) {
			cnt = 0;
			color ++;
			dfs(i, j);
			f[color] = cnt;
		}
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (s[i][j] == '.') printf("%c", s[i][j]);
			else {
				T ++;
				int ans = 0;
				for (int k = 0; k < 4; k ++) {
					int I = i + dx[k], J = j + dy[k];
					if (I < 0 || I >= n || J < 0 || J >= m) continue;
					if (s[I][J] == '.') {
                        if (vis[col[I][J]] != T) ans += f[col[I][J]];
                        vis[col[I][J]] = T;
					}
				}
				printf("%d", (ans + 1) % 10);
			}
		}
		puts("");
	}
	return 0;
}