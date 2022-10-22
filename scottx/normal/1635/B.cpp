#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
int main() {
#ifdef local
	freopen("a.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		rep(i, 0, n - 1) scanf("%d", &a[i]);
		auto old = a;
		rep(i, 1, n - 2) if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			a[i + 1] = max(a[i], i + 2 < n ? a[i + 2] : 0);
		}
		int tot = 0;
		rep(i, 0, n - 1) if (a[i] != old[i])++ tot;
		printf("%d\n", tot);
		for (auto& x: a) printf("%d ", x);
		puts("");
	}
}