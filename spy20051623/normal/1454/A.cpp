#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 1; i <= n; ++i)
			cout << i % n + 1 << ' ';
		cout << endl;
	}
	return 0;
}