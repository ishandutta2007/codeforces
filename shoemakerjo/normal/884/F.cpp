#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	int b[n];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int ans = 0;
	int swp[26];
	for (int i = 0; i < 26; i++) swp[i] = 0;
	for (int i = 0; i < n/2; i++) {
		ans += b[i] + b[n-i-1];
		if (s[i] == s[n-i-1]) {
			swp[s[i]-'a']++;
			ans -= min(b[i], b[n-i-1]);
		}
	}
	int ssum = 0;
	for (int i = 0; i < 26; i++) {
		ssum += swp[i];
	}
	for (int i = 0; i < 26; i++) {
		if (2*swp[i] > ssum) {
			// cout << "Oh no " << i << endl;
			int need = swp[i] - (ssum - swp[i]);
			// cout << "need   " << need << endl;
			vector<int> ops;
			for (int j = 0; j < n/2; j++) {
				if (s[j] -'a' == i || s[n-j-1]-'a' == i) continue;
				if (s[j] == s[n-j-1]) {
					continue;
					// if (s[j]-'a' == i) continue;
					// ops.push_back(max(b[j], b[n-j-1]));
				}
				else {
					if (s[j]-'a' != i) ops.push_back(b[j]);
					if (s[n-j-1]-'a' != i) ops.push_back(b[n-j-1]);
				}
			}
			sort(ops.begin(), ops.end());
			for (int j = 0; j < need; j++) {
				ans -= ops[j];
			}
		}
	}
	cout << ans << endl;
	cin >> ans;

}