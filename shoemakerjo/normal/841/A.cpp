#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	string line;
	cin >> line;
	int lets[26];
	for (int i = 0; i < 26; i++) {
		lets[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		lets[line[i]-'a']++;
	}
	bool ok = true;
	for (int i = 0; i < 26; i++) {
		if (lets[i] > k) ok = false;
	}
	if (ok) cout << "YES\n";
	else cout << "NO\n";
	cin >> n;
}