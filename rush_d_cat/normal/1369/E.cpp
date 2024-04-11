#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
struct Eege {
	int u,v,id;
} e[N];

int n, m, w[N], d[N], vis[N];
vector<int> g[N];
int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d", &e[i].u, &e[i].v); e[i].id = i;
		w[e[i].u] --, w[e[i].v] --;
		g[e[i].u].push_back(i);
		g[e[i].v].push_back(i);
	}


	queue< Eege > q;
	for (int i = 1; i <= m; i ++) {
		if (w[e[i].u] >= 0 || w[e[i].v] >= 0) {
			q.push(e[i]); vis[e[i].id] = 1;
		}
	}
	vector<int> ans;
	while (q.size()) {
		Eege now = q.front(); q.pop();
		w[now.u] ++, w[now.v] ++;
		ans.push_back(now.id);
		if (w[now.u] == 0) {
			for (auto i: g[now.u]) if (vis[i] == 0) {
				q.push(e[i]); vis[i]=1;
			}
		}
		if (w[now.v] == 0) {
			for (auto i: g[now.v]) if (vis[i] == 0) {
				q.push(e[i]); vis[i]=1;
			}
		}
	}
	if (ans.size() == m) {
		printf("ALIVE\n");
		reverse(ans.begin(), ans.end());
		for (auto x: ans) printf("%d ", x);
	} else {
		printf("DEAD\n");
	}
}