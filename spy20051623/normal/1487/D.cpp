#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, s;
	cin >> t;
	while (t--) {
		cin >> n;
		s = (int)sqrt(2 * n - 1);
		if (s % 2)
			cout << (s + 1) / 2 - 1 << endl;
		else
			cout << s / 2 - 1 << endl;
	}
	return 0;
}