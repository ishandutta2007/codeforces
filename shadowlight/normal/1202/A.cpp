#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
	string s, t;
	cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	int i = 0, j = 0;
	while (j < t.size() && t[j] == '0') j++;
	while (i < s.size() && (i < j || s[i] == '0')) i++;
	//cout << i << " " << j << "\n";
	cout << i - j << "\n";
}

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}