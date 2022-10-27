#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;

		string s[2];
		cin >> s[0] >> s[1];

		bool ok = 1;
		if (s[0][0] == '1' || s[1][n-1] == '1')
			ok = 0;
		else {
			for (int i = 0; i < n; i ++)
				if (s[0][i] == '1' && s[1][i] == '1')
					ok = 0;
		}
		cout << (ok?"YES":"NO") << "\n";
	}
}