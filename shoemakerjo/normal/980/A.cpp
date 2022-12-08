#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int numo = 0, numd = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-') numd++;
		else numo++;
	}
	if (numo == 0 || numd%numo == 0 ) cout << "YES" << endl;
	else cout << "NO" << endl;
	cin >> s;
}