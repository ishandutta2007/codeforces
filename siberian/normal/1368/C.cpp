#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;

void read() {
	cin >> n;
}

vector<pair<int, int>> ans;

void run() {
	for (int i = 1; i <= n + 1; i++) {
		ans.push_back({i, i});
		ans.push_back({i - 1, i});
		ans.push_back({i, i - 1});
		ans.push_back({i - 1, i - 1});
	}
	sort(all(ans));
	ans.resize(unique(all(ans)) - ans.begin());
}

void write() {
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i.first << " " << i.second << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}