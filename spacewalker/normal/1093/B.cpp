#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		set<char> apps;
		for (char c : s) apps.insert(c);
		if (apps.size() == 1) cout << "-1\n";
		else {
			sort(s.begin(), s.end());
			cout << s << "\n";
		}
	}
	return 0;
}