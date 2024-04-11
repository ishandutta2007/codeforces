#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t;
	cin >> s >> t;
	int ct[26];
	fill(ct, ct+26, 0);
	int quest = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '?') quest++;
		else ct[s[i]-'a']++;
	}
	int tct[26];
	fill(tct, tct+26, 0);
	for (int i = 0; i < t.length(); i++) {
		tct[t[i]-'a']++;
	}

	int ans = 0;
	for (int i = 1; i <= 1000000; i++) {
		int cost = 0;
		for (int j = 0; j < 26; j++) {
			int need = tct[j]*i;
			cost += max(0, need-ct[j]);
		}
		if (cost <= quest) {
			ans = i;
		}
		else break;
	}
	int ext[26];
	fill(ext, ext+26, 0);
	for (int j = 0; j < 26; j++) {
		int need = tct[j]*ans;
		// if (j < 2) {
		// 	cout << j << "  " << need << "  " << ct[j] << endl;
		// }
		ext[j] = max(0, need-ct[j]);
	}

	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '?') continue;
		bool took = false;
		for (int j = 0; j < 26; j++) {
			if (ext[j] > 0) {
				s[i] = j+'a';
				ext[j]--;
				took = true;
				break;
			}
		}
		if (!took) s[i] = 'a';
	}
	// cout << "ans   " << ans << endl;
	cout << s << endl;
	cin >> ans;
}