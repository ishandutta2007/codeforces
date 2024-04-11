#include <string>
#include <iostream>
using namespace std;
string s; bool ok[5009][5009];
int main() {
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			ok[i][j] = true;
		}
	}
	for (int i = 0; i < n; ++i) {
		int delta = 0; bool curf = true;
		for (int j = i; j < n; ++j) {
			if (s[j] == ')') --delta;
			else ++delta;
			if (delta < 0) curf = false;
			if (!curf) ok[i][j + 1] = false;
		}
	}
	for (int i = 0; i < n; ++i) {
		int delta = 0; bool curf = true;
		for (int j = i; j >= 0; --j) {
			if (s[j] == '(') --delta;
			else ++delta;
			if (delta < 0) curf = false;
			if (!curf) ok[j][i + 1] = false;
		}
	}
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 2; j <= n; j += 2) {
			ret += ok[i][j];
		}
	}
	cout << ret << '\n';
	return 0;
}