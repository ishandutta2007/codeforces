#include <bits/stdc++.h>
using namespace std;
const int N = 3002;
vector< pair<int, int> > ans;
void down(int n, int a[]) {
	for (int i = 1; i <= n; i ++) {
		if (a[i] != i) {
			bool vis[N] = {0};
			int now = i;
			while (vis[now] == 0) {
				//printf("# %d\n", now);
				vis[now] = 1;
				now = a[now];
			}
			for (int j = 1; j <= n; j ++) if (j != i && vis[j]) {
				ans.push_back(make_pair(i, j));
				swap(a[i], a[j]);
				return;
			}
		}
	}
}
void up(int n, int a[]) {
	int pos[N];
	for (int i = 1; i <= n; i ++) {
		pos[a[i]] = i;
		//printf("%d ", a[i]);
	} //printf("\n");
	bool vis[N] = {0};
	int now = 1;
	while (vis[now] == 0) {
		//printf("# %d\n", now);
		vis[now] = 1;
		now = a[now];
	}
	//printf("------\n");
	int j = -1;
	for (int i = 1; i <= n; i ++) if (vis[i] == 0) {
		j = i; break;
	}
	//printf("j = %d\n", j);
	assert(j != -1);
	ans.push_back(make_pair(1, j));
	swap(a[1], a[j]);	
	// for (int i = 1; i <= n; i ++) printf("%d ", a[i]); printf("\n");
}
int n, m, p[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &p[i]);
	scanf("%d", &m);
	bool vis[N] = {0}; int pos[N];
	for (int i = 1; i <= n; i ++) pos[p[i]] = i;
	int sz = 0;
	for (int i = 1; i <= n; i ++) {
		if (vis[i] == 0) {
			++ sz;
			int now = i;
			while (vis[now] == 0) {
				vis[now] = 1;
				now = p[now];
			}
		}
	}
	// printf("sz = %d\n", sz);
	m = n - m;
	if (sz > m) for (int i = 1; i <= sz - m; i ++) up(n, p);
	if (sz < m) for (int i = 1; i <= m - sz; i ++) down(n, p);
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (auto x: ans) printf("%d %d ", x.first, x.second);
}
/*
1 2
2 3
3 4
4 1

3 4 2 5 1
 



*/