#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int k;
	cin >> k;
	if (s.length() < k) {
		cout << "impossible" << endl;
		return 0;
	}
	bool found[26];
	for (int i = 0; i < 26; i++) {
		found[i] = false;
	}
	for (int i = 0; i < s.length(); i++) {
		found[s[i]-'a'] = true;
	}
	int ct = 0;
	for (int i = 0; i < 26; i++) {
		if (found[i]) ct++;
	}
	if (ct > k) cout << 0 << endl;
	else cout << k-ct << endl;
	cin >> k;
}