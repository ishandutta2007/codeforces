#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define find find228
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

int n, k;
vector<int> c;

void solve() {
	cin >> n >> k;
	c.resize(n);
	for (auto &i : c)
		cin >> i;
	int ans = 0;
	vector<int> fans(n);
	set<pair<int, int>> q;
	int sum = 0;
	for (int i = 0; i < k; i++) {
		ans += (k - i) * c[i];
		q.insert({c[i], i});
		sum += c[i];
	}
	//cout << ans << endl;
	//cout << sum << endl;
	for (int i = k; i < n + k; i++) {
		if (i < n) {
			sum += c[i];
			q.insert({c[i], i});
		}
		//cout << q.size() << endl;
		int x = (--q.end())->second;
		q.erase(--q.end());
		sum -= c[x];
		ans += sum;
		fans[x] = i + 1;
	}
	cout << ans << "\n";
	for (auto i : fans)
		cout << i << " ";
	cout << "\n";
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