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
	vector<ll> a;
	ll n, sz;

	ordered_multiset(ll n_) {
		n = n_;
		sz = 0;
		a.resize(n + 1);
	}

	ll get_sum(ll x) {
		ll res = 0;
		while (x > 0) {
			res += a[x];
			x = (x & (x + 1)) - 1;
		}
		return res;
	}

	ll sum(ll l, ll r) {
		return get_sum(r) - get_sum(l - 1);
	}

	void upd_plus(ll p, ll x) {
		for (ll j = p; j <= n; j = (j + 1) | j) {
			a[j] += x;
		}
	}

	void upd(ll p, ll x) {
		upd_plus(p, x - sum(p, p));
	}


	ll count(ll l, ll r) {
		if (l <= r)
			return sum(l, r);
		return 0;
	}

	void insert(ll x) {
		upd_plus(x, 1);
		sz++;
	}

	void erase(ll x) {
		upd_plus(x, -1);
		sz--;
	}

	ll less(ll x) {
		ll l = -1, r = x;
		while (r - l > 1) {
			ll m = (l + r) / 2;
			if (count(m, x))
				l = m;
			else
				r = m;
		}
		return l;
	}
};

ll solve(int m, vector<ll>& vvod) {
	vector<pair<ll, ll>> a(m);
	for (int i = 0; i < m; ++i) {
		a[i] = { vvod[i], -i };
	}
	sort(all(a));
	a.push_back({ 1e12, 1e12 });
	vector<ll> b(m);
	ordered_multiset s(m + 10);
	for (int i = 0; i < m; ++i) {
		b[-a[i].second] = i + 1;
	}
	ll ans = 0;
	for (int i = 0; i < m; ++i) {
		ans += s.count(0, b[i] - 1);
		s.insert(b[i]);
	}
	return ans;
}

signed main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		vector<pair<ll, ll>> a(n * m);
		for (int i = 0; i < n * m; ++i) {
			int x;
			cin >> x;
			a[i] = { x, i };
		}
		sort(all(a));
		vector<pair<ll, ll>> tmp1;
		ll ans = 0;
		for (int i = 0; i <= n * m; ++i) {
			if (i % m == 0 && i) {
				sort(all(tmp1));
				vector<ll> tmp2;
				for (auto& j : tmp1)
					tmp2.push_back(j.second);
				tmp1.clear();
				ans += solve(m, tmp2);
			}
			if (i < n * m)
				tmp1.push_back({ a[i].second, a[i].first });
		}
		cout << ans << "\n";
	}

	return 0;
}