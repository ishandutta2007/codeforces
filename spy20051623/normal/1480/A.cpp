#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, flag;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		flag = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (!flag) {
				if (s[i] == 'a')
					s[i] = 'b';
				else
					s[i] = 'a';
			} else {
				if (s[i] == 'z')
					s[i] = 'y';
				else
					s[i] = 'z';
			}
			flag = !flag;
		}
		cout << s << endl;
	}
	return 0;
}