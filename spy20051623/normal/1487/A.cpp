#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i, a, minm, cnt;
	cin >> t;
	while (t--) {
		minm = 0x3f3f3f3f;
		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> a;
			if (a < minm) {
				minm = a;
				cnt = 1;
			} else if (a == minm) {
				++cnt;
			}
		}
		cout << n - cnt << endl;
	}
	return 0;
}