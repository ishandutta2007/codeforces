#include <bits/stdc++.h>
using namespace std;

main() {
	int t, n, i, j;
	char s[1000], m[5] = {"2020"};
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> s;
		j = 0;
		for (i = 0; i < 4; ++i) {
			if (s[j] == m[i])
				++j;
			else
				break;
		}
		j = n - 4 + i;
		for (; i < 4; ++i) {
			if (s[j] == m[i])
				++j;
			else
				break;
		}
		if (i == 4)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}