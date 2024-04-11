#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 505;
const int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int n, m;
char s[N][N];
int bel[N][N], tot, col[N * N], ans[N][N];
vector<int> adj[N * N];

void insedge(int u, int v) { adj[u].push_back(v), adj[v].push_back(u); }

void dfs(int x, int y) {
	if(s[x][y] != '.' || bel[x][y]) return;
	bel[x][y] = tot;
	for(int i = 0; i < 8; i++) dfs(x + dx[i], y + dy[i]);
}

void GetCol(int u, int c) {
	if(col[u] != -1) return;
	col[u] = c;
	for(int i = 0; i < adj[u].size(); i++) GetCol(adj[u][i], c ^ 1);
}

int main() {
	n = get(), m = get();
	for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(s[i][j] == 'X') {
				int cnt = 0;
				for(int k = 0; k < 4; k++) cnt += s[i + dx[k]][j + dy[k]] == '.';
				if(cnt & 1) return printf("NO\n"), 0;
			}
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= m; j++)
			if(s[i][j] == '.' && !bel[i][j]) ++tot, dfs(i, j);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(s[i][j] == 'X') {
				if(s[i][j - 1] == '.' && s[i][j + 1] == '.') 
					if(bel[i][j - 1] != bel[i][j + 1]) insedge(bel[i][j - 1], bel[i][j + 1]); 
				if(s[i - 1][j] == '.' && s[i + 1][j] == '.') 
					if(bel[i - 1][j] != bel[i + 1][j]) insedge(bel[i - 1][j], bel[i + 1][j]); 
			}
	memset(col, -1, sizeof(col));
	GetCol(1, 0);
	for(int j = 1; j <= m; j++) {
		int lst = col[bel[1][j]], now = (j & 1)? 1 : 4;
		ans[1][j] = now;
		for(int i = 2; i <= n; i++) {
			if(s[i][j] != '.') continue;
			if(col[bel[i][j]] != lst) now = 5 - now;
			lst = col[bel[i][j]], ans[i][j] = now;
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(s[i][j] == 'X') {
				for(int k = 0; k < 4; k++)
					ans[i][j] += (s[i + dx[k]][j + dy[k]] == '.') * ans[i + dx[k]][j + dy[k]];
			}
	printf("YES\n");
	for(int i = 1; i <= n; i++, printf("\n"))
		for(int j = 1; j <= m; j++)
			printf("%d ", ans[i][j]);
	return 0;
}