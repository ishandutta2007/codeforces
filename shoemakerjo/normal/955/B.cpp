#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int ct[26];
	fill(ct, ct+26, 0);
	for (int i = 0; i < s.length(); i++) {
		ct[s[i]-'a']++;
	}
	int sing = 0;
	int dub = 0;
	for (int i = 0; i < 26; i++) {
		if (ct[i] > 1) dub++;
		else if (ct[i] == 1) sing++;
	}
	if (dub + sing > 4 || dub + sing <= 1) {
		cout << "No" << endl;
		return 0;
	}
	if (dub + sing == 4) {
		cout << "Yes" << endl;
	}
	else { //does not sum to 4, 1 must split
		if (dub + sing == 3) {
			if (dub >= 1) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else {
			if (dub >= 2) {
				cout << "Yes" << endl;

			}
			else cout << "No" << endl;
		}

	}

	cin >> s;
}