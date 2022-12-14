#include <bits/stdc++.h>
using namespace std;

const int L = 11;
const int K = 1 << L;

const int INF = 1e9;

#define N 1010

int n, a[K][2][N];

int main() {
	scanf("%d", &n);
	for (int k = 1, id = 0; k <= n; k <<= 1, id ++) {
		int cnt = 0;
		for (int i = 1; i <= n; i ++) if (i & k) cnt ++;
		printf("%d\n", cnt);
		for (int i = 1; i <= n; i ++) if (i & k) printf("%d ", i);
		fflush(stdout);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[id][1][i]);
		printf("%d\n", n - cnt);
		for (int i = 1; i <= n; i ++) if (!(i & k)) printf("%d ", i);
		fflush(stdout);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[id][0][i]);
	}
	puts("-1");
	for (int i = 1; i <= n; i ++) {
		int ans = INF;
		for (int k = 1, id = 0; k <= n; k <<= 1, id ++) {
			if (i & k) ans = min(ans, a[id][0][i]);
			else ans = min(ans, a[id][1][i]);
		}
		printf("%d ", ans);
	}
	fflush(stdout);

	return 0;
}