#include <bits/stdc++.h>
using namespace std;

int a[110];

int main () {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		int cnt = 0;
		while (cnt < n && a[cnt] == a[0]) cnt++;
		cout << n - cnt << endl;
	}
	return 0;
}