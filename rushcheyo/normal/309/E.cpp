#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int n, l[N], r[N], d[N], ans[N], cnt[N];
bool del[N];

bool check(int x) {
	r[0] = 1000000005;
	for (int i = 1; i <= n; i++) d[i] = n, del[i] = false, cnt[i] = 0;
	cnt[n] = n;
	for (int i = 1; i <= n; i++) {
		int t = i - 1;
		for (int j = i; j <= n; j++)
			if ((t += cnt[j]) >= j) {
				if (t > j) return false;
				break;
			}
		int id = 0;
		for (int j = 1; j <= n; j++) if (!del[j] && d[j] <= t && r[j] < r[id]) id = j;
		cnt[d[id]]--;
		cnt[d[id] = i]++;
		del[id] = true;
		ans[i] = id;
		for (int j = 1; j <= n; j++)
			if (r[id] >= l[j] && l[id] <= r[j]) {
				cnt[d[j]]--;
				cnt[d[j] = min(d[j], i + x)]++;
			}
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", l + i, r + i);
	int l = 0, r = n - 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	check(r);
	for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}