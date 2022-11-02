#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, h;
pair <int, int> p[N];

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d", &n, &h);
	for (int i = 1; i <= n; i ++) scanf("%d", &p[i].first), p[i].second = i;
	sort(p + 1, p + n + 1);
	int ans = p[n].first + p[n-1].first - p[1].first - p[2].first;
	int mx = max(p[n].first + p[n-1].first, p[n].first + p[1].first + h);
	int mn = min(p[1].first + p[2].first + h, p[2].first + p[3].first);
	if (ans <= mx - mn) {
		printf("%d\n", ans);
		for (int i = 1; i <= n; i ++) printf("1 "); puts("");
	}
	else {
		printf("%d\n", mx - mn);
		for (int i = 1; i <= n; i ++) printf("%d ", 1 + (i == p[1].second)); puts("");
	}
	return 0;
}