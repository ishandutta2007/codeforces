#include <bits/stdc++.h>
using namespace std;
#define N 100100

typedef long long LL;

const LL inf = 1ll << 60;

int n, m, a, b, c, prv[N], prt[N];
LL d[N];
vector <int> v[N], w[N];
priority_queue < pair <LL, int> > pq;

void dijkstra() {
	for (int i = 2; i <= n; i ++) d[i] = inf;
	pq.push(make_pair(-d[1], 1));
	while (!pq.empty()) {
		int x = pq.top().second;
		LL z = -pq.top().first;
		pq.pop();
		if (d[x] != z) continue;
		for (int i = 0; i < v[x].size(); i ++) {
			int y = v[x][i];
			if (d[y] > z + w[x][i]) {
				d[y] = z + w[x][i], prv[y] = x;
				pq.push(make_pair(-d[y], y));
			}
		}
	}
}

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d", &n, &m);
	while (m --) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(b), w[a].push_back(c);
		v[b].push_back(a), w[b].push_back(c);
	}
	dijkstra();
	if (d[n] == inf) {
		puts("-1"); return 0;
	}
	int cnt = 0, x = n;
	while (x) {
		prt[cnt++] = x;
		x = prv[x];
	}
	reverse(prt, prt + cnt);
	for (int i = 0; i < cnt; i ++) printf("%d ", prt[i]);
	puts("");
	return 0;
}