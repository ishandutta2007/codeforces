#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define fadd fadd228
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

//#define int ll
mt19937 rnd(time(0));
const int MOD = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) a += MOD;
	return a;
}

int mul(int a, int b) {
	return (ll) a * b % MOD;
}

int binpow(int a, int n) {
	if (n == 0) return 1;
	if (n & 1) {
		return mul(a, binpow(a, n - 1));
	}
	else {
		return binpow(mul(a, a), n / 2);
	}
}

int inv(int a) {
	return binpow(a, MOD - 2);
} 

#define int ll

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (auto &i : a) cin >> i;
	int pos = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == m) pos = i;
		if (a[i] < m) a[i] = -1;
		else if (a[i] > m) a[i] = 1;
	}

	map<int, int> cntL, cntR;
	int pref = 0;
	for (int i = pos + 1; i < n; i++) {
		pref += a[i];
		cntR[pref]++;
	}
	pref = 0;
	for (int i = pos - 1; i >= 0; i--) {
		pref += a[i];
		cntL[pref]++;
	}
	/*for (auto i: a)
		cout << i << " ";
	cout << endl;*/
	int ans = 1;
	ans += cntL[0] + cntL[1] + cntR[0] + cntR[1];
	for (auto i : cntR) {
		ans += cntL[-i.first] * i.second;
		ans += cntL[-i.first + 1] * i.second;
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