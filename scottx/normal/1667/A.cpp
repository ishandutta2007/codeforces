#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	rep(i, 0, n - 1) scanf("%d", &a[i]);
	long long ret = 9e18;
	rep(i, 0, n - 1) {
		long long ans = 0;
		long long cur = 0;
		per(j, i - 1, 0) {
			ans += (-cur + a[j]) / a[j];
			cur = -((-cur + a[j]) / a[j]) * a[j];
		}
		cur = 0;
		rep(j, i + 1, n - 1) {
			ans += (cur + a[j]) / a[j];
			cur = ((cur + a[j]) / a[j]) * a[j];
		}
		ret = min(ret, ans);
	}
	cout << ret << '\n';
}