#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (a == b)
			cout << 0 << endl;
		else
			cout << (abs(a - b) - 1) / 10 + 1 << endl;
	}
	return 0;
}