#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}
typedef long long ll;
const ll mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i ++) cin >> a[i];
		int mx = *max_element(a.begin(), a.end());
		int mn = *min_element(a.begin(), a.end());

		if (mn != 1 or count(a.begin(), a.end(), 1) != 1) cout << "NO" << "\n";
		else if (mx > n) cout << "NO" << "\n";
		else {
			bool ok = true;
			for (int i = 0; i < n; i ++) {
				int j = (i + 1) % n;
				if (a[j] > a[i] && a[j] != a[i] + 1) ok = false;

			}
			cout << (ok?"YES":"NO") << "\n";
		}
	}
}

/*
1 2 3 4 5 6

*/