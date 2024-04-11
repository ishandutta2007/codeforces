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

int n, k;
struct segm{
	int l, r, ind;
	segm() {}
};
vector<segm> a;

bool check(vector<segm> have) {
	vector<int> pos(n + 200);
	for (auto i : have) {
		for (int j = i.l; j <= i.r; j++) {
			pos[j]++;
		}
	}
	return (*max_element(all(pos))) <= k;
}

void solve() {
	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].l >> a[i].r;
		a[i].ind = i;
	}
	sort(all(a), [&] (segm i, segm j) {return tie(i.r, j.l) < tie(j.r, i.l);});
	vector<int> ans;
	vector<segm> have;
	for (auto i : a) {
		have.push_back(i);
		if (!check(have)) {
			have.pop_back();
			ans.push_back(i.ind);
		}
	}
	cout << ans.size() << endl;
	for (auto i: ans)
		cout << i + 1 << " ";
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