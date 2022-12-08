#include <bits/stdc++.h>
using namespace std;
int a[100005];

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m, x[2] = {0, 0}, i, in, p;
	cin >> n >> m;
	for (i = 1; i <= n; ++i) {
		cin >> a[i];
		++x[a[i]];
	}
	while (m--) {
		cin >> in >> p;
		if (in == 1) {
			--x[a[p]];
			++x[!a[p]];
			a[p] = !a[p];
		} else {
			if (p > x[1])
				cout << 0 << endl;
			else
				cout << 1 << endl;
		}
	}
	return 0;
}