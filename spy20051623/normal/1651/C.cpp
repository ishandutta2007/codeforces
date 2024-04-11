#include <bits/stdc++.h>

using namespace std;

long long a[200005], b[200005];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	long long ll = abs(a[0] - b[0]), lr = abs(a[0] - b[n - 1]), ul = 2e9, dl = 2e9;
	long long rl = abs(a[n - 1] - b[0]), rr = abs(a[n - 1] - b[n - 1]), ur = 2e9, dr = 2e9;
	for (int i = 0; i < n; ++i) {
		ul = min(ul, abs(a[0] - b[i]));
		dl = min(dl, abs(b[0] - a[i]));
		ur = min(ur, abs(a[n - 1] - b[i]));
		dr = min(dr, abs(b[n - 1] - a[i]));
	}
	long long ans = ul + ur + dl + dr;
	ans = min(ans, ll + min(rr, ur + dr));
	ans = min(ans, lr + min(rl, ur + dl));
	ans = min(ans, rl + min(lr, ul + dr));
	ans = min(ans, rr + min(ll, ul + dl));
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}