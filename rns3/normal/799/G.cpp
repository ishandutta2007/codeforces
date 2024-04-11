#include <bits/stdc++.h>
using namespace std;

const double ep = 1e-6;
const double eps = 4e-5;
const double pi = acos(-1);

int tmpx, tmpy;
struct pnt{
	double x, y;
	pnt(double x = 0, double y = 0) : x(x), y(y) {}
	pnt operator + (const pnt &b) const {return pnt(x + b.x, y + b.y);}
	pnt operator - (const pnt &b) const {return pnt(x - b.x, y - b.y);}
	pnt operator * (const double &b) const {return pnt(x * b, y * b);}
	pnt operator / (const double &b) const {return pnt(x / b, y / b);}
	double operator & (const pnt &b) const {return x * b.x + y * b.y;}
	double operator ^ (const pnt &b) const {return x * b.y - y * b.x;}
	double dist() {return sqrt(x * x + y * y);}
	void input() {scanf("%d %d", &tmpx, &tmpy), x = tmpx, y = tmpy;}
};

#define N 10101

int n, Q;
pnt p[N<<1], q;
double s[N<<1], area;

void prep() {
	for (int i = 0, j = n - 1; i < j; i ++, j --) swap(p[i], p[j]);
	for (int i = 0; i <= n; i ++) p[i+n] = p[i];
	s[0] = 0;
	for (int i = 1; i <= 2 * n; i ++) s[i] = s[i-1] + (p[i-1] ^ p[i]);
	area = s[n];
}

double dist(pnt &p, double &a, double &b, double &c) {
	return p.x * a + p.y * b + c;
}

pnt intersect(pnt &a, pnt &b, double &A, double &B, double &C) {
	double a_ = dist(a, A, B, C);
	double b_ = dist(b, A, B, C);
	return (a * b_ - b * a_) / (b_ - a_);
}

double calc(double alpha) {
	double A = sin(alpha), B = -cos(alpha), C = -A * q.x - B * q.y;
	int st, en, u, v, mid;
	double st_, en_, u_, v_, mid_;

	st = 0, en = n - 1;
	st_ = dist(p[st], A, B, C);
	en_ = dist(p[en], A, B, C);
	while (st < en) {
		u = (st + en - 1) >> 1;
		v = u + 1;
		u_ = dist(p[u], A, B, C);
		v_ = dist(p[v], A, B, C);
		if ((st_ <= en_ && st_ <= v_) || (u_ <= en_ && u_ <= v_)) en = u;
		else st = v;
	}
	int mn = st;

	st = 0, en = n - 1;
	st_ = dist(p[st], A, B, C);
	en_ = dist(p[en], A, B, C);
	while (st < en) {
		u = (st + en - 1) >> 1;
		v = u + 1;
		u_ = dist(p[u], A, B, C);
		v_ = dist(p[v], A, B, C);
		if ((st_ >= en_ && st_ >= v_) || (u_ >= en_ && u_ >= v_)) en = u;
		else st = v;
	}
	int mx = st;

	st = mn, en = mx + n;
	while (st < en - 1) {
		mid = (st + en) >> 1;
		mid_ = dist(p[mid], A, B, C);
		if (mid_ < 0) st = mid;
		else en = mid;
	}
	int ans1 = st % n;
	pnt crs1 = intersect(p[ans1], p[ans1+1], A, B, C);

	st = mx, en = mn + n;
	while (st < en - 1) {
		mid = (st + en) >> 1;
		mid_ = dist(p[mid], A, B, C);
		if (mid_ > 0) st = mid;
		else en = mid;
	}
	int ans2 = st % n;
	pnt crs2 = intersect(p[ans2], p[ans2+1], A, B, C);

	if (ans1 >= ans2) ans2 += n;

	double rlt = (p[ans2] ^ crs2) + (crs2 ^ crs1) + (crs1 ^ p[ans1+1]) + s[ans2] - s[ans1+1];
	if (((crs1 - crs2) & pnt(cos(alpha), sin(alpha))) < 0) rlt = area - rlt;
	return rlt;
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d", &n, &Q);
	for (int i = 0; i < n; i ++) p[i].input();
	prep();
	while (Q --) {
		q.input();
		double st = 0, en = pi, mid, tmp;
		bool stt = (calc(st) < area / 2), enn = !stt, midd;
		for (int step = 1; step <= 31; step ++) {
			mid = (st + en) / 2;
			tmp = calc(mid);
			midd = (tmp < area / 2);
			if (fabs(tmp * 2 - area) / area < eps) break;
			if (midd == stt) st = mid;
			else en = mid;
		}
		printf("%.20lf\n", (st + en) / 2);
	}

	return 0;
}