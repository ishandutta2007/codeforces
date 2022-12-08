#include <bits/stdc++.h>
using namespace std;
int a[100005];

void op(int x) {
	cout << "? " << x << endl;
	fflush(stdout);
	cin >> a[x];
}

int check(int i) {
	return a[i] < a[i - 1] && a[i] < a[i + 1];
}

int main() {
//	freopen("in.txt", "r", stdin);
	memset(a, 0, sizeof(a));
	int n, c = 0, l, r, mid, mid1, mid2, i;
	cin >> n;
	if (n == 1) {
		cout << "! " << 1 << endl;
		fflush(stdout);
		return 0;
	}
	op(1);
	op(2);
	if (a[1] < a[2]) {
		cout << "! " << 1 << endl;
		fflush(stdout);
		return 0;
	}
	op(n);
	op(n - 1);
	if (a[n] < a[n - 1]) {
		cout << "! " << n << endl;
		fflush(stdout);
		return 0;
	}
	l = 1;
	r = n;
	while (r - l > 3) {
		mid = (l + r) / 2;
		op(mid);
		op(mid + 1);
		if (a[mid] > a[mid + 1])
			l = mid;
		else
			r = mid + 1;
	}
	for (i = (l - 1 > 0 ? l - 1 : l); i <= r; ++i) {
		if (a[i] == 0)
			op(i);
	}
	for (i = (l > 1 ? l : l + 1); i <= (r < n ? r : r - 1); ++i) {
		if (check(i))
			break;
	}
	cout << "! " << i;
	fflush(stdout);
	return 0;
}