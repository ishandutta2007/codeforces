#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	int n;
	string s;
	while (T--) {
		cin >> n >> s;
		bool ok = true;
		for (int i = 0; i < n; i++) {
			int diff = s[i] - s[n-i-1];
			diff = abs(diff);
			ok = ok && (diff == 2 || diff == 0);
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}