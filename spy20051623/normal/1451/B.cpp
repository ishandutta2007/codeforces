#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, q, l, r, i;
	bool f1, f2;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> q;
		cin >> s;
		while (q--) {
			cin >> l >> r;
			--l;
			--r;
			f1 = f2 = false;
			for (i = l - 1; i >= 0; --i) {
				if (s[i] == s[l]) {
					f1 = true;
					break;
				}
			}
			for (i = r + 1; i < n; ++i) {
				if (s[i] == s[r]) {
					f2 = true;
					break;
				}
			}
			if (f1 || f2)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}