#include <bits/stdc++.h>
using namespace std;

const double ep = 1e-6;
const double INF = 2e9;

struct pnt {
	double x, y;
	pnt(double x = 0, double y = 0) : x(x), y(y) {}
	pnt operator + (const pnt &b) const {return pnt(x + b.x, y + b.y);}
	pnt operator - (const pnt &b) const {return pnt(x - b.x, y - b.y);}
	pnt operator * (const double &b) const {return pnt(x * b, y * b);}
	pnt operator / (const double &b) const {return pnt(x / b, y / b);}
	double operator & (const pnt &b) const {return x * b.x + y * b.y;}
	double operator ^ (const pnt &b) const {return x * b.y - y * b.x;}
	double dist() {return sqrt(x * x + y * y);}
	void input() {scanf("%lf %lf", &x, &y);}
};

#define N 101010
pnt p[N];

double dist(pnt a, pnt b, pnt c) {
	return fabs((a - b) ^ (b - c)) / (b - c).dist();
}

int n;

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) p[i].input();
	double ans = INF;
	for (int i = 0; i < n; i ++) {
		for (int j = 0, k; j < n; j ++) {
			k = (j + 1) % n;
			if (j == i || i == k) continue;
			ans = min(ans, dist(p[i], p[j], p[k]));
		}
	}
	for (int i = 0; i < n; i ++) {
		int j = (i + 1) % n, k = (i + n - 1) % n;
		ans = min(ans, dist(p[i], p[j], p[k]));
	}
	printf("%.9lf\n", ans / 2);

	return 0;
}