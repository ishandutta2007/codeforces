#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ct = 0;
	map<int, int> first;
	first[0] = -1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') ct++;
		else ct--;
		if (first.count(ct) > 0) {
			ans = max(ans, i-first[ct]);
		}
		else first[ct] = i;
	}
	cout << ans << endl;
	// cin >> n;
}