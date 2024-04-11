#include <bits/stdc++.h>

using namespace std;

int main() {
	int m;
	cin >> m;
	int s[m];
	for (int i = 0; i < m; i++) {
		cin >> s[i];

	}
	bool ok = true;
	int low = s[0];
	for (int i = 1; i < m; i++) {
		if (s[i]%low != 0) {
			ok = false;
		}
	}
	if (!ok) {
		cout << -1 << endl;
	}
	else {
		cout << 2*m << endl;
		for (int i = 0; i < m; i++) {
			if (i > 0) cout << " ";
			cout << low;
			cout << " " << s[i];
		}
		cout << endl;
	}
	// cin >> m;
}