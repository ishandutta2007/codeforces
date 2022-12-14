#include <vector>
#include <stdio.h>
using namespace std;

const double ep = 1e-8;

int tmpx, tmpy;
struct pnt {
	double x, y;
	pnt(double x = 0, double y = 0) : x(x), y(y) {}
	pnt operator + (const pnt &b) const {return pnt(x + b.x, y + b.y);}
	pnt operator - (const pnt &b) const {return pnt(x - b.x, y - b.y);}
	double operator & (const pnt &b) const {return x * b.x + y * b.y;}
	double operator ^ (const pnt &b) const {return x * b.y - y * b.x;}
	void input() {scanf("%d %d", &tmpx, &tmpy), x = tmpx, y = tmpy;}
	void print() {printf("%.2lf %.2lf\n", x, y);}
	double dist() {return x * x + y * y;}
};

typedef vector <pnt> poly;

#define N 3030

int n, m;
poly u, v;
pnt p, q;
double r;

bool func(pnt a, pnt b) {
	double mn = min(a.dist(), b.dist());
	double mx = max(a.dist(), b.dist());
	if (((a & (a - b)) > 0) && ((b & (b - a)) > 0) && (a - b).dist() > ep) mn = (a ^ b) * (a ^ b) / (a - b).dist();

	return (mx + ep > r) && (mn - ep < r);
}

int main() {
	p.input();
	scanf("%d", &n);
	u.resize(n);
	for (int i = 0; i < n; i ++) u[i].input();
	q.input();
	scanf("%d", &m);
	v.resize(m);
	for (int i = 0; i < m; i ++) v[i].input();
	r = (p - q).dist();
    bool flag = 0;
    for (int i = 0; i < n && !flag; i ++) for (int j = 0; j < m && !flag; j ++) {
    	if (func(u[i] - p - v[j] + q, u[i] - p - v[(j+1)%m] + q)) flag = 1;
    	else if (func(u[i] - p - v[j] + q, u[(i+1)%n] - p - v[j] + q)) flag = 1;
    }
    if (flag) puts("YES");
    else puts("NO");

	return 0;
}