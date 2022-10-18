#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

bool isFixable(string s) {
	set<char> m(s.begin(), s.end());
	return m.size() > 1;
}

string fix(string s) {
	sort(s.begin(), s.end());
	return s;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (!isFixable(s)) {
			cout << -1 << endl;
		}
		else {
			cout << fix(s) << endl;
		}
	}
	exit(0);
}