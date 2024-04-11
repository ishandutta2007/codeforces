#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, c[26]; string s;
int main() {
	cin >> n >> s;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			string t = s.substr(i, j - i);
			for (int k = 0; k < 26; k++) c[k] = 0;
			bool f = true;
			for (int k = 0; k < t.size(); k++) {
				if (t[k] <= 'Z') f = false;
				else c[t[k] - 97] = 1;
			}
			if (f) {
				int res = 0;
				for (int k = 0; k < 26; k++) res += c[k];
				ret = max(ret, res);
			}
		}
	}
	cout << ret << endl;
	return 0;
}