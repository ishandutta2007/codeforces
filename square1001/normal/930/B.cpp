#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
int n; string s;
int main() {
	cin >> s; n = s.size();
	int win = 0;
	for (int i = 0; i < 26; i++) {
		vector<string> v;
		for (int j = 0; j < n; j++) {
			if (s[j] == i + 97) {
				v.push_back(s.substr(j) + s.substr(0, j));
			}
		}
		int mx = 0;
		for (int j = 1; j < n; j++) {
			vector<int> cnt(26);
			for (int k = 0; k < v.size(); k++) {
				cnt[v[k][j] - 97]++;
			}
			int c = 0;
			for (int k = 0; k < 26; k++) {
				if (cnt[k] == 1) c++;
			}
			mx = max(mx, c);
		}
		win += mx;
	}
	cout << fixed << setprecision(15) << 1.0 * win / n << endl;
	return 0;
}