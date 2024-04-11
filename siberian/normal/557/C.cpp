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

struct fenvik{
	vector<int> tree;
	int n;
	fenvik() {}
	fenvik(int _n) {
		n = _n;
		tree.assign(n, 0);
	}

	void upd(int pos, int val) {
		for (; pos < n; pos |= pos + 1)
		tree[pos] += val;
	}

	int get(int r)  {
		int ans = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			ans += tree[r];
		return ans;
	}
};

int n;
vector<pair<int, int>> a;

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i.first;
	for (auto &i : a)
		cin >> i.second;
	sort(all(a));
	vector<pair<int, int>> have;
	for (int i = 0; i < n; i++) {
		have.push_back({a[i].second, i});
	}
	sort(all(have));
	vector<int> pos(n);
	for (int i = 0; i < n; i++) {
		pos[have[i].second] = i;
	}

	fenvik cnt(n);
	for (int i = 0; i < n; i++)
		cnt.upd(i, 1);
	fenvik val(n);
	for (int i = 0; i < n; i++)
		val.upd(i, have[i].first);
	int pos1 = n - 1;
	int ans = 1e18;
	int sum = 0;
	while (pos1 >= 0) {
		int l = pos1;
		while (l >= 0 && a[l].first == a[pos1].first) 
			l--;
		int fsum = 0;
		for (int i = l + 1; i <= pos1; i++) {
			cnt.upd(pos[i], -1);
			val.upd(pos[i], -have[pos[i]].first);
			fsum += have[pos[i]].first;
		}
		
		int have = l + 1;
		int my = pos1 - l;
		int del = max(0LL, have - my + 1);

		if (del == 0) {
			chkmin(ans, sum);
		}
		else {
			int tl = -1, tr = n - 1;
			while (tl < tr - 1) {
				int tm = (tl + tr) / 2;
				if (cnt.get(tm) >= del)
					tr = tm;
				else
					tl = tm;
			}
			chkmin(ans, sum + val.get(tr));
		}

		pos1 = l;
		sum += fsum;
	}
	cout << ans << endl;
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