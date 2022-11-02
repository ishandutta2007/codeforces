#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int find1(vector<int> & a) {
	int ans = -1;
	for (auto i : a)
		ans = max(ans, i);
	return ans;
}

int find2(vector<int> & a) {
	int ans = -1;
	int n = a.size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] % a[j] != 0) {
				ans = max(ans, a[i] + a[j]);
			}
		}
	}
	return ans;
}

int find3(vector<int> & a) {
	int ans = -1;
	int n = a.size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (a[i] % a[j] != 0 && a[i] % a[k] != 0 && a[j] % a[k] != 0) {
					ans = max(ans, a[i] + a[j] + a[k]);
				}
			}
		}
	}
	return ans;
}

int find(vector<int> & a) {
	return max(find1(a), max(find2(a), find3(a)));
}

void solve() {
	int n;
	cin >> n;
	set<int> help;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		help.insert(-x);	
	}
	vector<int> a;
	int cnt = 80;
	while (cnt && !help.empty()) {
		auto x = *help.begin();
		help.erase(help.begin());
		x *= -1;
		cnt--;
		a.push_back(x);
	}
	cout << find(a) << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}