#include <bits/stdc++.h>

using namespace std;

bool pres[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	string s;
	while (t--) {
		cin >> s;
		vector<char> vc;

		for (int i = 0; i < s.length(); i++) {
			vc.push_back(s[i]);
		}

		sort(vc.begin(), vc.end());
		if (vc[0] == vc[vc.size()-1]) {
			cout << -1 << endl;
		}
		else {
			for (char c : vc) {
				cout << c;
			}
			cout << endl;
		}

	}
}