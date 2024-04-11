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

//#define int ll

const int MAXN = 2e5 + 10;
int par[MAXN];
set<int> val;

void make() {
	for (int i = 0; i < MAXN; i++)
		par[i] = i, val.insert(i);
}

int get_par(int v) {
	if (v == par[v]) return v;
	return par[v] = get_par(par[v]);
}

void uni(int a, int b) {
	a = get_par(a);
	b = get_par(b);
	if (a == b) return;
	par[b] = a;
}

int n, q;

void solve() {
	cin >> n >> q;
	make();
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			uni(x, y);
		} else if (t == 2) {
			int x, y;
			cin >> x >> y;
			while (x < y) {
				uni(x, x + 1);
				val.erase(x);
				auto it = val.lower_bound(x + 1);
				if (it == val.end()) continue;
				x = *it;
			}
		} else {
			int x, y;
			cin >> x >> y;
			if (get_par(x) == get_par(y))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
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