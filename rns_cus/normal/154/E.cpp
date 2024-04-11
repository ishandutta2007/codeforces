#include <bits/stdc++.h>
using namespace std;
#define M 200010
#define ep 1e-9

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
} p[M], q[M], con[M];

double r;
int m, n;

double dist(pnt a) {return sqrt(a & a);}

double angle(pnt a, pnt b, pnt c) {return acos(((a - b) & (c - b)) / dist(a - b) / dist(b - c));}

bool check(pnt a, pnt b, pnt c) {
	double al = angle(a, b, c);
	double be = asin(dist(a-c)/2/r);
	return (al + be > pi - ep);
}
double calc(pnt a, pnt b) {
	double be = asin(dist(a-b)/2/r);
	return (be - sin(2 * be) / 2) * r * r;
}

bool cmp(pnt a, pnt b) {
	if (fabs(a.x - b.x) > ep) return a.x < b.x;
	return a.y < b.y;
}

bool cmp1(pnt a, pnt b) {
	double tmp = a - p[0] ^ b - p[0];
	if (fabs(tmp) > ep) return tmp > 0;
	double u = a - p[0] & a - p[0], v = b - p[0] & b - p[0];
	return u < v;
}

void Graham() {
	sort(p, p + n, cmp);
	sort(p + 1, p + n, cmp1);
	int k = 0;
	for (int i = 0; i < n; i ++) {
		while (k > 1 && (con[k - 1] - con[k - 2] ^ p[i] - con[k - 2]) < ep) k --;
		con[k ++] = p[i];
	}
	for (int i = 0; i < k; i++) p[i] = con[i]; n = k;
}

int main() {
	//freopen("E.in", "r", stdin);
	scanf("%d %lf", &n, &r);
	for (int i = 0; i < n; i++) p[i].input();
	Graham();

	int s=1, e=2;
	q[1] = p[0], q[2] = p[1];
	for (int i=2; i<n; ++i) if (!check(q[s], p[i], q[e])) {
		for (; s<e && check(q[s+1], q[s], p[i]); ++s);
		for (; s<e && check(q[e-1], q[e], p[i]); --e);
		q[++e] = p[i];
	}
	q[e+1] = q[s];
	double area = 0;
	for (int i = s; i <= e; i++) area += (q[i] ^ q[i+1]);
	area = fabs(area) / 2;
	for (int i = s; i <= e; i++) area += calc(q[i], q[i+1]);
	printf("%.12lf\n", area);
}