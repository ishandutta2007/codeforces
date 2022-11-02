#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(a) (a).begin(), (a).end()

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
	if (y < x) {
		x = y;
	}
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
	if (x < y) {
		x = y;
	}
}

const int N = 2e5 + 10;
const int A = 3;
int n, q;
string s;
vector<vector<int>> perm;
int pref[N][6];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	cin >> n >> q;
	cin >> s;
	vector<int> have = {0, 1, 2};
	// perm.push_back({0, 1, 2});
	do {
		perm.push_back(have);
	} while (next_permutation(all(have)));

	for (int c = 0; c < perm.size(); ++c) {
		for (int i = 0; i < n; ++i) {
			pref[i][c] += (s[i] - 'a') != perm[c][i % A];
			if (i > 0) pref[i][c] += pref[i - 1][c];
		}
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		--l;
		--r;
		int ans = INT_MAX;
		for (int c = 0; c < perm.size(); ++c) {
			chkmin(ans, pref[r][c] - (l > 0 ? pref[l - 1][c] : 0));
		}
		cout << ans << '\n';
	}
	return 0;
}