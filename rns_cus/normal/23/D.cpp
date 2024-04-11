//23_D
#include <bits/stdc++.h>
using namespace std;

#define ep 1e-7

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
}p[4], a[4];

double dist(pnt a) {return sqrt(a & a);}

pnt rot(pnt p) {return pnt(-p.y, p.x);}

bool intersect_line(pnt a, pnt b, pnt c, pnt d, pnt &res) {
	double den = a - b ^ c - d;
	if (fabs(den) < ep) return 0;		//The two lines are parallel...
	double x = (a - d ^ c - d) / den;
	res = a * (1 - x) + b * x;
	return 1;						//The two lines are intersect...
}

bool inside(pnt a, pnt b, pnt c) {
	//if pnt a is on the segment between pnt b and pnt c, return 1.
	double A = a - b & a - c;
	double B = a - b ^ a - c;
	if (fabs(B) > ep) return 0;
	return A < ep;
}

int intersect_segment(pnt a, pnt b, pnt c, pnt d, pnt &res) {
	double s1 = b - a ^ d - c, s2 = b - c ^ a - c, s;
	double t1 = s1, t2 = c - a ^ d - a;
	if (fabs(s1) < ep) {
		double dd = c - b ^ a - b;
		if (fabs(dd) > ep) return 2;	//parallel
		if (inside(a, c, d) || inside(b, c, d) ||
			inside(c, a, b) || inside(d, a, b)) return 1;	//overlap
		return 2;					//parallel
	}
	if (s1 < 0) s2 *= -1, t2 *= -1, s1 *= -1, t1 *= -1;
	if (-ep < s2 && s2 < s1 + ep && -ep < t2 && t2 < t1 + ep) {
		s = s2 / s1;
		res = c + ((d - c) * s);
		return 1;
	}
	return 0;
}

double area(pnt a, pnt b, pnt c){
    double aa = dist(b - c), bb = dist(c - a), cc = dist(a - b);
    double p = (aa + bb + cc) / 2;
    return sqrt(p * (p - aa) * (p - bb) * (p - cc));
}

bool inside_triangle(pnt a, pnt b, pnt c, pnt d){
    double aa = area(b, c, d), bb = area(c, a, d), cc = area(a, b, d);
    double tot = area(a, b, c);
    if(fabs(tot - aa - bb - cc) < ep) return 1;
    return 0;
}

bool find(pnt p, pnt q, pnt r){
    ///printf("(%lf %lf)  (%lf %lf)  (%lf %lf)\n", p.x, p.y, q.x, q.y, r.x, r.y);
    pnt pq = (p + q) / 2, qr = (q + r) / 2;
    pnt pq2 = rot(q - pq) + pq;
    pnt qr2 = rot(r - qr) + qr;

    if(!intersect_line(q * 2 - pq, q * 2 - pq2, qr, qr2, a[2])) return 0;

    a[1] = q * 2 - a[2];
    a[0] = p * 2 - a[1];
    a[3] = r * 2 - a[2];
    ///for(int i = 0; i < 4; i ++) printf("(%lf %lf)\n", a[i].x, a[i].y);

    pnt d;
    if(intersect_segment(a[0], a[1], a[2], a[3], d) == 1) return 0;
    if(intersect_segment(a[1], a[2], a[0], a[3], d) == 1) return 0;
    if(inside_triangle(a[0], a[1], a[2], a[3])) return 0;
    if(inside_triangle(a[1], a[2], a[3], a[0])) return 0;
    if(inside_triangle(a[2], a[3], a[0], a[1])) return 0;
    if(inside_triangle(a[3], a[0], a[1], a[2])) return 0;
    return 1;
}

int main(){
    ///freopen("23_d.in", "r", stdin);

    int TC;
    for(scanf("%d", &TC); TC --;) {
        for(int i = 0; i < 3; i ++) p[i].input();

        bool ok = 0;
        for(int i = 0; i < 3; i ++) if(!ok) {
            for(int j = 0; j < 3; j ++) if(j != i) {
                int k = 3 - i - j;
                if(find(p[i], p[j], p[k])) {
                    ///printf("%d %d %d\n", i, j, k);
                    ok = 1; break;
                }
            }
        }

        if(!ok) puts("NO\n");
        else {
            puts("YES");
            for(int i = 0; i < 4; i ++) printf("%.9lf %.9lf ", a[i].x, a[i].y);
            puts("");
        }
    }
    ///return 9;
}