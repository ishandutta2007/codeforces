#include <bits/stdc++.h>

using namespace std;

int a[100];

void solve() {
	int n;
	cin >> n;
	int c0 = 0, c1 = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == 0) ++c0;
		if (a[i] == 1) ++c1;
	}
	cout << (1ll << c0) * c1 << endl;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}