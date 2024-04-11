#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> a;

bool isSorted(int l, int r) {
	for (int i = l; i < r - 1; i++) {
		if (a[i] > a[i + 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int k;
	cin >> k;
	int n = log2(k);
	a.resize(1 << n);
	for (int i = 0; i < 1 << n; i++) {
		cin >> a[i];
	}
	int len = 0;
	if (isSorted(0, 1 << n)) {
		cout << (1 << n) << "\n";
		return 0;
	}
	//cout << n << "\n";
	for (int mask = 0; mask < (1 << n); mask++) {
		int l = 0, r = 1 << n;
		for (int i = 0; i < n; i++) {
			int mid = (l + r) / 2;
			if (mask & (1 << i)) {
				l = mid;
			} else {
				r = mid;
			}
			if (isSorted(l, r)) {
				if (len < n - i - 1) {
					len = n - i - 1;
					//cout << i << " " << l << " " << r << "\n";
				}
				break;
			}
		}
	}
	cout << (1 << len);
}