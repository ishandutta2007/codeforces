//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 9;
int pre[N], suf[N], a[N];
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n, k, x; cin >> n >> k >> x;
	int p = 1;
	for (int i = 0; i < k; ++i)
		p *= x;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pre[i + 1] = pre[i] | a[i];
	}
	for (int i = n - 1; ~i; --i)
		suf[i] = suf[i + 1] | a[i];
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, (p * a[i] | pre[i] | suf[i + 1]));
	}
	cout << ans << endl;
	return 0;
}