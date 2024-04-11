#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, z;
	cin >> n >> z;
	vector <int> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	int l = 0, r = n + 1;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (2 * mid > n) {
			r = mid;
			continue;
		}
		bool can = true;
		for (int i = 0; i < mid; i++) {
			if (x[i + n - mid] - x[i] < z) {
				can = false;
				break;
			}
		}
		if (can) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << l << "\n";
}