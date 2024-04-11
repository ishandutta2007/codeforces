#include <bits/stdc++.h>
using namespace std;
char b[100005];

main() {
	int t, n, i;
	char ch, f;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> ch;
			if (i == 0) {
				b[i] = '1';
				f = ch + 1;
				continue;
			}
			if (ch + 1 == f)
				b[i] = '0';
			else
				b[i] = '1';
			f = ch - '0' + b[i];
		}
		b[n] = '\0';
		cout << b << endl;
	}
}