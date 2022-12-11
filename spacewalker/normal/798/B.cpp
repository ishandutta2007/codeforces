#include <bits/stdc++.h>

using namespace std;

string str[50];
int sizes[50];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> str[i];
		sizes[i] = str[i].size();
	}
	int bans = 1000000000;
	for (int i = 0; i < sizes[0]; ++i) {
		// we used i shifts to get here
		int cans = i;
		// cout << "zcc " << str[0] << "\n";
		for (int j = 1; j < n; ++j) {
			bool matchFound = false;
			for (int ss = 0; ss < sizes[j]; ++ss) {
				// cout << j << " now " << str[j] << "\n";
				if (!matchFound && str[j] == str[0]) {
					// cout << "MATCH\n";
					matchFound = true;
					cans += ss;
				}
				if (sizes[j] > 1) rotate(begin(str[j]), begin(str[j]) + 1, end(str[j]));
			}
			if (!matchFound) cans = 1000000000;
		}
		bans = min(bans, cans);
		if (sizes[0] > 1) rotate(begin(str[0]), begin(str[0]) + 1, end(str[0]));
	}
	if (bans == 1000000000) cout << -1 << "\n";
	else cout << bans << "\n";
	return 0;
}