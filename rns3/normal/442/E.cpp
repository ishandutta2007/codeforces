#include <bits/stdc++.h>
using namespace std;

const double ep = 1e-10, INF = 1e13;
const int K = 10;

struct pnt {
	double x, y;
	pnt(double x = 0, double y = 0) : x(x), y(y) {}
	double z;
    pnt operator + (const pnt &b) {return pnt(x + b.x, y + b.y);}
    pnt operator - (const pnt &b) {return pnt(x - b.x, y - b.y);}
    pnt operator * (const double &b) {return pnt(x * b, y * b);}
    pnt operator / (const double &b) {return pnt(x / b, y / b);}
    bool operator < (const pnt &b) const {return z > b.z;}
    double dist() {return x * x + y * y;}
    void input() {scanf("%lf %lf", &x, &y);}
}a[2][K*K*K+1], p[1020];

int n, e, xx, yy;

double calc_z(pnt q) {
	double g = INF, h = INF, now;
	for (int i = 1; i <= n; i ++) {
		now = (q - p[i]).dist();
		if (now < h) {
			h = now;
			if (h < g) swap(h, g);
		}
	}
	return h;
}


int main() {
	scanf("%d %d %d", &xx, &yy, &n);
	for (int i = 1; i <= n; i ++) p[i].input();
    int u = 1, v = 0;
    for (int i = 0; i < K; i ++) for (int j = 0; j < K; j ++) a[1][++e] = pnt((xx * (i + 0.5)) / K, (yy * (j + 0.5)) / K);
    double dx = xx * 0.5 / K, dy = yy * 0.5 / K, ans;
    int step = 10;
    while (step --) {
    	for (int i = 1; i <= e; i ++) a[u][i].z = calc_z(a[u][i]);
    	sort (a[u] + 1, a[u] + e + 1);
    	ans = a[u][1].z;
		dx = dx / K, dy = dy / K;
    	e = 0;
		for (int k = 1; k <= K; k ++) for (int i = 0; i < K; i ++) for (int j = 0; j < K; j ++) a[v][++e] = a[u][k] + pnt(dx * (2 * i - K + 1), dy * (2 * j - K + 1));
		swap(u, v);
    }
    printf("%.12lf\n", sqrt(ans));

	return 0;
}