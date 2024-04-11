#include <bits/stdc++.h>
using namespace std;

#define N 303030

int a[N], n;

map <int, bool> mp;

pair <int, int> ans[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		int j = i;
		while (j <= n) {
			if (mp.count(a[j])) break;
			mp[a[j]] = 1;
			j ++;
		}
		if (j <= n) ans[++cnt] = make_pair(i, j);
		i = j;
		mp.clear();
	}
	if (!cnt) puts("-1");
	else {
		ans[cnt].second = n;
		printf("%d\n", cnt);
		for (int i = 1; i <= cnt; i ++) printf("%d %d\n", ans[i].first, ans[i].second);
	}

	return 0;
}