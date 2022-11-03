#include <cstdio>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 2E2 + 10;

int n, m;
vector<PII> E[MAXN];
int e[MAXN * MAXN][3];
int vis[MAXN];
int mark[MAXN * MAXN];

vector<PII> a, b;
vector<PII> ans;
int anscnt;

bool DFS(int u, int pre){
	vis[u] = true;
	for (int v, i = 0; i < E[u].size(); ++i){
		if (mark[E[u][i].nd])
			continue;
		if ((v = E[u][i].st) == pre)
			continue;

		a.push_back(PII(u, E[u][i].nd));
		if (vis[v]){
			int j = 0;
			for (; a[j].st != v; ++j);
			b = vector<PII>(a.begin() + j, a.end());
			return true;
		}
		else if (DFS(v, u))
			return true;
		a.pop_back();
	}
	return false;
}

void DFS2(int u, int pre){
	vis[u] = true;
	int cnt = 0;
	for (int i = 0; i < E[u].size(); ++i)
		cnt += !mark[E[u][i].nd] && !vis[E[u][i].st];
	anscnt += !(cnt + pre & 1);
	cnt += pre;
	cnt >>= 1;
	for (int v, i = 0; i < E[u].size(); ++i){
		if (mark[E[u][i].nd] || vis[v = E[u][i].st])
			continue;

		ans.push_back(cnt ? PII(u, v) : PII(v, u));
		DFS2(v, cnt ? 1 : -1);
		cnt -= !!cnt;
	}
}

int main(){
	int cas;
	scanf("%d", &cas);
	while (cas--){
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)
			E[i].clear();
		for (int u, v, i = 0; i < m; ++i){
			scanf("%d%d", &u, &v);
			e[i][0] = u, e[i][1] = v;
			e[i][2] = u ^ v;
			mark[i] = false;
			E[u].push_back(PII(v, i));
			E[v].push_back(PII(u, i));
		}

		anscnt = 0;
		ans.clear();
		while (true){
			fill_n(vis + 1, n, 0);
			bool flag = true;
			for (int i = 1; i <= n; ++i)
				if (!vis[i]){
					if (DFS(i, 0)){
						for (int j = 0; j < b.size(); ++j){
							ans.push_back(PII(b[j].st, e[b[j].nd][2] ^ b[j].st));
							mark[b[j].nd] = true;
//							printf("%d %d\n", ans.back().st, ans.back().nd);
						}
						a.clear();
						b.clear();
						flag = false;
						break;
					}
				}
			if (flag)
				break;
		}

		fill_n(vis + 1, n, 0);
		for (int i = 1; i <= n; ++i)
			if (!vis[i])
				DFS2(i, 0);

		printf("%d\n", anscnt);
		for (int i = 0; i < m; ++i)
			printf("%d %d\n", ans[i].st, ans[i].nd);
	}
	return 0;
}