#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 3e5 + 30;
 
int n, m;
int a[N], f[N], q[N], vis[N];
vector<int> g[N], ans;
 
int getf(int u) {
	if(u == f[u])return u;
	return f[u] = getf(f[u]);
}
 
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			vis[i] = -1, f[i] = i, g[i].clear();
		for(int i = 1; i <= m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			g[x].push_back(y), g[y].push_back(x);
			int u = getf(x), v = getf(y);
			if(u != v)f[u] = v;
		}
		int bo = 1;
		for(int i = 1; i <= n; i++)
			if(getf(i) != getf(1))bo = 0;
		if(!bo) {
			puts("NO");
			continue;
		}
		int h = 0, l = 0;
		q[++l] = 1;
		vis[1] = 0;
		ans.clear();
		while(h < l) {
			int x = q[++h];
			if(vis[x] == 1)continue;
			ans.push_back(x);
			for(int i = 0; i < g[x].size(); i++) {
				int y = g[x][i];
				if(vis[y] == 1)continue;
				else {
					vis[y] = 1;
					for(int j = 0; j < g[y].size(); j++) {
						int z = g[y][j];
						if(vis[z] == -1) {
							vis[z] = 2;
							q[++l] = z;
						}
					}
				}
			}
		}
		puts("YES");
		printf("%d\n", ans.size());
		for(int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i]);
		puts("");
	}
}