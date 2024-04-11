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
vector<int> s;
	
bool check(int sz) {
	sort(all(s));
	if (s.back() > sz) return false;
	int pos = 0;
	int cnt = 0;
	for (int i = s.size() - 1; i >= pos; i--) {
		if (i == pos) {
			cnt++;
			break;
		}
		if (s[i] + s[pos] <= sz) {
			cnt++;
			pos++;
		}
		else {
			cnt++;
		}
	}
	return cnt <= k;
}

void solve() {
	cin >> n >> k;
	s.resize(n);
	for (auto &i : s)
		cin >> i;
	int l = 0, r = 2e9 + 10;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (check(mid)) 
			r = mid;
		else
			l = mid;
	}
	cout << r;
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