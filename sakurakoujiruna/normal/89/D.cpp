#include <bits/stdc++.h>
using namespace std;

using db = double;
const db eps = 1e-6;
int sgn(db a, db b = 0) {
	a -= b;
	return (a > eps) - (a < -eps);
}

#define op operator
struct poi {
	db x, y, z;
	void r() { cin >> x >> y >> z; }
	void w() { cout << x << ' ' << y << ' ' << z << '\n'; }
	poi op -(poi p) {
		return {x - p.x, y - p.y, z - p.z};
	}
	poi op +(poi p) {
		return {x + p.x, y + p.y, z + p.z};
	}
	poi op *(db d) {
		return {x * d, y * d, z * d};
	}
	db dot(poi p) {
		return x * p.x + y * p.y + z * p.z;
	}
	poi cross(poi p) {
		return {y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x};
	}
	db len2() { return dot(*this); }
	db len() { return sqrt(len2()); }
	poi proj(poi p, poi q) {
		db s = (q - p).dot(*this - p) / (q - p).len2();
		return p + (q - p) * s;
	}
};

db isqrt(db x) {
	if(x <= 0)
		return 0;
	return sqrt(x);
}

db solve1(poi p, poi v, poi o, db r) {
	if(sgn((o - p).len(), r) <= 0)
		return 0;
	poi proj = o.proj(p, p + v);
	if(sgn((o - proj).len(), r) > 0)
		return 1e10;
	if(sgn((proj - p).dot(v)) < 0)
		return 1e10;
	db h = (o - proj).len();
	db s = isqrt(r * r - h * h);
	return ((proj - p).len() - s) / v.len();
}

db solve2(poi p, poi v, poi a, poi b, db r) {
	if(sgn(v.cross(b - a).len()) == 0)
		return 1e10;
	poi hor = (b - a) * (v.dot(b - a) / (b - a).len2());
	poi ver = v - hor;
	db ret = solve1(p, ver, p.proj(a, b), r);
	if(ret == 1e10)
		return ret;
	poi q = p + v * ret;
	db t = (q - a).dot(b - a) / (b - a).len2();
	if(sgn(t) >= 0 && sgn(t, 1) <= 0)
		return ret;
	return 1e10;
}

int main() {
	cout << fixed << setprecision(9);
	ios :: sync_with_stdio(0);
	poi a, v; db dsr;
	a.r(); v.r(); cin >> dsr;

	db ans = 1e10;
	int n; cin >> n;
	while(n --) {
		poi o; db r;
		o.r(); cin >> r;
		ans = min(ans, solve1(a, v, o, dsr + r));
		int m; cin >> m;
		while(m --) {
			poi p; p.r();
			ans = min(ans, solve1(a, v, o + p, dsr));
			ans = min(ans, solve2(a, v, o, o + p, dsr));
		}
	}

	if(ans == 1e10)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
	return 0;
}