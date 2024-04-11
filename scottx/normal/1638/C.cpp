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
		int mx = 0, ans = 0;
		rep(i, 0, n - 1) {
			mx = max(mx, a[i]);
			ans += mx == i + 1;
		}
		printf("%d\n", ans);
	}
}