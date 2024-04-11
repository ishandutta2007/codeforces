#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, i, cnt[3], m, k, r[2];
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		memset(cnt, 0, sizeof(cnt));
		for (i = 0; i < s.length(); ++i) {
			++cnt[s[i] - 'A'];
		}
		m = 0;
		for (i = 1; i < 3; ++i) {
			if (cnt[i] > cnt[m])
				m = i;
		}
		if (2 * cnt[m] != cnt[0] + cnt[1] + cnt[2])
			cout << "NO" << endl;
		else {
			if (s[0] - 'A' == m)
				k = 1;
			else
				k = 0;
			memset(r, 0, sizeof(r));
			for (i = 0; i < s.length(); ++i) {
				if (s[i] - 'A' == m)
					++r[1];
				else ++r[0];
				if (r[k] < r[!k])
					break;
			}
			if (i < s.length())
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
	}
	return 0;
}