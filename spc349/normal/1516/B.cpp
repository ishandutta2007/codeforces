#include <bits/stdc++.h>
using namespace std;

int a[2010];

int main() {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n; for (int i = 0; i < n; i++) cin >> a[i];
		int sum = 0; for (int i = 0; i < n; i++) sum ^= a[i];
		if (sum == 0) {
			cout << "YES" << endl;
			continue;
		}
		int cur = 0, flag = 0;
		for (int i = 0; i < n; i++) {
			cur ^= a[i];
			if (cur == sum) {
				if (flag == 0) flag++;
			} else if (cur == 0) {
				if (flag == 1) flag++;
			}
		}
		if (flag == 2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}