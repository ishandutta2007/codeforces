#include <bits/stdc++.h>
using namespace std;

#define N 1010
#define M 1000100
#define X first
#define Y second

typedef long double LD;

const double ep = 1e-9, pi = acos(-1);

struct pnt {
	double x, y;
	pnt (double x = 0, double y = 0): x(x), y(y) {}
	inline pnt operator - (const pnt &a) const { return pnt(x - a.x, y - a.y); }
	inline pnt operator + (const pnt &a) const { return pnt(x + a.x, y + a.y); }
	inline pnt operator * (const double &a) const { return pnt(x * a, y * a); }
	inline pnt operator / (const double &a) const { return pnt(x / a, y / a); }
	inline double operator & (const pnt &a) const { return x * a.x + y * a.y; }
	inline double operator ^ (const pnt &a) const { return x * a.y - y * a.x; }
	inline void input() { x = y = 0, scanf("%lf %lf", &x, &y); }
	inline void print() { printf("%lf %lf\n", x, y); }
	inline bool operator < (const pnt &a) const {
		return (fabs(x - a.x) > ep) ? (x < a.x) : (y < a.y);
	}
	inline bool operator == (const pnt &a) const {
		return fabs(x - a.x) < ep && fabs(y - a.y) < ep;
	}
	inline pnt Rotate(const double &angle) {
		pnt R = pnt(sin(angle), cos(angle)), C = *this;
		return pnt(C ^ R, C & R);
	}
	inline double dist() { return sqrt(x * x + y * y); }
	inline pnt norm() { return (*this) / dist(); }
} A, B, C, p[11];

double dist(pnt a) {return sqrt(a.x * a.x + a.y * a.y);}

pnt turn_R(pnt O, pnt A) {
	pnt B = A - O, C = O;
	C.x -= B.y;
	C.y += B.x;
	return C;
}

pnt reflex(pnt O, pnt A) {
	return O * 2 - A;
}

pnt intersect(pnt a, pnt b, pnt c, pnt d) {
	double den = a - b ^ c - d;
	double x = (a - d ^ c - d) / den;
	return a * (1 - x) + b * x;
}

bool inside(pnt a, pnt b, pnt c) {
	pnt dr = a - b ^ a - c;
	if (dist(dr) > ep) return 0;	///	A is not on the segment BC
	double d = a - b & a - c;
	return d < ep;
}

bool intersect_seg(pnt a, pnt b, pnt c, pnt d) {
	double den = a - b ^ c - d;
	if (fabs(den) < ep) return 0;
	pnt e = intersect(a, b, c, d);
	if (inside(e, a, b)) return 1;
	return 0;
}

double wide(pnt A, pnt B, pnt C) {
	return abs((A ^ B) + (B ^ C) + (C ^ A));
}

bool ok(pnt A, pnt B, pnt C) {
	double den = A - B ^ B - C;
	if (fabs(den) < ep) return 0;
	pnt E0 = (A + C) / 2, F0 = (A + B) / 2;
	pnt E1 = turn_R(E0, A), F1 = turn_R(F0, A);
	pnt E2 = reflex(A, E0), E3 = reflex(A, E1);
	pnt F2 = reflex(A, F0), F3 = reflex(A, F1);
	p[0] = intersect(E0, E1, F2, F3);
	p[1] = intersect(F0, F1, E2, E3);
	p[2] = reflex(B, p[1]);
	p[3] = reflex(C, p[0]);
	if (intersect_seg(p[0], p[3], p[1], p[2])) return 0;
	double S = 0;
	for (int i = 0; i < 4; i ++) S += p[i] ^ p[(i+1)%4];
	S = abs(S);
	for (int i = 0; i < 4; i ++) {
		if (wide(p[i], p[(i+1)%4], p[(i+2)%4]) > S - ep) return 0;
	}
	return 1;
}

void print() {
	puts("YES");
	for (int i = 0; i < 3; i ++) printf("%.9lf %.9lf ", p[i].x, p[i].y);
	printf("%.9lf %.9lf\n", p[3].x, p[3].y);
}

int main() {
	int t;
	for (scanf("%d", &t); t --;) {
		A.input(), B.input(), C.input();
		if (ok(A, B, C)) print();
		else if (ok(B, C, A)) print();
		else if (ok(C, A, B)) print();
		else puts("NO\n");
	}
	return 0;
}