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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> cnt(2);
	for (auto &i : a) cin >> i;
	for (auto i : a) cnt[i % 2]++;
	if (cnt[0] && cnt[1]) sort(all(a));
	for (auto i : a) cout << i << " ";
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