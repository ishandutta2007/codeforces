#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n == 1) {
		cout << ":(";
		return 0;
	}
	string s;
	cin >> s;
	if (s[0] == ')' || s.back() == '(') {
		cout << ":(";
		return 0;
	}
	int cnt = 0, open = 0, close = 0;
	for (int i = 1; i < n - 1; i++) {
		if (s[i] == '?') {
			cnt++;
		} else if (s[i] == '(') {
			open++;
		} else {
			close++;
		}
	}
	string res = s;
	res[0] = '(';
	res.back() = ')';
	int bal = 0;
	for (int i = 1; i < n - 1; i++) {
		if (s[i] == '(') {
			bal++;
			open--;
		} else if (s[i] == ')') {
			bal--;
			close--;
		}
		if (bal < 0) {
			cout << ":(";
			return 0;
		}
		if (s[i] != '?') continue;
		if (bal + open - close - cnt > 0) {
			cout << ":(";
			return 0;
		}
		if (bal + open - close - cnt == 0) {
			bal--;
			res[i] = ')';
		} else {
			bal++;
			res[i] = '(';
		}
		if (bal < 0) {
			cout << ":(";
			return 0;
		}
		cnt--;
	}
	if (bal) {
		cout << ":(";
		return 0;
	}
	cout << res << "\n";
}