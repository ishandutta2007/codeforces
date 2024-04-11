#include <bits/stdc++.h>
using namespace std;

#define pb push_back
using ll = long long;

struct poi {
	ll x, y;
	void r() { cin >> x >> y; }
	void w() { cout << x << ' ' << y << '\n'; }
	poi operator -(poi p) { return {x - p.x, y - p.y}; }
	poi operator +(poi p) { return {x + p.x, y + p.y}; }
	bool operator <(poi p) const {
		return tie(x, y) < tie(p.x, p.y);
	}
	ll cross(poi p) { return x * p.y - y * p.x; }
};
ll xmul(poi a, poi b, poi c) {
	return (b - a).cross(c - a);
}

using vp = vector <poi>;
vp convex(vp v) {
	sort(v.begin(), v.end()); vp r;
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
	}
	return r;
}

int main() {
	ios :: sync_with_stdio(false);
	int n; ll s; cin >> n >> s;
	vp v;
	for(int i = 0; i < n; i ++) {
		poi p; p.r();
		v.pb(p);
	}
	v = convex(v);
	n = v.size();

	{
		vp ans; ll s = 0;
		for(int i = 0; i < n; i ++) {
			int k = i + 1;
			for(int j = i + 1; j < i + n; j ++) {
				while(xmul(v[i], v[j % n], v[k % n]) <
					xmul(v[i], v[j % n], v[(k + 1) % n])) k ++;
				if(xmul(v[i], v[j % n], v[k % n]) > s) {
					s = xmul(v[i], v[j % n], v[k % n]);
					ans = {v[i], v[j % n], v[k % n]};
				}
			}
		}
		for(int i = 0; i < 3; i ++)
			(ans[i] + ans[(i + 1) % 3] - ans[(i + 2) % 3]).w();
	}
	return 0;
}