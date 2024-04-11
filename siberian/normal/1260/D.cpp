#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

int m, n, k, t;
vector<int> a;
struct segm{
	int l, r, d;
	segm() {}
	segm(int _l, int _r, int _d) {
		l = _l, r = _r, d = _d;
	}
};

vector<segm> have;

void relax(vector<pair<int, int>> & a) {
	vector<pair<int, int>> ans;
	sort(all(a));
	for (auto i : a) {
		if (ans.empty() || ans.back().second + 1 < i.first)
			ans.push_back(i);
		else
			chkmax(ans[ans.size() - 1].second, i.second);
	}
	a = ans;
}

bool check(int cnt) {
	int d = a[cnt - 1];
	vector<pair<int, int>> x;
	for (auto i : have) {
		if (i.d > d) x.push_back({i.l, i.r});
	}
	relax(x);
	int ans = n + 1;
	for (auto i : x) {
		ans += (i.second - i.first + 1) * 2;
	}
	return ans <= t;
}

void solve() {
	cin >> m >> n >> k >> t;
	a.resize(m);
	for (auto &i : a)
		cin >> i;
	sort(all(a));
	reverse(all(a));
	have.resize(k);
	for (auto &i : have) {
		cin >> i.l >> i.r >> i.d;
	}
	int l = 0, r = m + 1;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid;
	}
	cout << l << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}