#include <bits/stdc++.h>

using namespace std;

int a[1000];
int n;
long long h;

bool check(long long k) {
	long long st = a[0], en = st + k - 1;
	long long d = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] > en) {
			d += en - st + 1;
			st = a[i];
			en = st + k - 1;
		} else {
			en = a[i] + k - 1;
		}
		if (d >= h) return true;
	}
	d += en - st + 1;
	if (d >= h) return true;
	else return false;
}

void solve() {
	cin >> n >> h;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long l = 1, r = 1e18, ans;
	while (l <= r) {
		long long mid = (l + r) >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}