#include <bits/stdc++.h>
using namespace std;

int l(int n) {
	return (n + 3) % 4;
}

int m(int n) {
	return (n + 2) % 4;
}

int r(int n) {
	return (n + 1) % 4;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t, s[4], i, n;
	bool f;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < 4; ++i) {
			cin >> s[i];
		}
		f = true;
		for (i = 0; i < 4; ++i) {
			if (s[i] == 0) {
				if (s[l(i)] == n || s[r(i)] == n) {
					f = false;
					break;
				}
				if (s[m(i)] == 0) {
					if (s[l(i)] == n - 1 || s[r(i)] == n - 1) {
						f = false;
						break;
					}
				}
				if (s[m(i)] == 1) {
					if (s[l(i)] == n - 1 && s[r(i)] == n - 1) {
						f = false;
						break;
					}
				}
			}
			if (s[i] == n) {
				if (s[l(i)] == 0 || s[r(i)] == 0) {
					f = false;
					break;
				}
				if (s[m(i)] == n) {
					if (s[l(i)] == 1 || s[r(i)] == 1) {
						f = false;
						break;
					}
				}
				if (s[m(i)] == n - 1) {
					if (s[l(i)] == 1 && s[r(i)] == 1) {
						f = false;
						break;
					}
				}
			}
		}
		cout << (f ? "YES" : "NO") << endl;
	}
	return 0;
}