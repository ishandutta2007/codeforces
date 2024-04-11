#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 1000010
#define pii pair<ll, ll>
#define pp pair<pii, ll>
#define mp make_pair

const ll INF = 100000000000000LL; 

bool Q;

struct Line {
	mutable ll k, m, p; //must be mutable for multiset
	//slope, y-intercept, last optimal x-value

	bool operator<(const Line& o) const {
		if (Q) {
			return p < o.p;
		}
		return k < o.k;
	}
};

struct LineContainer : multiset<Line> {
	ll div (ll v1, ll v2) {
		//floor division, handle negatives
		if (v2 < 0) {
			v1 *= -1;
			v2 *= -1;
		}
		if (v1 >= 0) {
			return v1/v2;
		}

		return 0-((0-v1+v2-1LL)/v2);
	}

	bool isect(iterator x, iterator y) {
		if (y == end()) {
			x->p = INF;
			return false;
		}
		if (x->k == y->k) {
			x->p = x->m > y->m ? INF: -INF;
		}
		else {
			x->p = div(y->m - x->m, x->k - y->k);
		}
		return x->p >= y->p;
	}

	void add(ll k, ll m) {
		// k = 0-k;
		// m = 0-m;
		//add a new line with slope k and y-intercept m

		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) {
			z = erase(z);
		}
		if (x != begin() && isect((--x), y)) {
			isect(x, y = erase(y));
		}
		while ((y = x) != begin() && (--x)->p >= y->p) {
			isect(x, erase(y));
		}
	}

	ll query(ll x) {
		if (empty()) return 0LL;
		Q = true;
		auto l = *lower_bound({0, 0, x});
		Q = false;
		return  0 + (l.k * x + l.m);
	}

};


int n;
vector<pp> stuff;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	LineContainer lc;
	cin >> n;
	ll x, y, a;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> a;
		stuff.push_back(mp(mp(x, y), a));
	}

	sort(stuff.begin(), stuff.end());

	ll ans = 0LL;
	for (int i = 0; i < n; i++) {
		x = stuff[i].first.first;
		y = stuff[i].first.second;
		a = stuff[i].second;

		ll tmp = lc.query(y);

		tmp = max(tmp, 0LL);

		ll curval = tmp + x * y - a;

		// cout << "tmp: " << tmp << endl;

		ans = max(ans, curval);
		lc.add(0-x, curval);
	}

	cout << ans << endl;

}