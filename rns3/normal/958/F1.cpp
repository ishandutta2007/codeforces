#include <bits/stdc++.h>

using namespace std;



#define N 101



int n, m, c[N], k[N], cnt[N];



int main() {

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i ++) scanf("%d", &c[i]);

	for (int i = 1; i <= m; i ++) scanf("%d", &k[i]);

	for (int st = 1; st <= n; st ++) for (int en = st; en <= n; en ++) {

		memset(cnt, 0, sizeof cnt);

		for (int i = st; i <= en; i ++) cnt[c[i]] ++;

		bool ok = 1;

		for (int i = 1; i <= m; i ++) if (k[i] != cnt[i]) ok = 0;

		if (ok) {

			puts("YES");

			return 0;

		}

	}

	puts("NO");



	return 0;

}