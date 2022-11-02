#include <vector>
#include <iostream>
using namespace std;
const int mods[5] = {
	900000011,
	900000041,
	900000053,
	900000067,
	900000083
};
int ph[1000009][5], pw[1000009][5], ch[5];
int n; string s[100009];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	int len = 0;
	for (int i = 0; i < n; ++i) cin >> s[i], len += s[i].size();
	for (int i = 0; i < 5; ++i) {
		pw[0][i] = 1;
		for (int j = 0; j < len; ++j) {
			pw[j + 1][i] = pw[j][i] * 311LL % mods[i];
		}
	}
	int cur = 0;
	string ans;
	for (int i = 0; i < n; ++i) {
		int com = 0;
		for (int j = 0; j < 5; ++j) ch[j] = 0;
		for (int j = 1; j <= s[i].size() && j <= cur; ++j) {
			for (int k = 0; k < 5; ++k) {
				ch[k] = (ch[k] * 311LL + s[i][j - 1]) % mods[k];
			}
			bool match = true;
			for (int k = 0; k < 5; ++k) {
				int lh = (ph[cur][k] - 1LL * pw[j][k] * ph[cur - j][k] % mods[k] + mods[k]) % mods[k];
				if (ch[k] != lh) {
					match = false;
					break;
				}
			}
			if (match) com = j;
		}
		for (int j = cur; j < cur + s[i].size() - com; ++j) {
			for (int k = 0; k < 5; ++k) {
				ph[j + 1][k] = (ph[j][k] * 311LL + s[i][j - cur + com]) % mods[k];
			}
		}
		cur += s[i].size() - com;
		ans += s[i].substr(com);
	}
	cout << ans << '\n';
	return 0;
}