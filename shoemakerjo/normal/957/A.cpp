#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool bad = false;
	bool poss = false;
	for (int i = 0; i < n; i++) {
		if (i > 0 && s[i] == s[i-1] && s[i] != '?') {
			bad = true;
		}
		if (s[i] != '?') continue;
		if (i == 0 || i == n-1) {
			poss = true;
			continue;
		}
		if (s[i-1] != s[i+1] && s[i-1] != '?' && s[i+1] != '?') {
			continue;
		}
		poss = true;
	}
	if (bad) poss = false;
	if (poss) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
	cin >> n;
}