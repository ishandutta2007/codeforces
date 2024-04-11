#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	set<string> seen;
	string cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		if (seen.find(cur) != seen.end()) {
			cout << "YES\n";
		}
		else cout << "NO\n";
		seen.insert(cur);
	}
	// cin >> n;
}