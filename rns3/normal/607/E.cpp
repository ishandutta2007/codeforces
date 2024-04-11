#include <bits/stdc++.h>
using namespace std;
#define M 800010
#define ep 1e-9
typedef long long LL;
const double pi = acos(-1);
int n, m;
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
	void input() {scanf("%lf %lf", &x, &y); x /= 1000, y /= 1000;}
	void print() {printf("%lf %lf\n", x, y);}
} o, st[M], en[M];

double a[M], b[M], ans;

pnt pa, pb;

bool intersect(pnt cp, double r, pnt st, pnt en) {
	double len = (en - st).dist();
	double d = fabs(cp - st ^ en - st) / len;
	if (d >= r) return 0;
	double dx =sqrt(r * r - d * d);
	double x = (cp - st & en - st) / len;
	double a = (x - dx) / len, b = (x + dx) / len;
	pa = st * (1 - a) + en * a;
	pb = st * (1 - b) + en * b;
	return 1;
}

inline double get(pnt a, pnt b) {return atan2(b.y - a.y, b.x - a.x);}

pair <double, pair <int, int> > p[M];

int cnt, s[M], bit[M];

void ins(double l, double r, int id) {
	if (l > r) swap(l, r);
	p[cnt++] = make_pair(l, make_pair(1, id));
	p[cnt++] = make_pair(r, make_pair(-1, id));
}


void add(int x, int val) {for ( ; x <= cnt; x += (x & -x)) bit[x] += val;}
int qry(int x) {int r = 0; for ( ; x; x -= (x & -x)) r += bit[x]; return r;}

LL calc(double R) {
	cnt = 0;
	int N = 0;
	for (int i = 0; i < n; i++) {
		if (intersect(o, R, st[i], en[i])) {
			double al = get(o, pa), be = get(o, pb);
			if (al > be) swap(al, be);
			ins(al, be, ++N);
		}
	}
	sort(p, p + cnt);
	for (int i = 1; i <= cnt; i++) bit[i] = 0;
	LL tot = 0;
	for (int i = 0; i < cnt; i++) {
		pair <int, int> A = p[i].second;
		if (A.first != -1) {
			s[A.second] = i + 1; add(i + 1, 1);
		}
		else {
			tot += qry(i + 1) - qry(s[A.second]);
			add(s[A.second], -1);
		}
	}
	return tot;
}

bool cross(pnt a, pnt b, pnt c, pnt d, pnt &res) {
	double den = a - b ^ c - d;
	if (fabs(den) < ep) return 0;
	double x = (a - d ^ c - d) / den;
	res = a * (1 - x) + b * x;
	return 1;
}

int T, id[M], q[M], Q[M];

void calc_dist(double R) {
	cnt = 0;
	int N = 0;
	for (int i = 0; i < n; i++) {
		if (intersect(o, R, st[i], en[i])) {
			double al = get(o, pa), be = get(o, pb);
			if (al > be) swap(al, be);
			ins(al, be, ++N); id[N] = i;
		}
	}
	sort(p, p + cnt);
	int h, t = 0;
	for (int i = 0; i < cnt; i++) {
		pair <int, int> A = p[i].second;
		if (A.first != -1) {
			q[t++] = A.second;
		}
		else {
			h = 0;
			pnt res;
			while (t && q[--t] != A.second) {
				Q[h++] = q[t], T++;
				int j = id[A.second], k = id[q[t]];
				cross(st[j], en[j], st[k], en[k], res);
				ans += (o - res).dist();
			}
			while (h) q[t++] = Q[--h];
		}
	}
}

int main() {
	//freopen("E.in", "r", stdin);
	double x, y;
	scanf("%d", &n);
	o.input(); scanf("%d", &m);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &x, &y); x /= 1000, y /= 1000;
		st[i] = pnt(0, y), en[i] = pnt(1, x + y);
	}
	double l = 0, r = 1e10;
	for (int step = 0; step < 100; step++) {
		double mid = (l + r) / 2;
		if (calc(mid) > m) r = mid;
		else l = mid;
	}
	calc_dist(l);
	printf("%.20lf\n", ans + (m - T) * l);
}