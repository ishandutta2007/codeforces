#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

struct dsu{
	vector<int> par, sz, mx;
	int n;
	dsu() {}

	dsu(int _n) {
		n = _n + 1;
		par.assign(n, 0);
		iota(all(par), 0);
		sz.assign(n, 1);
		mx = par;
	}

	int get_par(int v) {
		if (v == par[v]) return v;
		return par[v] = get_par(par[v]);
	}

	void uni(int a, int b) {
		a = get_par(a);
		b = get_par(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		par[b] = a;
		chkmax(mx[a], mx[b]);
	}
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> pos(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		pos[a[i]] = i;
	}

	dsu nxt(n);
	vector<int> count(n, 1);
	multiset<int> fmx;
	for (auto i : count) {
		fmx.insert(i);
	}

	for (int i = 0; i < n; i++) {
		int mx_val = *(--fmx.end());
		/*cout << "mx_val = " << mx_val << endl;	
		cout << "count = " << endl;
		for (auto i : count)
			cout << i << " ";
		cout << endl;*/

		if (count[pos[i]] != mx_val) {
			cout << "No\n";
			return;
		}
		fmx.erase(--fmx.end());
		nxt.uni(pos[i], pos[i] + 1);
		int my_nxt = nxt.mx[nxt.get_par(pos[i])];
		//cout << "my_nxt = " << my_nxt << endl;
		if (my_nxt != n) {
			fmx.erase(fmx.find(count[my_nxt]));
			count[my_nxt] += count[pos[i]];
			fmx.insert(count[my_nxt]);
		}
		count[pos[i]] = 0;
	}
	cout << "Yes\n";
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