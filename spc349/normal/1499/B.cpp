#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; cin >> T;
	while (T--) {
		string s; cin >> s;
		int n = s.size();
		int pre = -1;
		for (int i = 1; i < n; i++) {
			if (s[i] == s[i - 1] && s[i] == '1') {
				pre = i - 1;
				break;
			}
		}
		if (pre == -1) {
			cout << "YES" << endl;
			continue;
		}
		int suc = -1;
		for (int i = n - 2; i >= 0; i--) {
			if (s[i] == s[i + 1] && s[i] == '0') {
				suc = i + 1;
				break;
			}
		}
		if (pre > suc) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}