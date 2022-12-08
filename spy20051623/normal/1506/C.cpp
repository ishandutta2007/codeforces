#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, i, j, k, maxm, res, cnt;
	string s1, s2;
	cin >> t;
	while (t--) {
		cin >> s1;
		cin >> s2;
		maxm = 0;
		i = 0;
		for (j = 0; j < s2.length(); ++j) {
			res = 0;
			cnt = 0;
			for (k = 0; k + i < s1.length() && k + j < s2.length(); ++k) {
				if (s1[k + i] != s2[k + j])
					cnt = 0;
				else
					++cnt;
				res = max(res, cnt);
			}
			maxm = max(maxm, res);
		}
		j = 0;
		for (i = 0; i < s1.length(); ++i) {
			res = 0;
			cnt = 0;
			for (k = 0; k + i < s1.length() && k + j < s2.length(); ++k) {
				if (s1[k + i] != s2[k + j])
					cnt = 0;
				else
					++cnt;
				res = max(res, cnt);
			}
			maxm = max(maxm, res);
		}
		cout << s1.length() + s2.length() - 2 * maxm << endl;
	}
	return 0;
}