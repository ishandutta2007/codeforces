///	E : Coded by Choe Kwang

#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, m, a, b, deg[N], color, col[N], odd[N];
bool vis[N], flag[3];
int ft[N], FT, head[N], nxt[N], v[N], rhead[N], rnxt[N], rv[N], d[N];
vector <int> path[3];
map <int, int> mp;

void dfs(int x) {
	col[x] = color;
	for (int i = head[x]; i; i = nxt[i]) if (!col[v[i]]) dfs(v[i]);
	for (int i = rhead[x]; i; i = rnxt[i]) if (!col[rv[i]]) dfs(rv[i]);
}

void DFS(int x) {
	for (int i = head[x]; i; i = nxt[i]) {
		if (vis[i]) continue;
		vis[i] = 1, DFS(v[i]);
		ft[i] = ++FT;
	}
	for (int i = rhead[x]; i; i = rnxt[i]) {
		if (vis[i]) continue;
		vis[i] = 1, DFS(rv[i]);
		ft[i] = ++FT;
	}
}

int main() {
//	freopen("e.in", "r", stdin);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &m);
	if (m == 1) {
		puts("-1"); return 0;
	}
	for (int i = 1; i <= m; i ++) {
		scanf("%d %d", &a, &b);
		if (!mp[a]) mp[a] = ++n;
		if (!mp[b]) mp[b] = ++n;
		a = mp[a], b = mp[b];
		v[i] = b, nxt[i] = head[a], head[a] = i;
		rv[i] = a, rnxt[i] = rhead[b], rhead[b] = i;
		deg[a] ++, deg[b] ++;
	}
	color = 0;
	for (int i = 1; i <= n; i ++) {
		if (col[i]) continue;
		color ++, dfs(i);
	}
	if (color > 2) {
		puts("-1"); return 0;
	}
	int k = 0;
	for (int i = 1; i <= n; i ++) if (deg[i] & 1) odd[k++] = i, flag[col[i]] = 1;
	if (k > 4) {
		puts("-1"); return 0;
	}
	if (color == 2) {
		if (k == 0) {
			a = 0, b = 0;
			for (int i = 1; i <= n; i ++) {
				if (!a && col[i] == 1) a = i;
				if (!b && col[i] == 2) b = i;
			}
			odd[k++] = a, odd[k++] = b, odd[k++] = a, odd[k++] = b;
		}
		else if (k == 2) {
			for (int i = 1; i <= n; i ++) if (col[i] != col[odd[0]]) {
				odd[k++] = i, odd[k++] = i; break;
			}
			swap(odd[1], odd[2]);
		}
		else if (k == 4) {
			if (!flag[1] || !flag[2]) {
				puts("-1"); return 0;
			}
			if (col[odd[0]] == col[odd[1]]) swap(odd[1], odd[2]);
		}
	}
	for (int i = 0; i < k; i += 2) {
		a = odd[i], b = odd[i+1];
		int r = i / 2 + 1;
		v[m+r] = b, nxt[m+r] = head[a], head[a] = m + r;
		rv[m+r] = a, rnxt[m+r] = rhead[b], rhead[b] = m + r;
	}
	DFS(1);
	k = m + k / 2;

//	for (int i = 1; i <= k; i ++) printf("%d ", ft[i]); puts("");

	for (int i = 1; i <= k; i ++) d[ft[i]] = i;
	int cnt = 0;
	for (int i = 1; i <= k; i ++) {
		if (d[i] <= m) path[cnt].push_back(d[i]);
		else cnt ++;
	}
	if (cnt == 0) {
		puts("1");
		printf("%d\n", path[0][0]);
		printf("%d\n", path[0].size() - 1);
		for (int i = 1; i < path[0].size(); i ++) printf("%d ", path[0][i]); puts("");
	}
	else if (cnt == 1) {
		if (path[0].size() == 0) {
			path[0].push_back(path[1][0]);
			path[1].erase(path[1].begin());
		}
		else if (path[1].size() == 0) {
			path[1].push_back(path[0][0]);
			path[0].erase(path[0].begin());
		}
		for (int i = 0; i <= 1; i ++) {
			printf("%d\n", path[i].size());
			for (int j = 0; j < path[i].size(); j ++) printf("%d ", path[i][j]); puts("");
		}
	}
	else {
		for (int i = 0; i < path[0].size(); i ++) path[2].push_back(path[0][i]);
		if (path[1].size() == 0) {
			path[1].push_back(path[2][0]);
			path[2].erase(path[2].begin());
		}
		else if (path[2].size() == 0) {
			path[2].push_back(path[1][0]);
			path[1].erase(path[1].begin());
		}
		for (int i = 1; i <= 2; i ++) {
			printf("%d\n", path[i].size());
			for (int j = 0; j < path[i].size(); j ++) printf("%d ", path[i][j]); puts("");
		}
	}
	return 0;
}