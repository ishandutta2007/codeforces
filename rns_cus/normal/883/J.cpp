#include <bits/stdc++.h>
using namespace std;

#define N 100100
#define M 22

int n, m, a[N], c[N];
long long sum[N], money[N];
pair <int, int> p[N];
int mx[N][M], id[N][M];
vector <int> v[N];
priority_queue <int> pq;

int main() {
//	freopen("j.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i ++) scanf("%d", &p[i].first);
	for (int i = 1; i <= m; i ++) scanf("%d", &p[i].second);
	for (int i = 1; i <= n; i ++) mx[i][0] = a[i], id[i][0] = i;
	for (int j = 1; j <= 31 - __builtin_clz(n); j ++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i ++) {
			if (mx[i][j-1] > mx[i+(1<<j-1)][j-1]) mx[i][j] = mx[i][j-1], id[i][j] = id[i][j-1];
			else mx[i][j] = mx[i+(1<<j-1)][j-1], id[i][j] = id[i+(1<<j-1)][j-1];
		}
	}
	for (int i = 1; i <= n; i ++) sum[i] = sum[i-1] + a[i];
	int cnt = 0;
	int last = 0;
	while (last < n) {
		int d = 31 - __builtin_clz(n - last);
		int x = mx[last+1][d] > mx[n-(1<<d)+1][d] ? id[last+1][d] : id[n-(1<<d)+1][d];
		c[++cnt] = a[x];
		money[cnt] = sum[x] - sum[last];
		last = x;
	}
	sort(p + 1, p + m + 1);
	for (int i = 1, j = m; i <= cnt; i ++) {
		while (j && p[j].first > c[i]) j --;
		while (j && p[j].first > c[i+1]) v[i].push_back(p[j].second), j --;
		sort(v[i].begin(), v[i].end());
	}
	long long remain = 0;
	for (int i = 1; i <= cnt; i ++) {
		remain += money[i];
		for (int j = 0; j < v[i].size(); j ++) {
			if (remain >= v[i][j]) pq.push(v[i][j]), remain -= v[i][j];
			else {
				if (!pq.empty()) {
					int x = pq.top();
					if (x <= v[i][j]) break;
					pq.pop();
					remain += x;
					pq.push(v[i][j]);
					remain -= v[i][j];
				}
			}
		}
	}
	int ans = 0;
	while (!pq.empty()) pq.pop(), ans ++;
	printf("%d\n", ans);
	return 0;
}