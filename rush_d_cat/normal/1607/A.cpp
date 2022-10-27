#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		string s, t;
		cin >> t >> s;
		map<char, int> id;
		for (int i = 0; i < 26; i ++)
			id[t[i]] = i;
		int ans = 0;

		for (int i = 1; s[i]; i ++)
			ans = ans + abs(id[s[i]] - id[s[i-1]]);
		cout << ans << "\n";
	}
}