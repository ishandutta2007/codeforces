#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string ans(n + 1, '9');
	int bst = 20 * n + 34;

	vector<vector<int>> pos(10);
	for (int i = 0; i < n; i++) {
		pos[s[i] - '0'].push_back(i);
	}

	for (int c = 0; c < 10; c++) {
		string t = s;
		int need = max(0, k - (int)pos[c].size());
		int dd = 0;
		int sign = -1;
		int cur = c;
		int cur_ans = 0;
		while (need > 0) {
			dd++;
			sign = -sign;
			cur += dd * sign;

			if (cur == 20 || cur == -10) exit(11);
			if (cur < 0 || cur >= 10) continue;

			if (cur > c) {
				for (int i = 0; i < (int)pos[cur].size() && need > 0; i++) {
					t[pos[cur][i]] = char('0' + c);
					cur_ans += abs(cur - c);
					need--;
				}
			} else {
				for (int i = (int)pos[cur].size() - 1; i >= 0 && need > 0; i--) {
					t[pos[cur][i]] = char('0' + c);
					cur_ans += abs(cur - c);
					need--;
				}
			}
		}

		if (cur_ans < bst) {
			bst = cur_ans;
			ans = t;
		} else if (cur_ans == bst) {
			ans = min(ans, t);
		}
	}

	cout << bst << "\n" << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
#ifdef SERT
	int t = 1;
	for (int i = 1; i < t; i++) {
		solve();
	}
#endif
}