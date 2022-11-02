#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
 
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
 
int get(string s) {
	vector<int> cnt(26);
	int ans = 0;
	for (auto i : s) {
		for (int j = i - 'a' + 1; j < 26; j++) {
			ans += cnt[j];
		}
		cnt[i - 'a']++;
	}
	return ans;
}
 
void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	auto x = s, y = t;
	sort(all(x));
	sort(all(y));
	if (x != y) {
		cout << "NO" << endl;
		return;
	}
	map<int, int> cnt;
	for (auto i : s)
		cnt[i]++;
	for (auto i : cnt) {
		if (i.second >= 2) {
			cout << "YES" << endl;
			return;
		}
	}
	if (get(s) % 2 != get(t) % 2) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
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