#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) {
		cin >> i;
	}
	vector<int> have = a;
	sort(all(have));
	have.resize(unique(all(have)) - have.begin());
	for (auto &i : a) {
		i = lower_bound(all(have), i) - have.begin();
	} 
	int ans = n;
	vector<int> L(have.size(), n), R(have.size(), -1);
	for (int i = 0; i < n; i++) {
		chkmin(L[a[i]], i);
		chkmax(R[a[i]], i);
	}
	vector<int> cnt(have.size());
	for (auto i : a) {
		cnt[i]++;
	}
	for (int i = 1; i < (int)have.size(); i++) {
		cnt[i] += cnt[i - 1];
	}
	vector<vector<int>> fcnt(have.size());
	for (int i = 0; i < n; i++) {
		fcnt[a[i]].push_back(i);
	}
	int pos = 0;
	for (int i = 0; i < (int)have.size(); i++) {
		chkmax(pos, i + 1);
		while (pos < (int)have.size() && R[pos - 1] < L[pos]) pos++;
		int cntSeg = (cnt[pos - 1] - (i > 0 ? cnt[i - 1] : 0));
		int cntPrev = (i > 0 ? (lower_bound(all(fcnt[i - 1]), L[i]) - fcnt[i - 1].begin()) : 0);
		int cntNxt = (pos < (int)have.size() ? fcnt[pos].end() - lower_bound(all(fcnt[pos]), R[pos - 1]) : 0);
		//cout << i << " " << cntSeg << " " << cntPrev << " " << cntNxt << endl;
		chkmin(ans, n - cntSeg - cntPrev - cntNxt);
	}
	for (int i = 0; i + 1 < (int)have.size(); i++) {
		for (int j = 0; j < (int)fcnt[i].size(); j++) {
			int help = fcnt[i + 1].end() - lower_bound(all(fcnt[i + 1]), fcnt[i][j]);
			chkmin(ans, n - (j + 1) - help);
		}
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}