#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;
using pdd = pair <db, db>;

const db eps = 1e-9;
int sgn(db a, db b = 0) {
	a -= b;
	return (a > eps) - (a < -eps);
}

const db pi = 4 * atan(1);

#define pb push_back

struct poi {
	ll x, y;
	//void r() { cin >> x >> y; }
	void r() { scanf("%lld%lld", &x, &y); }
	poi operator -(poi p) {
		return {x - p.x, y - p.y};
	}
	db ang() {
		db r = atan2(y, x);
		if(sgn(r) < 0)
			r += 2 * pi;
		return r;
	}
	ll len2() { return x * x + y * y; }
	db len() { return sqrt(len2()); }
};

const int N = 1e5L + 11;
poi p[N];
ll r[N];

int main() {
	//ios :: sync_with_stdio(false);
	cout << fixed << setprecision(6);

	ll v, t;
	p[0].r(); cin >> v >> t;
	r[0] = v * t;
	int n; cin >> n;
	for(int i = 1; i <= n; i ++) {
		p[i].r(); //cin >> r[i];
		scanf("%lld", r + i);
		p[i] = p[i] - p[0];
	}

	vector <pdd> events;
	for(int i = 1; i <= n; i ++) {
		if(p[i].len2() <= r[i] * r[i]) {
			events.pb({0, 2 * pi});
			continue;
		}
		if(r[0] + r[i] == 0 ||
			p[i].len2() / (r[0] + r[i]) >= (r[0] + r[i]) &&
			p[i].len2() >= (r[0] + r[i]) * (r[0] + r[i]))
			continue;
		db s = p[i].len();
		db t = sqrt(p[i].len2() - r[i] * r[i]);
		if(t > r[0])
			t = r[0];
		db a = acos((s * s + t * t - r[i] * r[i]) / 2 / s / t);
		db b = p[i].ang();

		db u = b - a, v = b + a;
		if(sgn(u) < 0) {
			events.pb({u + 2 * pi, 2 * pi});
			events.pb({0.0, v});
		} else if(sgn(v, 2 * pi) > 0) {
			events.pb({u, 2 * pi});
			events.pb({0.0, v - 2 * pi});
		} else
			events.pb({u, v});
	}

	sort(events.begin(), events.end());
	db ans = 0, last = 0;
	for(auto e : events) {
		last = max(last, e.first);
		ans += max(e.second - last, 0.0);
		last = max(last, e.second);
	}
	cout << ans / 2 / pi << '\n';
	return 0;
}