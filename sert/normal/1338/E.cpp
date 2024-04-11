#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n / 4; j++) {
			int x = ('0' <= s[j] && s[j] <= '9' ? s[j] - '0' : s[j] - 'A' + 10);
			for (int k = 3; k >= 0; k--) {
				a[i][j * 4 + k] = x % 2;
				x /= 2;
			}
		}
	}

	vector<int> deg_in(n);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) deg_in[j] += a[i][j];
	vector<bool> u(n, true);

	bool del = true;
	ll ans = 0;
	for (int del_it = 0; del; del_it++) {
		del = false;
		for (int i = 0; i < n; i++) 
			if (deg_in[i] == del_it) {
				u[i] = false;
				del = true;
				ans += (614ll * n + 1) * (n - del_it - 1);
				// cout << "del" << i << endl;
			}
	}


	int mx = max_element(deg_in.begin(), deg_in.end()) - deg_in.begin();
	//cout << mx << endl;

	vector<int> top, bot;
	for (int i = 0; i < n; i++) {
		if (!u[i] || i == mx) continue;
		if (a[i][mx]) top.push_back(i);
		else bot.push_back(i);
	}
	auto cmp = [&](int v1, int v2) { return (bool)(a[v1][v2]); };
	sort(top.begin(), top.end(), cmp);
	sort(bot.begin(), bot.end(), cmp);
	top.push_back(mx);

	int ts = top.size();
	int bs = bot.size();
	ans += 3 * ts * bs;
	ans += ((ts - 1) * ts + (bs - 1) * bs) * 3 / 2;

	vector<int> bd(n, 0), td(n, 0);
	a[mx][mx] = 1;
	for (int i = 0; i < n; i++) {
		if (!u[i]) continue;
		int d = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j] && (a[i][mx] ^ a[j][mx])) d++;
		}
		if (a[i][mx]) td[d]++;
		else bd[d]++;
	}

	for (int i = 0; i < n; i++) {
		ans += (bd[i] * (bd[i] - 1)) / 2;
		ans += (td[i] * (td[i] - 1)) / 2;
	}

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
#ifdef SERT
	int t = 2;
	for (int i = 1; i < t; i++) {
		solve();
	}
#endif
}