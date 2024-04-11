#include <bits/stdc++.h>

using namespace std;

int n, F[2000002];
string s1, s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> s1 >> s;
	reverse(s.begin(), s.end());
	for (char& c : s) {
		if (c == 'N') c = 'S';
		else if (c == 'S') c = 'N';
		else if (c == 'E') c = 'W';
		else c = 'E';
	}

	s += "#" + s1;
	int k = 0;
	for (int i = 1; i < s.size(); i++) {
		while (k && s[i] != s[k])
			k = F[k - 1];
		F[i] = (k += s[i] == s[k]);
	}
	
	return cout << (k ? "NO" : "YES") << endl, 0;
}