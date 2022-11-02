#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string s; int cnt[26];
int main() {
	cin >> s;
	bool flag = false;
	for (int i = 26; i <= s.size() && !flag; i++) {
		fill(cnt, cnt + 26, false);
		for (int j = i - 26; j < i; j++) {
			if(s[j] != '?') cnt[s[j] - 65]++;
		}
		bool f = true;
		for (int j = 0; j < 26; j++) {
			if (cnt[j] >= 2) f = false;
		}
		if (!f) continue;
		for (int j = i - 26; j < i; j++) {
			if (s[j] != '?') continue;
			for (int k = 0; k < 26; k++) {
				if (cnt[k] == 0) {
					cnt[k]++;
					s[j] = k + 65;
					break;
				}
			}
		}
		flag = true;
	}
	if (!flag) cout << -1 << endl;
	else {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '?') s[i] = 'A';
		}
		cout << s << endl;
	}
	return 0;
}