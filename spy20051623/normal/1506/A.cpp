#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	long long t, n, m, p, x, y;
	cin >> t;
	while (t--) {
		cin >> n >> m >> p;
		x = (p - 1) / n;//x
		y = (p - 1) % n + 1;//y
		cout << m*(y - 1) + x + 1 << endl;
	}
	return 0;
}