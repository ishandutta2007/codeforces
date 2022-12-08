#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<string, string> mp;
	string f, s;

	for (int i = 0; i < m; i++) {
		cin >> f >> s;
		if (f.length() <= s.length()) {
			mp[f] = f;
		}
		else mp[f] = s;
	}

	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cin >> f;
		cout << mp[f];
	}
	cout << endl;
	// cin >> n;
}