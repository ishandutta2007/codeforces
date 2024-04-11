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
		int n, x;
		scanf("%d%d", &n, &x);
		vector<int> a(n);
		rep(i, 0, n - 1) scanf("%d", &a[i]);
		vector<LL> t(n + 1, -5e18);
		t[0] = 0;
		rep(i, 0, n - 1) {
			LL sum = 0;
			rep(j, i, n - 1) {
				sum += a[j];
				t[j - i + 1] = max(t[j - i + 1], sum);
			}
		}
		per(i, n - 1, 0) {
			t[i] = max(t[i + 1], t[i]);
		}
		rep(i, 0, n) {
			t[i] += 1LL * i * x;
		}
		rep(i, 1, n) t[i] = max(t[i - 1], t[i]);
		rep(i, 0, n) printf("%lld ", t[i]);
		puts("");
	}
}