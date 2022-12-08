#include <bits/stdc++.h>

using namespace std;

int a[100000];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		a[i] = i;
	}
	int lim = 0;
	for (int i = 0; i < n; i += 2) {
		lim += i & i + 1;
	}
	if (k > lim) {
		cout << "-1\n";
		return;
	}
	k = lim - k;
	int kk = 0;
	if (k & 1) {
		++k;
		kk = 1;
	}
	int nn = n;
	while (nn > 1) {
		for (int i = 0; i < n; i += nn) {
			for (int j = 1; j < nn / 2; j += 2) {
				if (k >= nn / 2) {
					swap(a[i + j], a[i + j + nn / 2]);
					k -= nn / 2;
				}
			}
		}
		nn /= 2;
	}
	if (kk) {
		int x;
		for (int i = 0; i < n; ++i) {
			if (a[i] == 3) {
				x = i;
				break;
			}
		}
		swap(a[2], a[x]);
	}
	int s = 0;
	for (int i = 0; i < n; i += 2) {
		cout << a[i] << ' ' << a[i + 1] << '\n';
		s += a[i] & a[i + 1];
	}
	cerr << s << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}