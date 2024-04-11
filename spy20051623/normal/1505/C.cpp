#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	string s;
	cin >> s;
	for (int i = 2; i < s.length(); ++i) {
		if ((s[i - 2] - 'A' + s[i - 1] - 'A') % 26 != s[i] - 'A') {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}