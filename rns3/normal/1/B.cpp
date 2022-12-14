#include <bits/stdc++.h>
using namespace std;

int pw[60];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int tcase;
	for (cin >> tcase; tcase--; ) {
		string s; cin >> s;
		int flag = 0, fn[2];
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				fn[0] = i; break;
			}
		}
		for (int i = fn[0]; i < s.size(); i++) {
			if (s[i] >= 'A' && s[i] <= 'z') {
				flag = 1; fn[1] = i;
				break;
			}
		}
		if (!flag) {
			pw[0] = 1;
			for (int i = 1; i < 7; i++) pw[i] = 26 * pw[i - 1];
			cout << "R";
			int ans = 0, q = fn[0] - 1;
			for (int i = 0; i < fn[0]; i++) {
				ans += (s[i] - 'A' + 1) * pw[q - i];
			}
			for (int i = fn[0]; i < s.size(); i++) cout << s[i];
			cout << "C" << ans << endl;
		} else {
			pw[0] = 1;
			for (int i = 1; i < 7; i++) pw[i] = 10 * pw[i - 1];
			int tot = 0, q = s.size() - fn[1] - 2;
			for (int i = fn[1] + 1; i < s.size(); i++) {
				tot += (s[i] - '0') * pw[q - i + fn[1] + 1];
			}
			string ans;
			while (tot) {
				char c = ((tot % 26) ? (char)(tot % 26 + 'A' - 1) : 'Z');
				ans.push_back(c);
				tot /= 26;
                                if (c == 'Z') tot--;
			}
			reverse(ans.begin(), ans.end());
			cout << ans;
			for (int i = fn[0]; i < fn[1]; i++) cout << s[i];
			cout << endl;
		}
	}
	return 0;
}