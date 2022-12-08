#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, a, b, i;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		a = -1;
		b = s.length();
		for (i = 0; i < s.length() - 1; ++i) {
			if (s[i] == '0' && s[i + 1] == '0')\
				a = i;
			if (s[i] == '1' && s[i + 1] == '1')
				b = min(b, i);
		}
		if (a > b)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}