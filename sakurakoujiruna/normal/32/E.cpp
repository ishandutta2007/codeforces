#include <bits/stdc++.h>
using namespace std;

using db = double;
const db eps = 1e-9;
int sgn(db a, db b = 0) {
	a -= b;
	return (a > eps) - (a < -eps);
}

#define op operator

struct poi {
	db x, y;
	void r() { cin >> x >> y; }
	poi op -(poi p) {
		return {x - p.x, y - p.y};
	}
	poi op +(poi p) {
		return {x + p.x, y + p.y};
	}
	poi op *(db d) {
		return {x * d, y * d};
	}
	db dot(poi p) {
		return x * p.x + y * p.y;
	}
	db cross(poi p) {
		return x * p.y - y * p.x;
	}
	poi proj(poi a, poi b) {
		db s = (*this - a).dot(b - a) / (b - a).dot(b - a);
		return a + (b - a) * s;
	}
};

db xmul(poi a, poi b, poi c) {
	return (b - a).cross(c - a);
}

bool inter1(poi a, poi b, poi p, poi q) {
	if(sgn(xmul(a, b, p)) * sgn(xmul(a, b, q)) >= 0)
		return false;
	db t = (p - a).cross(q - p) / (b - a).cross(q - p);
	return sgn(t) > 0 && sgn(t, 1) < 0;
} // pqab, pq

bool inter2(poi a, poi b, poi p, poi q) {
	if(sgn(xmul(a, b, p)) * sgn(xmul(a, b, q)) > 0)
		return false;
	if(sgn((b - a).cross(q - p)) == 0) {
		db s = (p - a).dot(b - a) / (b - a).dot(b - a);
		db t = (q - a).dot(b - a) / (b - a).dot(b - a);
		if(s > t) swap(s, t);
		if(sgn(s, 1) > 0 || sgn(t) < 0)
			return false;
		return true;
	}
	db t = (p - a).cross(q - p) / (b - a).cross(q - p);
	return sgn(t) > 0 && sgn(t, 1) < 0;
} // pqab, pq

int main() {
	ios :: sync_with_stdio(false);
	poi p1, p2, w1, w2, m1, m2;
	p1.r(); p2.r();
	w1.r(); w2.r();
	m1.r(); m2.r();

	if((!inter2(p1, p2, m1, m2) || sgn((m2 - m1).cross(p2 - p1)) == 0) &&
		!inter2(p1, p2, w1, w2))
		cout << "YES\n";
	else if(sgn(xmul(m1, m2, p1)) * sgn(xmul(m1, m2, p2)) > 0) {
		poi proj = p1.proj(m1, m2);
		poi sym = proj + proj - p1;
		db t = (sym - m1).cross(p2 - sym) / (m2 - m1).cross(p2 - sym);
		poi ref = m1 + (m2 - m1) * t;
		if(sgn(t) >= 0 && sgn(t, 1) <= 0 &&
			!inter2(p1, ref, w1, w2) && !inter2(ref, p2, w1, w2))
			cout << "YES\n";
		else
			cout << "NO\n";
	} else
		cout << "NO\n";

	return 0;
}