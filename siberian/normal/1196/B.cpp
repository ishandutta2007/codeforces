#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &i : a)
		cin >> i;

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2)
			ans.push_back(i + 1);
	}
	if (ans.size() < k) {
		cout << "NO\n";
		return;
	}
	while (ans.size() > k - 1) {
		ans.pop_back();
	}
	int sum = 0;
	for (int i = (!ans.empty() ? ans.back() : 0); i < n; i++)
		sum += a[i];

	if (sum % 2 == 0) {
		cout << "NO\n";
		return;
	}
	
	ans.push_back(n);
	cout << "YES\n";
	for (auto i : ans)
		cout << i << " ";
	cout << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}