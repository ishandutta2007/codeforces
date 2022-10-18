#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

bool vow(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }

int main()
{
	string s, t;

	cin >> s >> t;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (vow(s[i])) s[i] = 'v'; else s[i] = 't';
		if (vow(t[i])) t[i] = 'v'; else t[i] = 't';
	}
	if (s == t) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	cout << endl;
	exit(0);
}