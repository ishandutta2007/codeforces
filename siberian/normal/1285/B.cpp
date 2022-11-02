#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll

int get(vector<int> a) {
	int sum = 0;
	int pref = 0;
	int ans = -1e18;
	for (auto i : a) {
		sum += i;
		chkmin(pref, sum);
		chkmax(ans, sum - pref);
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for (auto &i : a)
		cin >> i, sum += i;
	int ans = -1e18;
	vector<int> b = a;
	a.pop_back();
	/*cout << "a = " << endl;
	for (auto i : a)
		cout << i << " ";
	cout << endl;
	cout << get(a) << endl;*/
	b.erase(b.begin());
	/*cout << "b = " << endl;
	for (auto i : b)
		cout << i << " ";
	cout << endl;
	cout << get(b) << endl;*/
	chkmax(ans, get(a));
	chkmax(ans, get(b));
	//cout << endl;
	//cout << sum << " " << ans << endl;
	if (sum > ans) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}