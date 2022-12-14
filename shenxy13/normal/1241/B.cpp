#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string s, t;
		cin >> s >> t;
		if (s.length() == 1) {
			if (s == t) cout << "YES\n";
			else cout << "NO\n";
			continue;
		}
		bool sp[s.length()][26], tp[t.length()][26], update = true;
		for (int j = 0; j < s.length(); ++j) {
			for (int k = 0; k < 26; ++k) sp[j][k] = tp[j][k] = false;
			sp[j][s[j] - 'a'] = tp[j][t[j] - 'a'] = true;
		}
		while (update) {
			update = false;
			for (int j = 0; j < 26; ++j) {
				if (!sp[0][j] && sp[1][j]) {
					update = true;
					sp[0][j] = true;
				}
				for (int k = 1; k < s.length() - 1; ++k) {
					if (!sp[k][j] && (sp[k - 1][j] || sp[k + 1][j])) {
						update = true;
						sp[k][j] = true;
					}
				}
				if (!sp[s.length() - 1][j] && sp[s.length() - 2][j]) {
					update = true;
					sp[s.length() - 1][j] = true;
				}
			}
		}
		update = true;
		while (update) {
			update = false;
			for (int j = 0; j < 26; ++j) {
				if (!tp[0][j] && tp[1][j]) {
					update = true;
					tp[0][j] = true;
				}
				for (int k = 1; k < t.length() - 1; ++k) {
					if (!tp[k][j] && (tp[k - 1][j] || tp[k + 1][j])) {
						update = true;
						tp[k][j] = true;
					}
				}
				if (!tp[t.length() - 1][j] && tp[t.length() - 2][j]) {
					update = true;
					tp[t.length() - 1][j] = true;
				}
			}
		}
		for (int j = 0; j < s.length(); ++j) {
			for (int k = 0; k < 26; ++k) {
				if (sp[j][k] == true && tp[j][k] == true) goto hell;
			}
			cout << "NO\n";
			goto school;
			hell:;
		}
		cout << "YES\n";
		school:;
	}
	return 0;
}