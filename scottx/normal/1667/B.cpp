#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;

struct fenwick {
	int n;
	vector<int> t;
	fenwick(int n): n(n), t(n, -1e9) {}
	void add(int x, int y) {
		for (int i = x; i < n; i += i & -i) t[i] = max(t[i], y);
	}
	int ask(int x) {
		int ret = -1e9;
		for (int i = x; i > 0; i &= i - 1) ret = max(ret, t[i]);
		return ret;
	}
};

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	rep(tc, 1, T) {
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		rep(i, 0, n - 1) scanf("%d", &a[i]);
		vector<long long> sum(n + 1);
		per(i, n - 1, 0) sum[i] = sum[i + 1] + a[i];
		auto num(sum);
		sort(num.begin(), num.end()), num.erase(unique(num.begin(), num.end()), num.end());
		vector<int> key(n + 1);
		rep(i, 0, n) {
			key[i] = lower_bound(num.begin(), num.end(), sum[i]) - num.begin() + 1;
		}
		fenwick o(n + 2);
		vector<int> dp(n + 1, -1e9);
		dp[n] = 0;
		o.add(key[n], n);
		per(i, n - 1, 0) {
			dp[i] = max(dp[i], dp[i + 1] + (a[i] < 0 ? -1 : a[i] > 0 ? 1 : 0));
			dp[i] = max(dp[i], o.ask(key[i] - 1) - i);
			o.add(key[i], dp[i] + i);
		}
		printf("%d\n", dp[0]);
	}
}