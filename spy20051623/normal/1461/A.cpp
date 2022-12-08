#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, k, i;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (i = 0; i < n; ++i) {
			cout << (char)('a' + i % 3);
		}
		cout << endl;
	}
	return 0;
}