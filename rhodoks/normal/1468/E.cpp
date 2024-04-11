#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int a[4];
		for (int i = 0; i < 4; ++i) cin >> a[i];
		sort(a, a + 4);
		int ans = a[0] * a[2];
		cout << ans <<'\n';
	}
	return 0;
}