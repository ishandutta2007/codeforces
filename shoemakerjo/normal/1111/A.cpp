#include <bits/stdc++.h>

using namespace std;

string s, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> t;
	if (s.length() != t.length()) {
		cout << "No" << endl;
		return 0;
	}
	for (int i = 0; i < s.length(); i++) {
		bool a1 = s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u';
		bool a2 = t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u';
		if (a1 != a2) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout<< "Yes" << endl;
}