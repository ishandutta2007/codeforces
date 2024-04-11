#include<bits/stdc++.h>
using namespace std;
int val[10010], p[10010];
int dis[110][110], vis[110][110], id[110][110];
int main(){
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		int t = 0, x;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &dis[i][j]), val[++t] = dis[i][j];
		for (int i = 1; i <= t; i++) p[i] = i;
		sort(p + 1, p + 1 + t, [&](int a, int b){
			return val[a] < val[b]; 
		});
		memset(id, 0, sizeof(id));
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= m; i++){
			int row = (p[i] - 1) / m + 1, col = (p[i] - 1) % m + 1;
			id[row][i] = dis[row][col];
			vis[row][col] = 1;
		}
		for (int i = 1; i <= n; i++){
			int now = 1;
			for (int j = 1; j <= m; j++)
				if (!vis[i][j]){
					while (id[i][now] > 0) now++;
					id[i][now] = dis[i][j];
				}
		}
		for (int i = 1; i <= n; i++, puts(""))
			for (int j = 1; j <= m; j++) printf("%d ", id[i][j]);
	}
}