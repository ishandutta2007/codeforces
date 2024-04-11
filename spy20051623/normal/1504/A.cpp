#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, i, j, k;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		for (i = 0; i < s.length(); ++i) {
			if (s[i] != 'a')
				break;
		}
		if (i == s.length())
			cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			j = s.length() - i;
			for (i = 0; i < j; ++i)
				cout << s[i];
			cout << 'a';
			for (; i < s.length(); ++i)
				cout << s[i];
			cout << endl;
		}
	}
	return 0;
}