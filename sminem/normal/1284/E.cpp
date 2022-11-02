#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
	pt operator- (pt b) const {
		return {x-b.x, y-b.y};
	}
	bool operator== (pt b) const {
		return x == b.x && y == b.y;
	}
	bool operator< (pt b) const {
		if (x != b.x)
			return x < b.x;
		return y < b.y;
	}
};

ll det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

ll sq(ll x) {
	return x*x;
}

ll d2(pt a, pt b) {
	return sq(a.x-b.x) + sq(a.y-b.y);
}

ll sp(pt a, pt b) {
	return a.x*b.x + a.y*b.y;
}

bool kolin(pt a, pt b, pt c) {
	if (det(a, b, c) != 0)
		return false;
	return b == a || b == c || sp(a-b, b-c) > 0;
}

ll sgn(ll x) {
	if (x < 0) return -1;
	else if (x == 0) return 0;
	else return 1;
}

bool sek(pt a, pt b, pt c, pt d) {
	return
		sgn(det(a, b, c)) * sgn(det(a, b, d)) == -1
	 && sgn(det(c, d, a)) * sgn(det(c, d, b)) == -1;
}

bool pip(pt b, pt* a, int n) {
	ld w = 0;
	for (int i=0; i<n; i++) {
		int j = (i+1) % n;

		ld arg = sp(b - a[i], b - a[j]);
		arg /= sqrt(d2(b, a[i]));
		arg /= sqrt(d2(b, a[j]));
		arg = max(arg, (ld)-1);
		arg = min(arg, (ld)1);

		if (det(b, a[i], a[j]) < 0)
			w += acos(arg);
		else
			w -= acos(arg);
	}

	return abs(w) > 1.5;
}

ll area(pt* a, int n) {
	ll s = 0;
	for (int i=1; i<n-1; i++)
		s += det(a[0], a[i], a[i+1]);
	return s;
}

basic_string<pt> hull_half(basic_string<pt> a) {
	basic_string<pt> b;
	for (pt p : a) {
		while (b.size() >= 2 && det(b[b.size()-2], b[b.size()-1], p) < 0)
			b.pop_back();
		b += p;
	}
	return b;
}

basic_string<pt> hull(basic_string<pt> a) {
	sort(a.begin(), a.end());
	auto p = hull_half(a);
	p.pop_back();
	reverse(a.begin(), a.end());
	auto q = hull_half(a);
	q.pop_back();
	return p + q;
}

int n;
pt a[2505];

void proba1() {
	int x = 0;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			for (int k=j+1; k<n; k++) {
				for (int l=k+1; l<n; l++) {
					basic_string<pt> b = {a[i], a[j], a[k], a[l]};
					if (hull(b).size() == 3)
						x++;
				}
			}
		}
	}
	cerr << x*(n-4)/2 << '\n';
}

struct ang {
	bool operator() (const pt& a, const pt& b) const {
		bool u = a < pt{0, 0};
		bool v = b < pt{0, 0};
		if (u != v)
			return u;
		return det(a, b, {0, 0}) > 0;

		// return atan2(a.y, a.x) < atan2(b.y, b.x);
	}
};

void proba2() {
	ll alfa = 0;
	for (int i=0; i<n; i++) {
		vector<pt> b;
		for (int j=0; j<n; j++) {
			if (j != i)
				b.push_back(a[i] - a[j]);
		}
		int m = n-1;
		sort(b.begin(), b.end(), ang());

		// for (auto [x, y] : b)
		// 	cerr << "Sorted " << x << ' ' << y << '\n';

		int q = 0, g = 0;
		for (int p=0; p<m; p++) {
			while (g < m && det({0, 0}, b[p], b[q]) >= 0)
				q = (q+1) % m, g++;
			// cerr << b[p].x << ' ' << b[p].y << " SRANJE ";
			// cerr << p << ' ' << q << " -> " << g << '\n';
			alfa += (g-1)*(g-2)/2;
			if (g == 0)
				q = (q+1) % m;
			else
				g--;
		}
	}

	ll bn = n*(n-1ll)*(n-2)*(n-3)/24;
	ll rez = 4*bn-alfa;

	cerr << "alfa = " << alfa << '\n';
	cerr << "bn   = " << bn << '\n';
	cerr << "rez = " << rez << '\n';
	
	cout << rez * (n-4) / 2 << '\n';
	// cout << sol*(n-4) << '\n';
}

void proba3() {
	ll sol = 0;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			for (int k=0; k<n; k++) {
				if (k == i || k == j)
					continue;
				for (int l=k+1; l<n; l++) {
					if (l == i || l == j)
						continue;

					if ((det(a[i], a[j], a[k]) > 0) == (det(a[i], a[j], a[l]) > 0))
						sol++;
				}
			}
		}
	}
	cerr << sol << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].x >> a[i].y;

	// proba1();	
	proba2();	
	// proba3();	
}