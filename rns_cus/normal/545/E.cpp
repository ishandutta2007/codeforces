#include <bits/stdc++.h>
using namespace std;

#define N 300300

const long long inf = 1ll << 60;

int n, m, src, a[N], b[N], c[N];
int cnt, prt[N];
long long d[N];
vector <int> v[N], w[N], id[N];

priority_queue < pair <long long, int> > pq;

void dijkstra(int src) {
	for (int i = 1; i <= n; i ++) d[i] = inf;
	d[src] = 0;
	pq.push(make_pair(-d[src], src));
	while (!pq.empty()) {
		int x = pq.top().second;
		long long z = -pq.top().first;
		pq.pop();
		if (d[x] != z) continue;
		for (int i = 0; i < v[x].size(); i ++) {
			int y = v[x][i], ww = w[x][i];
			if (z + ww < d[y]) {
				d[y] = z + ww;
				pq.push(make_pair(-d[y], y));
			}
		}
	}
}

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		a[i] = x, b[i] = y, c[i] = z;
		v[x].push_back(y), w[x].push_back(z), id[x].push_back(i);
		v[y].push_back(x), w[y].push_back(z), id[y].push_back(i);
	}
	scanf("%d", &src);
	dijkstra(src);
	long long ans = 0;
	for (int i = 1; i <= n; i ++) if (i != src) {
		long long mn = inf;
		int num = 0;
		for (int j = 0; j < v[i].size(); j ++) {
			if (d[i] == d[v[i][j]] + w[i][j]) {
				if (mn > w[i][j]) mn = w[i][j], num = id[i][j];
			}
		}
		ans += c[num];
        prt[++cnt] = num;
	}
	printf("%I64d\n", ans);
	sort(prt + 1, prt + cnt + 1);
	for (int i = 1; i <= cnt; i ++) printf("%d%c", prt[i], i < cnt ? ' ' : '\n');
	return 0;
}