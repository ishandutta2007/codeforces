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

//#define int long long
//#define DEBUG

using namespace std;

struct ordered_multiset {
	vector<int> a;
	int n, sz;

	ordered_multiset(int n_) {
		n = n_;
		sz = 0;
		a.resize(n + 1);
	}

	int get_sum(int x) {
		int res = 0;
		while (x > 0) {
			res += a[x];
			x = (x & (x + 1)) - 1;
		}
		return res;
	}

	int sum(int l, int r) {
		return get_sum(r) - get_sum(l - 1);
	}

	void upd_plus(int p, int x) {
		for (int j = p; j <= n; j = (j + 1) | j) {
			a[j] += x;
		}
	}

	void upd(int p, int x) {
		upd_plus(p, x - sum(p, p));
	}


	int count(int l, int r) {
		if (l <= r)
			return sum(l, r);
		return 0;
	}

	void insert(int x) {
		upd_plus(x, 1);
		sz++;
	}

	void erase(int x) {
		upd_plus(x, -1);
		sz--;
	}

	int less(int x) {
		int l = -1, r = x;
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (count(m, x))
				l = m;
			else
				r = m;
		}
		return l;
	}
};

signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<pair<ll, ll>> a(n * m);
		for (int i = 0; i < n * m; ++i) {
			int x;
			cin >> x;
			a[i] = { x, -i };
		}
		sort(all(a));
		a.push_back({ 1e12, 1e12 });
		vector<ll> b(n * m);
		ordered_multiset s(n * m + 10);
		for (int i = 0; i < n * m; ++i) {
			b[-a[i].second] = i + 1;
		}
		ll ans = 0;
		for (int i = 0; i < n * m; ++i) {
			ans += s.count(0, b[i] - 1);
			s.insert(b[i]);
		}
		cout << ans << "\n";
	}

	return 0;
}