#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	long long t, p, a, b, c, minm;
	cin >> t;
	while (t--) {
		cin >> p >> a >> b >> c;
		minm = a - p % a;
		minm = min(minm, b - p % b);
		minm = min(minm, c - p % c);
		if (p % a == 0 || p % b == 0 || p % c == 0)
			minm = 0;
		cout << minm << endl;
	}
	return 0;
}