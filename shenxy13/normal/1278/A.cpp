#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		string p, h;
		cin >> p;
		cin >> h;
		int pum[26];
		fill_n(pum, 26, 0);
		for (char c: p) ++pum[c - 'a'];
		int hum[h.size() + 1][26];
		for (int j = 0; j <= h.size(); ++j) fill_n(hum[j], 26, 0);
		for (int j = 1; j <= h.size(); ++j) hum[j][h[j - 1] - 'a'] = 1;
		for (int j = 1; j <= h.size(); ++j) {
			for (int k = 0; k < 26; ++k) hum[j][k] += hum[j - 1][k];
		}
		for (int j = 0; j <= (int) h.size() - (int) p.size(); ++j) {
			bool possible = true;
			for (int k = 0; k < 26; ++k) {
				if (hum[j + p.size()][k] - hum[j][k] != pum[k]) possible = false;
			}
			if (possible) {
				cout << "YES\n";
				goto hell;
			}
		}
		cout << "NO\n";
		hell:;
	}
	return 0;
}