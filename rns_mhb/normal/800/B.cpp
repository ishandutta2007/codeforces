#include <bits/stdc++.h>
using namespace std;
#define N 1010

const double ep = 1e-8;
const double pi = 3.14159265358979323846264338327950288L;
struct pnt {
    double x, y;
    pnt(double x = 0, double y = 0) : x(x), y(y) {}
    pnt operator + (const pnt &b) {
        return pnt(x + b.x, y + b.y);
    }
    pnt operator - (const pnt &b) {
        return pnt(x - b.x, y - b.y);
    }
    pnt operator * (const double &b) {
        return pnt(x * b, y * b);
    }
    pnt operator / (const double &b) {
        return pnt(x / b, y / b);
    }
    double operator & (const pnt &b) {
        return x * b.x + y * b.y;
    }
    double operator ^ (const pnt &b) {
        return x * b.y - b.x * y;
    }
    double dist() {
        return sqrt(x * x + y * y);
    }
    void input() {
        scanf("%lf %lf", &x, &y);
    }
    void print() {
        printf("%.12lf %.12lf\n", x, y);
    }
}p[N];

double dist_line(pnt a, pnt b, pnt c) {
	return abs(a - b ^ c - b) / (b - c).dist();
}

double ans = 1e12;
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) p[i].input();
	p[0] = p[n], p[n+1] = p[1];
	for (int i = 1; i <= n; i ++) ans = min(ans, dist_line(p[i], p[i-1], p[i+1]));
	printf("%.12lf", ans / 2);
}