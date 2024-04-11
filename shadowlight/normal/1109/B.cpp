#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool isPal(string t) {
	int n = t.size();
	for (int i = 0; i < n; i++) {
		if (t[i] != t[n - i - 1]) {
			return false;
		}
	}
	return true;
}

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	if (s.size() % 2 == 0) {
		bool can = false;
		for (int i = 0; i < n - 1; i++) {
			if (s[i] != s[i + 1]) {
				can = true;
				break;
			}
		}
		if (!can) {
			cout << "Impossible\n";
			return;
		}
	} else {
		bool can = false;
		for (int i = 0; i < n / 2 - 1; i++) {
			if (s[i] != s[i + 1]) {
				can = true;
				break;
			}
		}
		for (int i = n / 2 + 1; i < n - 1; i++) {
			if (s[i] != s[i + 1]) {
				can = true;
				break;
			}
		}
		if (!can) {
			cout << "Impossible\n";
			return;
		}
	}
	for (int i = 0; i < n; i++) {
		string t = s.substr(i, n) + s.substr(0, i);
		if (t != s && isPal(t)) {
			cout << "1\n";
			return;
		}
	}
	cout << "2\n";
}

const ll TESTS = 1;

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	for (ll i = 0; i < TESTS; i++) {
		solve();
	}
}