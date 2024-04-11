#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string s;
string e = "RBYG";
int main() {
	cin >> s;
	int n = s.size();
	vector<int> p(4);
	for (int i = 0; i < 4; i++) p[i] = i;
	do {
		string t;
		for (int i = 0; i < n; i++) t += e[p[i % 4]];
		bool ok = true;
		for (int j = 0; j < n; j++) {
			if (s[j] != '!' && s[j] != t[j]) ok = false;
		}
		if (ok) {
			int c[4] = { 0 };
			for (int j = 0; j < n; j++) {
				if (s[j] == '!') {
					if (t[j] == 'R') c[0]++;
					if (t[j] == 'B') c[1]++;
					if (t[j] == 'Y') c[2]++;
					if (t[j] == 'G') c[3]++;
				}
			}
			cout << c[0] << ' ' << c[1] << ' ' << c[2] << ' ' << c[3] << endl;
			break;
		}
	} while (next_permutation(p.begin(), p.end()));
	return 0;
}