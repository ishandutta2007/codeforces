#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	string s;
	scanf("%d%d", &n, &m);
	cin >> s;
	if (n % 2 && m % 2) {
		printf("-1\n");
		return;
	}
	for (int i = 0, j = s.length() - 1; i <= j; ++i, --j) {
		if (i != j) {
			if (s[i] == '?' && s[j] == '0') {
				if (n > 1) {
					n -= 2;
					s[i] = '0';
				} else {
					printf("-1\n");
					return;
				}
			} else if (s[i] == '?' && s[j] == '1') {
				if (m > 1) {
					m -= 2;
					s[i] = '1';
				} else {
					printf("-1\n");
					return;
				}
			} else if (s[i] == '0' && s[j] == '?') {
				if (n > 1) {
					n -= 2;
					s[j] = '0';
				} else {
					printf("-1\n");
					return;
				}
			} else if (s[i] == '1' && s[j] == '?') {
				if (m > 1) {
					m -= 2;
					s[j] = '1';
				} else {
					printf("-1\n");
					return;
				}
			} else if (s[i] == '1' && s[j] == '0') {
				printf("-1\n");
				return;
			} else if (s[i] == '0' && s[j] == '1') {
				printf("-1\n");
				return;
			} else if (s[i] == '0') {
				if (n > 1) {
					n -= 2;
				} else {
					printf("-1\n");
					return;
				}
			} else if (s[i] == '1') {
				if (m > 1) {
					m -= 2;
				} else {
					printf("-1\n");
					return;
				}
			}
		} else {
			if (s[i] == '0') {
				if (n) {
					--n;
				} else {
					printf("-1\n");
					return;
				}
			} else if (s[i] == '1') {
				if (m) {
					--m;
				} else {
					printf("-1\n");
					return;
				}
			}
		}
	}
	if (n % 2 && m % 2) {
		printf("-1\n");
		return;
	}
	for (int i = 0, j = s.length() - 1; i <= j; ++i, --j) {
		if (s[i] == '?') {
			if (i != j) {
				if (n > 1) {
					n -= 2;
					s[i] = s[j] = '0';
				} else {
					m -= 2;
					s[i] = s[j] = '1';
				}
			} else {
				if (n) {
					--n;
					s[i] = s[j] = '0';
				} else {
					--m;
					s[i] = s[j] = '1';
				}
			}
		}
	}
	cout << s << endl;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}