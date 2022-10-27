#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
bool ok(int x) {
	int y = max((int)sqrt(x) - 2, 0);
	while (y * y < x) ++ y;
	return y * y == x;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t --) {
		int n; cin >> n;
		if (n % 4 == 0) {
			int x = n / 4;
			if (ok(x)) {
				cout << "YES" << endl; continue;
			}
		}
		if (n % 2 == 0) {
			int x = n / 2;
			if (ok(x)) {
				cout << "YES" << endl; continue;
			}
		}
		cout << "NO" << endl;
	}
}