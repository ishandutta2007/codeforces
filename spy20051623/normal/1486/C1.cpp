#include <bits/stdc++.h>
using namespace std;
int in;

void op(int l, int r) {
	cout << '?' << ' ' << l << ' ' << r << endl;
	fflush(stdout);
	cin >> in;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, l, r, tmp, mid;
	cin >> n;
	l = 1;
	r = n;
	while (r - l > 1) {
		mid = (l + r) / 2;
		op(l, r);
		tmp = in;
		if (tmp < mid) {
			op(l, mid);
			if (in == tmp) {
				r = mid;
			} else {
				l = mid + 1;
			}
		} else {
			op(mid, r);
			if (in == tmp) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
	}
	if (r > l) {
		op(l, r);
		if (in == l) {
			cout << "! " << r << endl;
			fflush(stdout);
		} else {
			cout << "! " << l << endl;
			fflush(stdout);
		}
	} else {
		cout << "! " << l << endl;
		fflush(stdout);
	}
	return 0;
}