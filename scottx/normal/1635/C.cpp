#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using LL = long long;
int main() {
#ifdef local
	freopen("a.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		vector<LL> a(n);
		rep(i, 0, n - 1) scanf("%lld", &a[i]);
		if (a[n - 2] <= a[n - 1]) {
			vector<tuple<int, int, int> > ans;
			int p = n - 2;
			while (p && a[p - 1] <= a[p]) --p;
			if (!p) {
				puts("0");
				continue;
			} else if (a[n - 2] - a[n - 1] <= a[n - 2]) {
				per(i, n - 3, 0) {
					ans.emplace_back(i, n - 2, n - 1);
				}
				printf("%d\n", (int)ans.size());
				for (auto& x: ans) printf("%d %d %d\n", get<0>(x) + 1, get<1>(x) + 1, get<2>(x) + 1);
				continue;
			} else {
				puts("-1");
				continue;
			}
		} else {
			puts("-1");
			continue;
		}
	}
}