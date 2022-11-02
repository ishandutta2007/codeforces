#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n; string s;
int main() {
	cin >> n >> s;
	int p = 0, d = 0;
	int ret1 = 0, ret2 = 0;
	for (int i = 0; i <= n; i++) {
		if (i == n || s[i] == '_' || s[i] == '(' || s[i] == ')') {
			string x = s.substr(p, i - p);
			if (x.size() >= 1) {
				if (d > 0) ret2++;
				else ret1 = max(ret1, (int)x.size());
			}
			p = i + 1;
		}
		if (i < n && s[i] == '(') d++;
		if (i < n && s[i] == ')') d--;
	}
	cout << ret1 << ' ' << ret2 << endl;
	return 0;
}