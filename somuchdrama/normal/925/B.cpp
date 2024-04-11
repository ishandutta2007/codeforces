#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;
#define int long long
const int INF = 1e9 + 7;
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
vector <pii> ans1, ans2;
int k1, k2; int n;

bool solve(vector <pii> c, int x1, int x2) {
	ans1.clear(); ans2.clear(); k1 = k2 = 1;
	for (; k1 <= n; ++k1) {
		auto ind = distance(c.begin(), lower_bound(c.begin(), c.end(), mp((x1 + k1 - 1) / k1, -INF)));
		if (ind + k1 <= n) break;
	}

	if (k1 > n) {
		return 0;
	} 

	for (int i = 1; i <= k1; ++i) {
		ans1.pb(c.back());
		c.pop_back();
	}

	for (; k2 <= (int)c.size(); ++k2) {
		auto ind = distance(c.begin(), lower_bound(c.begin(), c.end(), mp((x2 + k2 - 1) / k2, -INF)));
		if (ind + k2 <= (int)c.size()) break;
	}

	if (k2 > (int)c.size()) {
		return 0;
	} 

	for (int i = 1; i <= k2; ++i) {
		ans2.pb(c.back());
		c.pop_back();
	}
	return 1;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	

	int x1, x2;
	cin >> n >> x1 >> x2;

	vector <pii> c(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i].ff; c[i].ss = i;
	}
	sort(c.begin(), c.end());


	if (solve(c, x1, x2)) {
		cout << "Yes\n";
		cout << k1 << ' ' << k2 << '\n';
		for (auto i : ans1) cout << i.ss + 1 << ' ';
		cout << '\n';
		for (auto i : ans2) cout << i.ss + 1 << ' ';
		cout << '\n';
	} else if (solve(c, x2, x1)) {
		cout << "Yes\n";
		cout << k2 << ' ' << k1 << '\n';
		for (auto i : ans2) cout << i.ss + 1 << ' ';
		cout << '\n';
		for (auto i : ans1) cout << i.ss + 1 << ' ';
		cout << '\n';
	} else {
		cout << "No\n";
	}
}