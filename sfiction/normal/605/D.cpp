#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 1E5 + 10;
const int INF = 1E9 + 10;

int n;
int a[MAXN][4];
int d[MAXN];
int dis[MAXN], pre[MAXN];

vector<int> lst[MAXN];
int val[MAXN << 2];

int choose(int l, int r){
	return a[lst[l].back()][1] < a[lst[r].back()][1] ? l : r;
}

void build(int u, int l, int r){
	if (l + 1 == r){
		val[u] = l;
		return;
	}
	int m = l + r >> 1;
	build(u << 1, l, m);
	build(u << 1 | 1, m, r);
	val[u] = choose(val[u << 1], val[u << 1 | 1]);
}

int query(int u, int l, int r, int c){
	if (r <= c)
		return val[u];

	int m = l + r >> 1, ret = query(u << 1, l, m, c);
	if (m < c)
		ret = choose(ret, query(u << 1 | 1, m, r, c));

	return ret;
}

void update(int u, int l, int r, int c){
	if (l + 1 == r)
		return;
	int m = l + r >> 1;
	if (c < m)
		update(u << 1, l, m, c);
	else
		update(u << 1 | 1, m, r, c);
	val[u] = choose(val[u << 1], val[u << 1 | 1]);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
		d[i] = a[i][0];
	}
	sort(d, d + n);
	int m = unique(d, d + n) - d;
	for (int i = 0; i < n; ++i)
		lst[lower_bound(d, d + m, a[i][0]) - d].push_back(i);
	a[n][1] = INF;
	a[n][2] = a[n][3] = 0;
	for (int i = 0; i < m; ++i){
		lst[i].push_back(n);
		sort(lst[i].begin(), lst[i].end(), [](const int &l, const int &r){return a[l][1] > a[r][1];});
	}
	build(1, 0, m);

	queue<int> Q;
	dis[n] = 0;
	for (int i = 0; i <= n; ++i)
		pre[i] = -1;
	Q.push(n);
	while (!Q.empty() && !~pre[n - 1]){
		int u = Q.front();
		Q.pop();

		int v, r = upper_bound(d, d + m, a[u][2]) - d;
		while (r && a[lst[v = query(1, 0, m, r)].back()][1] <= a[u][3]){
			dis[lst[v].back()] = dis[u] + 1;
			pre[lst[v].back()] = u;
			Q.push(lst[v].back());
			lst[v].pop_back();
			update(1, 0, m, v);
		}
	}
	if (~pre[n - 1]){
		printf("%d\n", dis[n - 1]);
		vector<int> ans;
		for (int p = n - 1; p < n; p = pre[p])
			ans.push_back(p + 1);
		for (int i = ans.size() - 1; i >= 0; --i)
			printf("%d%c", ans[i], "\n "[!!i]);
	}
	else
		puts("-1");
	return 0;
}