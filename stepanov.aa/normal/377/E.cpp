#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>
#include <cassert>
#include <map>
#include <set>
#include <deque>
#include <array>



using namespace std;


#define int long long
#define ll long long
#define flt long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define nlpt nullptr
#define prcs cout << fixed << setprecision(10)


mt19937 rnd(123123);
ll inf = 1e17;


struct CHT {
	struct line {
		ll k;
		ll b;
		flt bg;

		line() {}
		line(ll k, ll b, flt bg) : k(k), b(b), bg(bg) {}


		ll operator()(ll x){
			return k * x + b;
		}
	};


	vector<line> a;


	void build() {
		a.clear();
		a.push_back(line(0, 0, -inf));
	}

	flt intrsct(line &a, line &b) {
		return ceil((a.b - b.b) / (flt)(b.k - a.k));
	}


	void add_line(ll k, ll b) {
		line ln = line(k, b, -inf);
		if (a.back().k == k) {
			if (b <= a.back().b) {
				return;
			}
			a.pop_back();
		}
		while (!a.empty() && intrsct(a.back(), ln) <= a.back().bg) {
			a.pop_back();
		}
		ln.bg = intrsct(a.back(), ln);
		a.push_back(ln);
	}


	ll get(ll x) {
		int l = 0;
		int r = a.size();
		while (l + 1 < r) {
			int m = (l + r) / 2;
			if (a[m].bg <= x) {
				l = m;
			}
			else {
				r = m;
			}
		}
		return a[l].k * x + a[l].b;
	}


	ll get_frst_ln(line &ln, ll y) {
		ll l = -1;
		ll r = 1e5;
		while (ln(r) < y) {
			r *= 2;
			if (r >= 1e17) {
				return r;
			}
		}
		while (l + 1 < r) {
			ll m = (l + r) / 2;
			if (ln(m) >= y) {
				r = m;
			}
			else {
				l = m;
			}
		}
		return r;
	}


	ll get_first(ll y) {
		int l = 0;
		int r = (int)(a.size()) - 1;
		while (l + 1 < r) {
			int m = (l + r) / 2;
			if (a[m](a[m + 1].bg - 1) < y) {
				l = m;
			}
			else {
				r = m;
			}
		}
		return get_frst_ln(a[r], y);
	}
};


int n;
ll s;
vector<pair<ll, ll>> a;
CHT cht;


ll find_frst(ll c) {
	return cht.get_first(c);
	ll l = -1;
	ll r = 1e9;
	while (cht.get(r) < c) {
		l = r;
		r *= 2;
	}
	while (l + 1 < r) {
		ll m = (l + r) / 2;
		if (cht.get(m) >= c) {
			r = m;
		}
		else {
			l = m;
		}
	}
	return r;
}


int32_t main() {
	if (1) {
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	}
	cin >> n >> s;
	a.resize(n);
	for (int i = 0; i < n; i += 1) {
		cin >> a[i].first >> a[i].second;
	}
	sort(all(a));
	cht.build();
	bool fnd = false;
	for (auto& f : a) {
		if (f.second != 0 && !fnd) {
			continue;
		}
		if (f.second == 0) {
			fnd = true;
		}
		ll x = find_frst(f.second);
		ll y = cht.get(x);
		cht.add_line(f.first, y - f.second - f.first * x);
	}
	cout << find_frst(s) << "\n";
	return 0;
}

/*
5 6
6 0
3 7
1 9
1 7
2 4
*/