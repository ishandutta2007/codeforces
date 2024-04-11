#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int l, r, k;
		cin >> l >> r >> k;
		l--, r--;
		int len = r - l + 1;
		k %= len;
		string t = s.substr(l, len);
		for (int i = 0; i < len; i++) {
			s[(i + k) % len + l] = t[i];
		}
		//cout << s << "\n";
	}
	cout << s << "\n";
}