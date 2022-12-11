#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <iomanip>

typedef long double ld;
typedef long long ll;
using namespace std;

struct target {
	ll t = 0;
	ll x = 0;
	ll y = 0;
	ld p = 0;
	target(ll time, ll xc, ll yc, ld pr) : t(time), x(xc), y(yc), p(pr) {}
	target() {}
};

const bool operator < (target a, target b) {
	return (a.t < b.t);
}

ll sqdiff(ll a, ll b) {
	return (a - b)*(a - b);
}

ll sqdist(target a, target b) {
	//cout << "coord check " << a.x << " " << b.x << " " << a.y << " " << b.y << " " << endl;
	return sqdiff(a.x, b.x) + sqdiff(a.y, b.y);
}


int main() {
	cout << setprecision(10) << fixed;
	int n; cin >> n;
	vector<target> ts;
	ts.reserve(n);
	for (int i = 0; i < n; ++i) {
		ll x, y, t; ld p; cin >> x >> y >> t >> p;
		ts.emplace_back(t, x, y, p);
		//cout << x << " " << y << " " << t << " " << p << endl;
	}
	sort(ts.begin(), ts.end());
	vector<ld> best(n, 0.0);
	for (int i = 0; i < n; ++i) {
		best[i] = ts[i].p;
	}
	for (int tc = 0; tc < n; ++tc) {
		for (int pred = 0; pred < tc; ++pred) {
			//cout << "pair has " << << " diff\n";
			if (sqdist(ts[tc], ts[pred]) <= sqdiff(ts[tc].t, ts[pred].t)) {
				//cout << "check pass with sdist " << sqdist(ts[tc], ts[pred]) << " against time " << sqdiff(ts[tc].t, ts[pred].t) << endl;
				best[tc] = max(best[tc], best[pred] + ts[tc].p);
			}
		}
	}
	cout << *max_element(best.begin(), best.end()) << endl;
	return 0;

}