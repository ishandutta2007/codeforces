#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 114514, inf = 0x3f3f3f3f;
int n, ans;
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot;
int f[N][3][2], tmp[3][2];

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }
void qmax(int &x, int y) { x = max(x, y); }

void dfs(int u, int lst) {
	f[u][0][0] = 0, f[u][0][1] = 1;
	f[u][1][0] = f[u][1][1] = f[u][2][0] = f[u][2][1] = -inf;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == lst) continue;
		dfs(v, u);
		memset(tmp, -0x3f, sizeof(tmp));
		qmax(tmp[0][0], f[u][0][0] + 1);
		qmax(tmp[0][1], f[u][0][1]);
		qmax(tmp[1][0], max(f[u][1][0] + 1, f[u][0][0] + max(f[v][1][0], f[v][1][1])));
		qmax(tmp[1][1], max(f[u][1][1], f[v][1][0] + 1));
		qmax(tmp[2][0], max(f[u][2][0] + 1, f[u][1][0] + max(f[v][1][0], f[v][1][1])));
		qmax(tmp[2][1], max(f[u][2][1], f[u][1][1] + f[v][1][0]));
		for(int a = 1; a < 3; a++) 
			for(int b = 0; b < 2; b++)
				qmax(tmp[a][b], tmp[a - 1][b]);
		for(int a = 0; a < 3; a++)
			for(int b = 0; b < 2; b++)
				f[u][a][b] = tmp[a][b];
	}
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 2; j++) {
			qmax(ans, f[u][i][j]);
			if(lst && !j) qmax(ans, f[u][i][j] + 1);
		}
}

int main() {
	n = get();
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}