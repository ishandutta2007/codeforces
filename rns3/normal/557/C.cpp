#include <bits/stdc++.h>
using namespace std;

#define N 100010

typedef pair <int, int> pii;

pii leg[N];

int n, rlt = 0, j, k, total = 0, now, h, vis[301];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &leg[i].first);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &leg[i].second);
		total += leg[i].second;
	}
	sort (leg + 1, leg + n + 1);
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n;) {
		j = i + 1;
		now = leg[i].second;
		while (j <= n && leg[j].first == leg[i].first) {
			now += leg[j].second;
			j ++;
		}
		k = min(j - i - 1, i - 1);
		h = 200;
		while (1) {
			if (vis[h] < k) {
				now += h * vis[h];
				k -= vis[h];
				h --;
			}
			else {
				now += h * k;
				break;
			}
		}
		rlt = max(rlt, now);
		for (int t = i; t < j; t ++) vis[leg[t].second] ++;
		i = j;
	}
	printf("%d\n", total - rlt);
	return 0;
}