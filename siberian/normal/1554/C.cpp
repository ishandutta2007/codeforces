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

mt19937 rnd(0);

int get(int x) {
	int ans = 30;
	while (ans >= 0 && !((x >> ans) & 1)) --ans;
	return ans;
}

int solve(int n, int m) {
	if (n > m) return 0;
	if (n == 0 && m == 0) return 1;
	int bn = get(n);
	int bm = get(m);
	if (bn < bm) {
		return (1 << bm) + solve(n, m ^ (1 << bm));
	} else {
		assert(bn == bm);
		int ans = solve(n ^ (1 << bn), m ^ (1 << bm));
		if (ans == (1 << bn)) {
			ans += (1 << bn);
		} 
		return ans;
	}
}

int stupidSolve(int n, int m) {
	// int n, m;
	// cin >> n >> m;
	vector<int> a;
	for (int i = 0; i <= m; ++i) {
		a.push_back(n ^ i);
	}
	sort(all(a));
	int ans = 0;
	while (ans < a.size() && a[ans] == ans) ++ans;
	// cout << ans << endl;
// }
	return ans;
}


int n, m;

void solve() {
	// cin >> n >> m;
	if (m < n) {
		cout << "0\n";
		return;
	}
	// for (int x = 0; x <= m; ++x) {
	// 	cout << (n ^ x) << " ";
	// }
	// cout << endl;
	// int ans = 0;
	// for (int bit = 30; bit >= 0; --bit) {
	// 	if (((m >> bit) & 1) && !((n >> bit) & 1)) {
	// 		int l = bit;
	// 		while (l >= 0 && ((n >> l) & 1) == 0 && ((m >> l) & 1) == 1) {
	// 			ans |= (1 << l);
	// 			--l;
	// 		}
	// 		break;
	// 	}
	// }
	// cout << ans + 1 << '\n';
	// cerr << n << " " << m << " " << solve(n, m) << " " << stupidSolve(n, m) << endl;
	// assert(solve(n, m) == stupidSolve(n, m));
	cout << solve(n, m) << '\n';
}

// const int N = 1000;

void gen() {
	// n = (ull)rnd() % N;
	// m = (ull)rnd() % N;
	cin >> n >> m;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	while (t--) {
		gen();
		solve();
	}
	return 0;
}