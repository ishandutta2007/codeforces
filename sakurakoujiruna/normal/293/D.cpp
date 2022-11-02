#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define op operator
using ll = long long;
using ld = long double;
using pii = pair <int, int>;

struct poi {
	ll x, y;
	poi op -(poi p) {
		return {x - p.x, y - p.y};
	}
	bool op <(poi p) const {
		return tie(x, y) < tie(p.x, p.y);
	}
	ll cross(poi p) {
		return x * p.y - y * p.x;
	}
};
ll xmul(poi a, poi b, poi c) {
	return (b - a).cross(c - a);
}

using vp = vector <poi>;
vp convex(vp v) { sort(v.begin(), v.end()); vp r;
	for(int i = 0; i < v.size(); i ++) {
		while(r.size() > 1 &&
			xmul(*++r.rbegin(), v[i], *r.rbegin()) >= 0)
			r.pop_back();
		r.pb(v[i]);
	}
	int d = r.size();
	for(int i = (int)v.size() - 2; i >= 0; i --) {
		while(r.size() > d &&
			xmul(*++r.rbegin(), v[i], *r.rbegin()) >= 0)
			r.pop_back();
		if(i != 0) r.pb(v[i]);
	} return r;
}

ll f(ll a, ll b) {
	if(a >= 0) return a / b;
	return a / b - bool(a % b);
}
ll g(ll a, ll b) { return f(a + b - 1, b); }

ld solve(vp v) {
	v = convex(v); v.pb(v[0]);
	vp up, down;
	for(int i = 0; i < v.size(); i ++)
		if(!i || v[i].x > v[i - 1].x)
			down.pb(v[i]);
		else break;
	while(v.back().x == (++ v.rbegin()) -> x)
		v.pop_back();
	reverse(v.begin(), v.end());
	for(int i = 0; i < v.size(); i ++)
		if(!i || v[i].x > v[i - 1].x)
			up.pb(v[i]);
		else break;
	int j = 0, k = 0;
	vector <pii> xs;
	ld c = 0, s = 0, s2 = 0;
	for(int i = up[0].x; i <= up.back().x; i ++) {
		while(up[j + 1].x < i) j ++;
		while(down[k + 1].x < i) k ++;
		ll u = f((up[j + 1].y - up[j].y) * (i - up[j].x), up[j + 1].x - up[j].x) + up[j].y;
		ll d = g((down[k + 1].y - down[k].y) * (i - down[k].x), down[k + 1].x - down[k].x) + down[k].y;
		xs.pb({i, u - d + 1});
		c += u - d + 1;
		s += i * (u - d + 1);
		s2 += ld(i) * i * (u - d + 1);
	}
	ld ret = 0;
	for(pii p : xs) {
		ret += ld(p.fi) * p.fi * c * p.se;
		ret += -2.0L * p.fi * s * p.se;
		ret += s2 * p.se;
	}
	/*
	cout << "------\n";
	for(pii p : xs) {
		cout << p.fi << ' ' << p.se << '\n';
	}
	*/
	return ret / c / (c - 1);
}

int main() {
	int n; cin >> n;
	vp v;
	while(n --) {
		poi p; cin >> p.x >> p.y;
		v.pb(p);
	}
	ld ans = 0;
	for(int t = 0; t < 2; t ++) {
		ans += solve(v);
		for(auto &p : v)
			swap(p.x, p.y);
	}
	cout << fixed << setprecision(9) << ans / 2 << '\n';
}