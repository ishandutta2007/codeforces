#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
using LL = long long;
const int P = 1e9 + 7;
int main() {
#ifdef local
	freopen("a.in", "r", stdin);
#endif
	int T = 1;
	while (T--) {
		int n, p;
		scanf("%d%d", &n, &p);
		vector<LL> a;
		set<LL> S;
		rep(i, 0, n - 1) {
			LL x;
			scanf("%lld", &x);
			if (p <= 30 && x >= (1 << p)) {
				continue;
			} else {
				a.push_back(x);
			}
		}
		sort(a.begin(), a.end());
		for (auto& x: a) {
			bool err = 0;
			int tmp = x;
			while (tmp) {
				if (S.count(tmp)) {
					err = 1;
					break;
				}
				if (tmp & 1) {
					tmp >>= 1;
				} else if ((tmp & 3) == 0) {
					tmp >>= 2;
				} else {
					break;
				}
			}
			if (!err) S.insert(x);
		}
		int ans = 0;
		static int fib[200005];
		fib[0] = fib[1] = 1;
		rep(i, 2, 200004) fib[i] = (fib[i - 1] + fib[i - 2]) % P;
		rep(i, 1, 200004) fib[i] = (fib[i] + fib[i - 1]) % P;
		for (auto& x: S) {
			ans += fib[p - __lg(x) - 1];
			if (ans >= P) ans -= P;
		}
		printf("%d\n", ans);
	}
}