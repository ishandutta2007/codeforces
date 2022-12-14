#include <bits/stdc++.h>
using namespace std;

#define N 606

int x[N], y[N];

int n, m, k;

vector <int> v[N], u[N];

int e;

void init() {
	for (int i = 1; i <= n; i ++) v[i].clear(), u[i].clear();
	e = 0;
}

int type[N<<1];

void new_node(int x) {
	type[++e] = x;
}

int prv[N];
bool vis[N];

bool bpm(int xx) {
	int x = type[xx];
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (vis[y]) continue;
		vis[y] = 1;
		if (!prv[y] || (type[prv[y]] != x && bpm(prv[y]))) {
			prv[y] = xx;
			return 1;
		}
	}
	return 0;
}

int bipartite_matching() {
	memset(prv, 0, (max(e, m) + 1) * sizeof prv[0]);
	int rlt = 0;
	for (int i = 1; i <= e; i ++) {
		memset(vis, 0, (max(e, m) + 1) * sizeof vis[0]);
		if (bpm(i)) rlt ++;
	}
	return rlt;
}

int ans[N];

int main() {
	int T;
	scanf("%d", &T);
	while (T --) {
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 1; i <= m; i ++) scanf("%d %d", &x[i], &y[i]);
		init();
		for (int i = 1; i <= m; i ++) {
			v[x[i]].push_back(i);
			v[y[i]].push_back(i);
		}
		bool flag = 1;
		for (int i = 1; i <= n; i ++) {
			if (v[i].size() > k * 2) {
				flag = 0;
				break;
			}
			int step = max(0, 2 * ((int)v[i].size() - k));
			while (step --) new_node(i);
		}//printf("%d\n", flag);
		if (flag && (bipartite_matching() < e)) flag = 0;
		if (!flag) {
			memset(ans, 0, (m + 1) * sizeof ans[0]);
		}
		else {
			//for (int i = 1; i <= m; i ++) printf("%d ", type[prv[i]]);puts("");
			int tot = 0;
			for (int i = 1; i <= m; i ++) {
				if (!prv[i]) ans[i] = ++ tot;
				else u[type[prv[i]]].push_back(i);
			}
			for (int i = 1; i <= n; i ++) if (!u[i].empty()) {
				bool tag = 0;
				for (int j = 0; j < u[i].size(); j ++) {
					if (!tag) tot ++;
					ans[u[i][j]] = tot;
					tag = !tag;
				}
			}
		}
		for (int i = 1; i <= m; i ++) printf("%d%c", ans[i], (i == m) ? '\n' : ' ');
	}

	return 0;
}