#include <cassert>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2E5 + 10, MAXM = 2E5 + 10;

int n, m;
int w[MAXM], c[MAXM];
int e[MAXM][2];
bool mark[MAXM];

int a[MAXM];

int fa[MAXN];
int dep[MAXN], edge[MAXN];

int find(int x){
	return fa[x] < 0 ? x : find(fa[x]);
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
		scanf("%d", w + i);
	for (int i = 0; i < m; ++i)
		scanf("%d", c + i);
	for (int i = 0; i < m; ++i)
		scanf("%d%d", e[i], e[i] + 1);
	int S;
	scanf("%d", &S);

	for (int i = 0; i < m; ++i)
		a[i] = i;
	sort(a, a + m, [](const int &l, const int &r){return w[l] < w[r] || w[l] == w[r] && l < r;});
	fill_n(fa + 1, n, -1);
	fill_n(dep + 1, n, 0);

	ll sum0 = 0;
	int val = 1 << 30;
	int tot = n;
	for (int i = 0; i < m; ++i){
		int u = find(e[a[i]][0]), v = find(e[a[i]][1]);
		if (u != v){
			if (fa[u] > fa[v])
				swap(u, v);
			fa[u] += fa[v];
			fa[v] = u;

			--tot;

			sum0 += w[a[i]], val = min(val, c[a[i]]);
			dep[u] = max(dep[u], dep[v] + 1);
			edge[v] = a[i];
			mark[a[i]] = true;
		}
	}
	assert(tot == 1);

	int val0 = val;
	ll ans = sum0 - S / val;
	int p1 = -1, p2 = -1;
	for (int i = 0; i < m; ++i){
		if (c[i] >= val0)
			continue;

		int u = e[i][0], v = e[i][1];
		int t = -1;
		while (u != v){
			if (dep[u] > dep[v])
				swap(u, v);
			if (t == -1 || w[t] < w[edge[u]] || w[t] == w[edge[u]] && t < edge[u])
				t = edge[u];
			u = fa[u];
		}

		if (ans > sum0 - w[t] + w[i] - S / c[i]){
			ans = sum0 - w[t] + w[i] - S / c[i];
			val = c[i];
			p1 = t, p2 = i;
		}
	}

	printf("%lld\n", ans);
	if (~p1)
		mark[p1] = false, mark[p2] = true;
	for (int i = 0; i < m; ++i)
		if (mark[i] && val == c[i]){
			printf("%d %d\n", i + 1, w[i] - S / c[i]);
			mark[i] = false;
			break;
		}

	for (int i = 0; i < m; ++i)
		if (mark[a[i]])
			printf("%d %d\n", a[i] + 1, w[a[i]]);

	return 0;
}