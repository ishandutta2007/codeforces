#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

bool check(string s) {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != s[s.size() - 1 - i])
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int T = 0; T < t; ++T) {
		string s;
		cin >> s;
		if (!check(s + 'a'))
			cout << "YES\n" << s + 'a' << "\n";
		else if (!check('a' + s))
			cout << "YES\n" << 'a' + s << "\n";
		else
			cout << "NO\n";
	}
	return 0;
}