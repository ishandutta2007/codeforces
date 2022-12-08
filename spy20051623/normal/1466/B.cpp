#include <bits/stdc++.h>
using namespace std;
int x[100005], d[220005];

main() {
	int t, n, i, j, flag, cnt;
	scanf("%d", &t);
	while (t--) {
		memset(x, 0, sizeof(x));
		memset(d, 0, sizeof(d));
		scanf("%d", &n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &x[i]);
			++d[x[i]];
		}
		flag = cnt = 0;
		for (i = 0; i <= n * 2 + 2; ++i) {
			if (d[i] > 1) {
				++cnt;
				flag = 1;
			} else if (d[i] == 1)
				++cnt;
			else {
				cnt += flag;
				flag = 0;
			}
		}
		printf("%d\n", cnt);
	}
}