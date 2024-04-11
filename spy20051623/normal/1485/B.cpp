#include <bits/stdc++.h>
using namespace std;
int a[100005];

int main() {
//	freopen("in.txt", "r", stdin);
	int n, q, k, l, r, lt, rt, i, j, sum;
	cin >> n >> q >> k;
	for (i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	while (q--) {
		cin >> l >> r;
		sum = k + 1 + a[r] - a[l] - 2 * (r - l + 1);
		cout << sum << endl;
	}
	return 0;
}