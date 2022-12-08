#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, a, b, c, d;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> d;
		cout << max(a + b, c + d) << endl;
	}
	return 0;
}