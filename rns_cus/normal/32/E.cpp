//E
#include <bits/stdc++.h>
using namespace std;

#define ep 1e-8

struct pnt{
    double x, y;
    pnt(double x = 0, double y = 0): x(x), y(y){}

    pnt operator - (pnt a) {return pnt(x-a.x, y-a.y);}
    pnt operator + (pnt a) {return pnt(x+a.x, y+a.y);}
    pnt operator * (double a) {return pnt(x*a, y*a);}
    pnt operator / (double a) {return pnt(x/a, y/a);}
    double operator ^ (pnt a) {return x*a.y-y*a.x;}
    double operator & (pnt a) {return x*a.x+y*a.y;}

    void input(){x = y = 0, scanf("%lf %lf", &x, &y);}
    void print(){printf("%lf %lf\n", x, y);}
}vv, pp, m[2], w[2];

bool inside(pnt a, pnt b, pnt c) {
	//if pnt a is on the segment between pnt b and pnt c, return 1.
	double A = a - b & a - c;
	double B = a - b ^ a - c;
	if (fabs(B) > ep) return 0;
	return A <= 0;
}

int intersect(pnt a, pnt b, pnt c, pnt d, pnt &res) {
	double s1 = b - a ^ d - c, s2 = b - c ^ a - c, s;
	double t1 = s1, t2 = c - a ^ d - a;
	if (fabs(s1) < ep) {
		double dd = c - b ^ a - b;
		if (fabs(dd) > ep) return 2;///parallel
		if (inside(a, c, d) || inside(b, c, d) || inside(c, a, b) || inside(d, a, b)) return 4;///overlap
		return 2;///parallel
	}
	if (s1 < 0) s2 *= -1, t2 *= -1, s1 *= -1, t1 *= -1;
	if (-ep < s2 && s2 < s1 + ep && -ep < t2 && t2 < t1 + ep) {
		s = s2 / s1;
		res = c + ((d - c) * s);
		return 1;
	}
	return 0;
}

pnt sym(pnt a, pnt b, pnt c) {	//AB  C 
	double tp = (c - a & b - a) / (b - a & b - a);
	pnt p = a * (1 - tp) + b * tp;		//AB  C 
	return p * 2 - c;
}

int main(){
    //freopen("e.in", "r", stdin);
    vv.input();
    pp.input();
    w[0].input(), w[1].input();
    m[0].input(), m[1].input();

    pnt d;
    int ww = intersect(w[0], w[1], vv, pp, d);
    int mm = intersect(m[0], m[1], vv, pp, d);
    if((ww == 0 || ww == 2) && (mm != 1)) {puts("YES"); return 0;}

    pnt ppp = sym(m[0], m[1], pp);
    pnt vvv = sym(m[0], m[1], vv);

    mm = intersect(m[0], m[1], vv, ppp, d);
    if(mm == 2 || mm == 0) {puts("NO"); return 0;}
    ww = intersect(w[0], w[1], vv, ppp, d);
    if(ww == 4 || ww == 1) {puts("NO"); return 0;}
    ww = intersect(w[0], w[1], pp, vvv, d);
    if(ww == 4 || ww == 1) {puts("NO"); return 0;}
    puts("YES");
    ///return 9;
}