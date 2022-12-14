#include <bits/stdc++.h>

using namespace std;

#define mk(i, j) make_pair(i, j)
#define pii pair<int, int>
#define fi first
#define se second

int read() {
	int x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
const char output[4] = {'v', '<', '^', '>'};  
const int maxn = 2005;  

char Mp[maxn][maxn];  

queue < pii > Q;

int n, m;

void write(int x) {
	if (x < 0) putchar('-'), write(-x);
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

bool can(int x, int y) {
	return (x > 0 && y > 0 && x <= n && y <= m && Mp[x][y] == '.');
}

bool degree(int x, int y) {
	int deg = 0;
	if (!can(x, y)) return 0;
	for (int i = 0; i < 4; i ++) {
		int xx = x + dir[i][0], yy = y + dir[i][1];
		if (can(xx, yy)) deg ++;
	}
	return deg == 1;
}

void topsort() {
	while (!Q.empty()) {
		pii u = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i ++) {
			int x = u.fi + dir[i][0], y = u.se + dir[i][1];
			if (can(x, y)) {
				Mp[u.fi][u.se] = output[i];
				Mp[x][y] = output[i ^ 2];
				for (int j = 0; j < 4; j ++) {
					int xx = x + dir[j][0], yy = y + dir[j][1];
					if (degree(xx, yy)) Q.push(mk(xx, yy));
				}
				break;
			}
		}
	}
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i ++) scanf("%s", Mp[i] + 1);
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) if (degree(i, j)) Q.push(mk(i, j));
	topsort();
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) if (Mp[i][j] == '.') return puts("Not unique"), 0;
	for (int i = 1; i <= n; i ++) printf("%s\n", Mp[i] + 1);	
	return 0;
}