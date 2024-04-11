#include <bits/stdc++.h>
using namespace std;

void resi(string s) {
	int n = s.size();
	for (int i=0; i+5<=n; i++) {
		if (s.substr(i, 5) == "twone") {
			s[i+2] = '.';
		}
	}

	for (int i=0; i+3<=n; i++) {
		if (s.substr(i, 3) == "one") {
			s[i+1] = '.';
		}
	}

	for (int i=0; i+3<=n; i++) {
		if (s.substr(i, 3) == "two") {
			s[i+1] = '.';
		}
	}

	// cerr << "info " << s << '\n';

	int k = 0;
	for (int i=0; i<n; i++)
		if (s[i] == '.')
			k++;
	cout << k << '\n';
	for (int i=0; i<n; i++)
		if (s[i] == '.')
			cout << i+1 << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		resi(s);
	}
}

// .netw.ne.wo.neoo.ne.wooo