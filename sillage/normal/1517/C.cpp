#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;
const int dx[2] = {0, 1};
const int dy[2] = {-1, 0};
int n, a[maxn], vis[maxn][maxn], tot = 0;
void dfs(int nx, int ny, int top){
	if (tot == top) return;
	for (int i = 0; i <= 1; i++){
		int x = nx + dx[i];
		int y = ny + dy[i];
		if (tot == top || x <= 0 || y <= 0 || x > n || y > n || vis[x][y]) continue;
		vis[x][y]= top;
		tot++;
		dfs(x, y, top);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		vis[i][i] = a[i];
		tot = 1;
		dfs(i, i, a[i]);
		if (tot < a[i]){
			puts("-1");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) cout << vis[i][j] << ' ';
		puts("");
	}
}