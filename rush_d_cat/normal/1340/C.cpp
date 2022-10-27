#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
int f[10002][1002];
int n, m;
int d[N];
int g, r;

struct Nod {
	int u, x;
};

void BFS() {
	for (int i = 1; i <= 10000; i ++) {
		for (int j = 0; j <= 1000; j ++) {
			f[i][j] = 1e9;
		}
	}
	f[1][g] = 0;
	deque<Nod> q;
	q.push_back((Nod){1, g});
	while (q.size()) {
		Nod p = q.front(); q.pop_front();
		int u = p.u, x = p.x;
		//printf("u=%d, x=%d, dis=%lld\n", u,x,f[u][x]);
		if (u + 1 <= m && x >= d[u+1] - d[u] && f[u+1][x-(d[u+1]-d[u])] > f[u][x]) {
			 f[u+1][x-(d[u+1]-d[u])] = f[u][x];
			 q.push_front((Nod){u+1, x-(d[u+1]-d[u])});
		}
		if (u - 1 >= 1 && x >= d[u] - d[u-1] && f[u-1][x-(d[u]-d[u-1])] > f[u][x]) {
			 f[u-1][x-(d[u]-d[u-1])] = f[u][x];
			 q.push_front((Nod){u-1, x-(d[u]-d[u-1])});
		}
		if (x == 0) {
			if (f[u][g] > f[u][x] + 1) {
				f[u][g] = f[u][x] + 1;
				q.push_back((Nod){u, g});
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		scanf("%d", &d[i]);
	}
	scanf("%d%d", &g, &r);
	sort(d + 1, d + 1 + m);
	vector<int> vec;
	vec.push_back(d[1]);
	for (int i = 2; i <= m; i ++) {
		if (d[i] != d[i-1]) {
			vec.push_back(d[i]);
		}
	}
	m = vec.size();
	for (int i = 1; i <= m; i ++) {
		d[i] = vec[i-1];
	}

	BFS();
	long long ans = 1e18;
	for (int i = 1; i <= m; i ++) {
		LL tmp = 0;
		if (d[i] != n) {
			if (f[i][g] > 1e9 - 2) continue;
			tmp = 1LL * f[i][g] * (g + r);
			if (d[i] + g >= n) {
				tmp += n - d[i];
				ans = min(ans, tmp);
			}
		} else {
			if (f[i][0] > 1e9 - 2) continue;
			tmp = 1LL * f[i][0] * (g + r) + g;
			ans = min(ans, tmp);
		}
	}
	if (ans > 1e16) return !printf("-1\n");
	printf("%lld\n", ans);
}