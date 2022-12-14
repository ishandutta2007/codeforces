#include <bits/stdc++.h>
using namespace std;
#define M 100010
#define ep 1e-9

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
} p[M], pp[M];

double ans, len[M];
int n;

double dist(pnt a, pnt b, pnt c) {return fabs(b - a ^ c - a) / (b - c).dist();}

void solve() {

	if ((p[2] - p[0] ^ p[1] - p[0]) > ep) {
		for (int i = 0; i < n / 2; i++) swap(p[i], p[n - 1 - i]);
	}
	for (int i = 0; i < n; i++) p[i+n] = p[i]; p[2*n] = p[0];

	for (int i = 0; i < n; i++) {
		if ((p[i+1] - p[i] & p[i+2] - p[i+1]) < ep) {printf("%.12lf\n", 0.); exit(0);}
	}

	double last = -1, area = 0;
	int id = -1;
	for (int i = 0; i < n; i++) len[i] = (p[i+1] - p[i]).dist();
	for (int i = n - 1; i >= 0; i--) {
		double tmp = p[i] - p[0] & p[0] - p[1];
		if (tmp < last + ep) break;
		last = tmp; id = i;
		area += fabs(p[i] - p[0] ^ p[i+1] - p[0]);
	}
	ans = min(ans, last * dist(p[id], p[0], p[1]) / len[0] - area);

	for (int i = 1; i < n; i++) {
		area += fabs(p[id] - p[i] ^ p[id] - p[i-1]);
		while ((p[id] - p[i] & p[i] - p[i+1]) < ep) {
			area -= fabs(p[id] - p[i] ^ p[id+1] - p[i]); id++;
		}
		last = p[id] - p[i] & p[i] - p[i+1];
		while (1) {
			double tmp = p[id+1] - p[i] & p[i] - p[i+1];
			if (tmp < last - ep) break;
			last = tmp; area -= fabs(p[id] - p[i] ^ p[id+1] - p[i]);
			id++;
		}
		if (id >= n) id -= n;
		ans = min(ans, last * dist(p[id], p[i], p[i+1]) / len[i] - area);
	}
}

int main() {
	ans = 1e18;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) p[i].input(), pp[i] = p[i];
	solve();
	for (int i = 0; i < n; i++) p[i] = pp[i], p[i].x = -p[i].x;
	solve();
	printf("%.12lf\n", ans / 2);
}