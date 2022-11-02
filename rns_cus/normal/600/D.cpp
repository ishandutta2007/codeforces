#include <bits/stdc++.h>
using namespace std;

typedef long double LD;

const LD ep = 1e-10, pi = acos(-1);

struct pnt {
	LD x, y;
	pnt (LD x = 0, LD y = 0): x(x), y(y) {}
	inline pnt operator - (const pnt &a) const { return pnt(x - a.x, y - a.y); }
	inline pnt operator + (const pnt &a) const { return pnt(x + a.x, y + a.y); }
	inline pnt operator * (const LD &a) const { return pnt(x * a, y * a); }
	inline pnt operator / (const LD &a) const { return pnt(x / a, y / a); }
	inline LD operator & (const pnt &a) const { return x * a.x + y * a.y; }
	inline LD operator ^ (const pnt &a) const { return x * a.y - y * a.x; }
	inline void input() { double xx, yy; scanf("%lf %lf", &xx, &yy); x = xx, y = yy; }
	void FastInput() {
		int a, b;
		cin >> a >> b;
		x = 1.0 * a;
		y = 1.0 * b;
	}
	inline void print() { printf("%lf %lf\n", (double)x, (double) y); }
	inline bool operator < (const pnt &a) const {
		if (fabs(x - a.x) > ep) return x < a.x;
		return y < a.y;
	}
	inline bool operator == (const pnt &a) const {
		return fabs(x - a.x) < ep && fabs(y - a.y) < ep;
	}
	inline pnt Rotate(const LD &angle) {
		pnt R = pnt(sin(angle), cos(angle)), C = *this;
		return pnt(C ^ R, C & R);
	}
	inline LD dist() { return sqrt(x * x + y * y); }
	inline pnt norm() { return (*this) / dist(); }
} O[3], p[3];

double R[3];

LD dist(pnt a) {return sqrt(a.x * a.x + a.y * a.y);}

LD common_circles(pnt c, LD r, pnt cc, LD rr){
	if (r<rr){
		swap(c,cc);
		swap(r,rr);
	}
	LD d=dist(c-cc);
	if (rr+d<=r + ep) return pi*rr*rr;
	if (r+rr<=d + ep) return 0;
	LD x=2*acos((r*r-rr*rr+d*d)/(d*2*r));
	LD xx=2*acos((-r*r+rr*rr+d*d)/(d*2*rr));
	LD res1=0.5*r*r*(x-sin(x));
	LD res2=0.5*rr*rr*(xx-sin(xx));
	return res1+res2;
}

int main() {
	O[1].input();

	scanf("%lf", &R[1]);
	O[2].input();

	scanf("%lf", &R[2]);
	//printf("%lf %lf\n", R[1], R[2]);
	printf("%.12lf\n", (double)common_circles(O[1], R[1], O[2], R[2]));
	return 0;
}