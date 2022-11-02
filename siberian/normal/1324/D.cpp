#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
vector<int> a;
vector<int> b;
struct fenvik{
	vector<int> tree;
	int n;
	fenvik() {}
	fenvik(int sz) {
		n = sz;
		tree.assign(n, 0);
	}
	int get(int r) {
		int ans = 0;
		for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
			ans += tree[i];
		return ans;
	}
	void upd(int pos, int val) {
		for (; pos < n; pos |= pos + 1)
			tree[pos] += val;
	}
};

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	b.resize(n);
	for (auto &i : b)
		cin >> i;
	vector<int> have;
	for (int i = 0; i < n; i++) {
		have.push_back(a[i] - b[i]);
		have.push_back(b[i] - a[i]);
	}
	sort(all(have));
	have.resize(unique(all(have)) - have.begin());
	ll ans = 0;
	fenvik tree(have.size());
	for (int i = 0; i < n; i++) {
		int pos = lower_bound(all(have), a[i] - b[i]) - have.begin();
		ans += tree.get(pos - 1);
		pos = lower_bound(all(have), b[i] - a[i]) - have.begin();
		tree.upd(pos, 1);
	}
	cout << ans << endl;
	return 0;
}