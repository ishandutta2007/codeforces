#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 13E4 + 10;

vector<int> E[MAXN];
bool des[MAXN];
int dep[MAXN], m1[MAXN], m2[MAXN];

int cnt, ans, ansl;

void update(int c, int u){
	if (ansl < c)
		ansl = c, ans = u;
	else if (ansl == c && ans > u)
		ans = u;
}

void DFS1(int u, int pre){
	dep[u] = -1;
	m1[u] = m2[u] = 0;
	for (int v, i = 0; i < E[u].size(); ++i)
		if ((v = E[u][i]) != pre){
			DFS1(v, u);
			des[u] |= des[v];
			dep[u] = max(dep[u], dep[v]);
			if (dep[v] > dep[m1[u]])
				m2[u] = m1[u], m1[u] = v;
			else if (dep[v] > dep[m2[u]])
				m2[u] = v;
		}
	dep[u] += des[u];
	cnt += des[u];
}

void DFS2(int u, int pre, int up){
	update(dep[u], u);
	update(up, u);
	for (int i = 0; i < E[u].size(); ++i)
		if (E[u][i] != pre && des[E[u][i]])
			DFS2(E[u][i], u, max(up, dep[E[u][i] == m1[u] ? m2[u] : m1[u]] + 1) + 1);
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	int u;
	for (int i = 0; i < m; ++i){
		scanf("%d", &u);
		des[u] = true;
	}
	dep[0] = -1;
	DFS1(u, 0);
	ansl = -1;
	DFS2(u, 0, 0);
	printf("%d\n%d\n", ans, (cnt - 1) * 2 - ansl);
	return 0;
}