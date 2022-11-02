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

const int MAXN = 2e5 + 10;
int par[MAXN], mx[MAXN];

void make() {
	for (int i = 1; i < MAXN; i++)
		par[i] = i, mx[i] = i;
}

int get_par(int v) {
	if (par[v] == v) return v;
	return par[v] = get_par(par[v]);
}

void uni(int a, int b) {
	a = get_par(a);
	b = get_par(b);
	if (a == b) return;
	par[b] = a;
	chkmax(mx[a], mx[b]);
}

int n;
int a[MAXN];
int have[MAXN];

void solve() {
	make();
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1)  {
			int pos, val;
			cin >> pos >> val;
			while (pos < n + 1 && val) {
				//cout << pos << endl;
				if (a[pos] == have[pos]) pos = mx[get_par(pos)];
				int add = min(a[pos] - have[pos], val);
				val -= add;
				have[pos] += add;
				if (!val) break;
				uni(pos, pos + 1);
			}
		}
		else {
			int k;
			cin >> k;
			cout << have[k] << "\n"; 
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