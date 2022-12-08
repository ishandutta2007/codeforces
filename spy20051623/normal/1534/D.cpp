#include <bits/stdc++.h>

using namespace std;

int n;
int g[2005][2005];
int s[2005];
int d[2005];
bool vis[2005];

void ask(int p) {
	printf("? %d\n", p);
	fflush(stdout);
}

void add(int x, int y) {
	g[x][y] = 1;
}

void ans() {
	printf("!\n");
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (g[i][j]) {
				printf("%d %d\n", i, j);
				g[i][j] = g[j][i] = 0;
			}
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	vis[1] = true;
	ask(1);
	int c0 = 0, c1 = 0;
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &d[i]);
		if (d[i] == 1)
			add(1, i);
		if (i != 1) {
			if (d[i] % 2)
				++c1;
			else
				++c0;
		}
	}
	if (!c0) {
		for (int i = 2; i <= n; ++i) {
			add(1, i);
		}
		ans();
		return 0;
	}
	if (c0 < c1) {
		for (int i = 2; i <= n; ++i) {
			if (d[i] == 2) {
				q.push(i);
				vis[i] = true;
			}
		}
	} else {
		for (int i = 2; i <= n; ++i) {
			if (d[i] == 1) {
				q.push(i);
				vis[i] = true;
			}
		}
	}
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		ask(p);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &s[i]);
			if (s[i] == 1) {
				if (!vis[i]) {
					add(p, i);
				} else {
					add(i, p);
				}
			}
			if (s[i] == 2 && !vis[i]) {
				q.push(i);
				vis[i] = true;
			}
		}
	}
	ans();
	return 0;
}