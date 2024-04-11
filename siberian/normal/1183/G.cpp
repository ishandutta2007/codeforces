#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n;
	cin >> n;
	map <int, pair <int, int> > a;
	
	for (int i = 0; i < n; i++) {
		int x, t;
		cin >> x >> t;
		if (t == 0)
			a[x].first++;
		else
			a[x].second++;
	}
	multiset<pair <int, int> > help;
	for (auto i : a) {
		help.insert({-i.second.first - i.second.second, i.second.second});
	} 


	/*cout << "help = " << endl;
	for (auto i : help) {
		cout << i.first << " " << i.second << endl;
	}*/

	multiset<int> good;

	int ans1 = 0;
	int ans2 = 0;
	int now = 1e9;
	while (!help.empty() && now > 0) {
		while (!help.empty() && (help.begin()->first) * -1 >= now) {
			auto q = *help.begin();
			good.insert(-q.second);
			help.erase(help.begin());
		}

		if (!good.empty()) {
			int x = *good.begin();
			good.erase(good.begin());
			x = -x;
			ans1 += now;
			ans2 += min(now, x);
			now--; 
		}
		else {
			auto q = *help.begin();
			now = -q.first;
		}
	}

	while (!good.empty() && now > 0) {
		int x = *good.begin();
		good.erase(good.begin());
		x = -x;
		ans1 += now;
		ans2 += min(now, x);
		now--; 
	}

	cout << ans1 << " " << ans2 << "\n";
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

/*
1
4
1 1
1 1
2 1
2 1

*/