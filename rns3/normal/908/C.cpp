#include <bits/stdc++.h>
using namespace std;

#define N 1005

const double ep = 1e-8;
const double INF = 1e18;
const double pi = 3.14159265358979323846264338327950288L;

struct pnt {
	double x, y;
	pnt(double x = 0, double y = 0) : x(x), y(y) {}
	pnt operator + (const pnt &b) {return pnt(x + b.x, y + b.y);}
	pnt operator - (const pnt &b) {return pnt(x - b.x, y - b.y);}
	pnt operator * (const double &b) {return pnt(x * b, y * b);}
	pnt operator / (const double &b) {return pnt(x / b, y / b);}
	double operator & (const pnt &b) {return x * b.x + y * b.y;}
	double operator ^ (const pnt &b) {return x * b.y - b.x * y;}
	bool operator < (const pnt &b) const {
		return abs(x - b.x) > ep ? x < b.x : y < b.y;
	}
	bool operator == (const pnt &b) {
		return abs(x - b.x) < ep && abs(y - b.y) < ep;
	}
	bool operator != (const pnt &b) {
		return abs(x - b.x) > ep || abs(y - b.y) > ep;
	}
	pnt rotate(double alpha) {
		pnt R = pnt(sin(alpha), cos(alpha)), C = *this;
		return pnt(C ^ R, C & R);
	}
	pnt rot() {return pnt(-y, x);}
	double dist() {return sqrt(x * x + y * y);}
	pnt norm() {return dist() > ep ? (*this) / dist() : pnt(1, 0);}
	void input() {scanf("%lf %lf", &x, &y);}
	void print() {printf("%.12lf %.12lf\n", x, y);}
};

int n;
pnt o[N];
double r, d;
double x[N];
double ans[N];
vector<pnt> now;
pnt rlt[4];

int inter_circle_line(pnt c, double r, pnt a, pnt b, pnt *rlt) {
	double len = (a - b).dist();
	double d = abs(a - c ^ b - c) / len;
	if (d >= r + ep) return 0;
	double dx = sqrt(r * r - d * d);
	double x = (c - a & b - a) / len;
	double ax = (x - dx) / len, bx = (x + dx) / len;
	rlt[0] = a * (1 - ax) + b * ax;
	rlt[1] = a * (1 - bx) + b * bx;
	return d <= r - ep ? 2 : 1;
}


void calc(int i) {
    double y = r;
    for (int j = 0; j < now.size(); j ++) {
        if (fabs(now[j].x - x[i]) > d) continue;
        inter_circle_line(now[j], d, pnt(x[i], 0), pnt(x[i], 1), rlt);
        if (rlt[0].y > rlt[1].y) swap(rlt[0], rlt[1]);
        y = max(y, rlt[1].y);
    }
    ans[i] = y;
    now.push_back(pnt(x[i], y));
}

int main() {
    scanf("%d %lf", &n, &r); d = 2 * r;
    now.clear();
    for (int i = 0; i < n; i ++) scanf("%lf", &x[i]);
    for (int i = 0; i < n; i ++) calc(i);
    for (int i = 0; i < n; i ++) printf("%.10lf%c", ans[i], i == n - 1 ? '\n' : ' ');
    return 0;
}