#include <bits/stdc++.h>
using namespace std;
#define M 400010
#define ep 1e-10

const double pi = acos(-1);

struct pnt {
	double x, y;
	pnt (double x = 0, double y = 0) : x(x), y(y) {}
	pnt operator +(pnt a) {return pnt(x + a.x, y + a.y);}
	pnt operator -(pnt a) {return pnt(x - a.x, y - a.y);}
	pnt operator /(double a) {return pnt(x / a, y / a);}
	pnt operator *(double a) {return pnt(x * a, y * a);}
	double operator ^ (pnt a) {return x * a.y - y * a.x;}
	double operator & (pnt a) {return x * a.x + y * a.y;}
	double dist() {return sqrt(x * x + y * y);}
	void input() {scanf("%lf %lf", &x, &y);}
	void print() {printf("%lf %lf\n", x, y);}
} p[M], o, O;

int n, A;
double dis[M];

pnt cr[3];

inline pnt rot(pnt p) { return pnt(-p.y, p.x); }

int intersect(pnt c, double r, pnt cc, double rr) {
	double d = (c - cc).dist();
	if (r + rr < d + ep || r + d < rr + ep || rr + d < r + ep) return 0;
	double x = (r * r - rr * rr + d * d) / (d * 2);
	pnt cp = (c * (d - x) + cc * x) / d;
	double h = sqrt(r * r - x * x);
	pnt dv = rot(cc - c) * h / d ;
	cr[0] = cp - dv;
	cr[1] = cp + dv;
	return 1;
}

double angle(pnt a) {return atan2(a.y, a.x);}

int cnt;

pair <double, pair <int, int> > s[M];

void ins(double l, double r, int j) {
	if (l > r) swap(l, r);
	s[cnt++] = make_pair(l, make_pair(-1, j));
	s[cnt++] = make_pair(r, make_pair(1, j));
}

int q[M];

bool check(double R) {
	cnt = 0;
	int N = 0;
	for (int i = 0; i < n; i++) {
		if ((O - p[i]).dist() + dis[i] < R) return 1;
	}
	for (int i = 0; i < n; i++) {
		if (intersect(O, R, p[i], dis[i])) {
			double al = angle(cr[0] - O), be = angle(cr[1] - O);
			ins(al, be, ++N);
		}
	}
	sort(s, s + cnt);
	int t = 0;
	for (int i = 0; i < cnt; i++) {
		pair <int, int> A = s[i].second;
		if (A.first == -1) {
			q[t++] = A.second;
		}
		else {
			if (t && q[--t] != A.second) return 1;
		}
	}
	return 0;
}

int main() {
	//freopen("G.in", "r", stdin);
	scanf("%d %d", &n, &A);
	O = pnt(-A, 0), o = pnt(A, 0);
	for (int i = 0; i < n; i++) p[i].input();
	for (int i = 0; i < n; i++) dis[i] = (o - p[i]).dist();
	double l = 0, r = 2 * A;
	for (int step = 0; step < 50; step++) {
		double mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	printf("%.20lf\n", l);
}