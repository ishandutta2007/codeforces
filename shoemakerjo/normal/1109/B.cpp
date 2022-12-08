#include <bits/stdc++.h>

using namespace std;

int n;
string s;

set<int> vs;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	n = s.length();
	for (int i = 0; i < n/2; i++) {
		vs.insert(s[i]-'a');
	}
	if (vs.size() < 2) {
		cout << "Impossible" << endl;
		return 0;
	}

	for (int i = 1; i < n; i++) {
		string ot = s.substr(i) + s.substr(0, i);

		// cout << "ot: " << ot << endl;

		if (ot == s) continue;

		bool ok = true;
		for (int j = 0; j < n; j++) {
			if (ot[j] != ot[n-j-1]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << 1 << endl;
			return 0;
		}
	}
	cout << 2 << endl;
}