#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int spot = 0;
	string alph = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < s.length(); i++) {
		if (spot == alph.length()) break;
		if (s[i]-'a' <= spot) {
			s[i] = alph[spot];
			spot++;
		}
	}
	if (spot == alph.length()) {
		cout << s << endl;
	}
	else cout << -1 << endl;
	cin >> s;
}