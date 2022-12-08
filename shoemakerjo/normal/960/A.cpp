#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ac = 0;
	int bc = 0;
	int cc = 0;
	int mode = 1;
	string s;
	cin >> s;
	int n = s.length();
	bool ok = true;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') {
			if (mode != 1) ok = false;
			ac++;
		}
		else if (s[i] == 'b') {
			if (mode == 3) ok = false;
			mode = 2;
			bc++;
		}
		else if (s[i] == 'c') {
			mode = 3;
			cc++;
		}
		else ok = false;
	}
	if (ac == 0 || bc == 0) ok = false;
	if (cc != ac && cc != bc) ok = false;
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	cin >> ac;
}