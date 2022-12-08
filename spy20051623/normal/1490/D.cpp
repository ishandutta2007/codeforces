#include <bits/stdc++.h>
using namespace std;
int a[105], rk[105];

void op(int l, int r, int n) {
	int i, maxi = l;
	for (i = l + 1; i <= r; ++i) {
		if (a[i] > a[maxi])
			maxi = i;
	}
	rk[maxi] = n;
	if (maxi > l)
		op(l, maxi - 1, n + 1);
	if (maxi < r)
		op(maxi + 1, r, n + 1);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; ++i)
			cin >> a[i];
		op(0, n - 1, 0);
		for (i = 0; i < n; ++i)
			cout << rk[i] << ' ';
		cout << endl;
	}
	return 0;
}