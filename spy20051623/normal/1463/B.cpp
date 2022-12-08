#include <bits/stdc++.h>
using namespace std;
int a[55];

int main() {
//	freopen("in.txt", "r", stdin);
	long long t, n, i, s[2], m;
	cin >> t;
	while (t--) {
		cin >> n;
		s[0] = s[1] = 0;
		for (i = 0; i < n; ++i) {
			cin >> a[i];
			s[i % 2] += a[i];
		}
		if (s[0] > s[1])
			m = 1;
		else
			m = 0;
		for (i = 0; i < n; ++i) {
			cout << (i % 2 == m ? 1 : a[i]) << ' ';
		}
		cout << endl;
	}
	return 0;
}