#include <bits/stdc++.h>
using namespace std;

int tcnt[26], cnt[26], bcnt;

int main() {
	string s, t;
	cin >> s >> t;
	if(s.size() < t.size()) {
		cout << "0\n";
		return 0;
	}
	for(auto c : t)
		tcnt[c - 'a']++;
	int k = t.size(), n = s.size(), ans = 0;
	for(int i = 0; i < k; i++)
		if(s[i] != '?') cnt[s[i] - 'a']++;
	for(int i = 0; i + k <= n; i++) {
		for(int j = 0; j < 26; j++) {
			if(cnt[j] > tcnt[j])
				break;
			if(j == 25)
				ans++;
		}
		if(s[i] != '?')
			cnt[s[i] - 'a']--;
		if(i + k < n && s[i + k] != '?')
			cnt[s[i + k] - 'a']++;
	}
	cout << ans << '\n';
}