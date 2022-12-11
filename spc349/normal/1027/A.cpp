#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		string s; cin >> s;
		for (int i = 0; i < n - i - 1; i++) {
			if (abs(s[i] - s[n - i - 1]) != 2 && s[i] != s[n - i - 1]) {
				cout << "NO" << endl;
				goto END;
			}
		}
		cout << "YES" << endl;
		END:;
	}
	return 0;
}