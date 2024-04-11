#include <iostream>
#include <iomanip>

#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <set>
#include <map>

#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <complex>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)

#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#ifdef SG
	#define debug(x) cerr << #x << ": " << (x) << endl
#else
	#define debug(x)
#endif

template <typename T>
ostream & operator << (ostream & out, vector<T> const & a) {
	out << "[";
	for (int i = 0; i < sz(a); ++i) {
		if (i != 0) {
			out << ", ";
		}
		out << a[i];
	}
	out << "]";
	return out;
}

template <typename T1, typename T2>
ostream & operator << (ostream & out, pair<T1, T2> const & p) {
	out << "(" << p.fs << ", " << p.sc << ")";
	return out;
}

const int N = 100000;

struct Data {
	ll l, n;

	ll f[N], k[N];

	bool read () {
		if (!(cin >> l >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%I64d%I64d", &f[i], &k[i]);
		}
		return 1;
	}

	ll ans;
 
	void write () {
		cout << ans << endl;
	}
 
	virtual void solve () {}
 
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	static const ll INF = 1e10;

	pair<ll, ll> calc1 (const vector<ll> &v) {
		if ((ll)v.size() < 3) {
			return mp(0, 0);
		}
		if (v[0] == v.back()) {
			return mp(0, ll(v.size()) * ll(v.size() - 1) * ll(v.size() - 2) / 6);
		}
		vector<ll>::const_iterator it1 = upper_bound(all(v), v[0]), it2 = lower_bound(all(v), v.back());
		ll l = it1 - v.begin();
		ll m = it2 - it1;
		ll r = v.end() - it2;
		return mp(2 * (v.back() - v[0]), l * r * m + l * (l - 1) * r / 2 + r * (r - 1) * l / 2);
	}

	pair<ll, ll> calc2 (const vector<ll> &v1, const vector<ll> &v2) {
		if ((ll)v1.size() < 2 || (ll)v2.size() < 1) {
			return mp(0, 0);
		}
		vector<ll>::const_iterator it1 = lower_bound(all(v2), v1[0]), it2 = upper_bound(all(v2), v1.back());
		if (it1 != it2) {
			ll s = 0;
			forn (i, v2.size()) {
				it1 = lower_bound(all(v1), v2[i]);
				it2 = upper_bound(all(v1), v2[i]);
				ll l = it1 - v1.begin();
				ll m = it2 - it1;
				ll r = v1.end() - it2;
				s += l * r + l * m + r * m + m * (m - 1) / 2;
			}
			return mp(2 * l, s);
		}
		ll t1, t2;
		{
			if (v1[0] == v1.back()) {
				t1 = t2 = ll(v1.size()) * ll(v1.size() - 1) / 2;
			} else {
				vector<ll>::const_iterator it1 = upper_bound(all(v1), v1[0]), it2 = lower_bound(all(v1), v1.back());
				ll l = it1 - v1.begin();
				ll m = it2 - it1;
				ll r = v1.end() - it2;
				t1 = l * l / 2 + l * m + l * r;
				t2 = r * r / 2 + r * m + r * l;
			}
		}
		ll x1, x2;
		{
			vector<ll>::const_iterator it = lower_bound(all(v2), v1[0]);
			if (it == v2.begin()) {
				x1 = -INF;
			} else {
				x1 = *(it - 1);
			}
			if (it == v2.end()) {
				x2 = INF;
			} else {
				x2 = *it;
			}
		}

		ll s1 = 2 * l + abs(v1[0] - v1.back()) - abs(v1[0] - x1) - abs(v1.back() - x1);
		ll s2 = 2 * l + abs(v1[0] - v1.back()) - abs(v1[0] - x2) - abs(v1.back() - x2);
		if (s1 > s2) {
			return mp(s1, t1 * (upper_bound(all(v2), x1) - lower_bound(all(v2), x1)));
		} else {
			return mp(s2, t2 * (upper_bound(all(v2), x2) - lower_bound(all(v2), x2)));
		}
		return mp(s2, t1 * (upper_bound(all(v2), x1) - lower_bound(all(v2), x1)) + t2 * (upper_bound(all(v2), x2) - lower_bound(all(v2), x2)));
	}

	void solve () {
		vector<ll> v[2];
		forn (i, n) {
			v[f[i]].pb(k[i]);
		}
		forn (i, 2) {
			sort(all(v[i]));
		}
		ll mx = 0;
		ans = 0;

		pair<ll, ll> q;

		q = calc1(v[0]);
		if (q.fs > mx) {
			mx = q.fs;
			ans = 0;
		}
		if (q.fs == mx) {
			ans += q.sc; 
		}

		q = calc1(v[1]);
		if (q.fs > mx) {
			mx = q.fs;
			ans = 0;
		}
		if (q.fs == mx) {
			ans += q.sc; 
		}

		q = calc2(v[0], v[1]);
		if (q.fs > mx) {
			mx = q.fs;
			ans = 0;
		}
		if (q.fs == mx) {
			ans += q.sc; 
		}

		q = calc2(v[1], v[0]);
		if (q.fs > mx) {
			mx = q.fs;
			ans = 0;
		}
		if (q.fs == mx) {
			ans += q.sc; 
		}
	}

	Solution (Data d = Data()): Data(d) {
	}

	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
#ifdef SG
	freopen("input.txt", "r", stdin);
//	freopen("", "w", stdout);
	while (sol.read()) {
		sol.solve();
		sol.write();
		sol.clear();
	}
#else
	sol.read();
	sol.solve();
	sol.write();	
#endif
	return 0;
}