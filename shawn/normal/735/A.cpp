#include <bits/stdc++.h>

using namespace std;

int read(){
	int x = 0, f = 1, c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

void write(int x) {
	if (x < 0) puts("-"), write(-x);
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int maxn = 200;

bool inq[maxn], mark[maxn], vis[maxn];

char s[maxn];

int S, E, n, k;

void bfs() {
	queue <int> Q;
	inq[S] = 1;
	mark[S] = 1;
	Q.push(S);
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
//		inq[u] = 0;
		int v = u - k;
		if (v > 0 && !vis[v]) {
			mark[v] = 1;
			if (!inq[v]) inq[v] = 1, Q.push(v);
		}
		v = u + k;
		if (v <= n && !vis[v]) {
			mark[v] = 1;
			if (!inq[v]) inq[v] = 1, Q.push(v);
		}
	}
}

int main() {
	n = read(), k = read();
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i ++) {
		if (s[i] == 'G') S = i;
		else if (s[i] == 'T') E = i;
		else if (s[i] == '#') vis[i] = 1;
	}
	bfs();
	if (mark[E]) puts("YES");
	else puts("NO");
	return 0;
}