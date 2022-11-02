#include <bits/stdc++.h>
using namespace std;
#define M 300010
typedef pair <int, int> PII;
int dt[M], ft[M], T;

vector <int> adj[M], u[M];

int n, m, chk[M], vis[M], a[M], tot, cnt, col[M], use[M];

vector <PII> v[M];

void dfs(int x) {
	dt[x] = ++T; vis[x] = 1; col[x] = cnt;
	for (int i = 0; i < adj[x].size(); i++) dfs(adj[x][i]);
	ft[x] = ++T;
}

int arr[M];

int calc(int x) {
	int res = 0; while (x) {res += arr[x]; x -= (x & -x);} return res;
}

void add(int x, int val) {
	while (x <= T) {arr[x] += val; x += (x & -x);}
}

int pa[M];

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	int x, y;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		pa[y] = x;
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if (!chk[a[i]]) chk[a[i]] = 1, tot++;
	}

	for (int i = 1; i <= n; i++) {
		if (pa[i]) continue;
		++cnt; dfs(i);
	}

	for (int i = 1; i <= n; i++) {
		v[col[i]].push_back(PII(dt[a[i]], i));
	}
	for (int i = 1; i <= cnt; i++) {
		if (v[i].size()) {
			sort(v[i].begin(), v[i].end());
			reverse(v[i].begin(), v[i].end());
			for (int j = 0; j < v[i].size(); j++) {
				int k = v[i][j].second;
				if (use[a[k]]) {
					if (calc(dt[k]) > 1) return puts("-1"), 0;
					continue;
				}
				if (calc(dt[k])) return puts("-1"), 0;
				add(dt[a[k]], 1); add(ft[a[k]] + 1, -1);
				u[i].push_back(a[k]); use[a[k]] = 1;
			}
		}
	}
	printf("%d\n", tot);
	for (int i = 1; i <= cnt; i++) {
		for (int j = 0; j < u[i].size(); j++) printf("%d\n", u[i][j]);
	}
}