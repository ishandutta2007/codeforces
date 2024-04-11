//#define _GLIBCXX_DEBUG
#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
//#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#pragma GCC optimize("O3")

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& i : a) cout << i << " ";
#define input(a) for (auto& i : a) cin >> i;

//#define DEBUG

using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ll> a(n);
	input(a);
	int m;
	cin >> m;
	vector<ll> x(m), y(m);
	for (int i = 0; i < m; ++i)
		cin >> x[i] >> y[i];
	sort(all(a));
	ll sum = 0;
	for (auto i : a)
		sum += i;
	for (int i = 0; i < m; ++i) {
		ll ans = 2e18;
		auto it = lower_bound(all(a), x[i]);
		if (it != a.end()) {
			ans = min(ans, max(0ll, y[i] - (sum - *it)));
		}
		if (it != a.begin()) {
			--it;
			ans = min(ans, x[i] - *it + max(0ll, y[i] - (sum - *it)));
		}
		cout << ans << "\n";
	}

	return 0;
}