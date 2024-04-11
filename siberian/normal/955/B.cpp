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

void no() {
	cout << "No";
	exit(0);
}

void yes() {
	cout << "Yes";
	exit(0);
}

void solve() {
	string s;
	cin >> s;
	if (s.size() < 4) no();
	map<char, int> have;
	for (auto i : s) have[i]++;
	if (have.size() > 4) no();
	if (have.size() > 2) yes();
	if (have.size() == 1) no();
	int x = 1e9;
	for (auto i : have)
		chkmin(x, i.second);

	if (x == 1) no();
	yes();
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