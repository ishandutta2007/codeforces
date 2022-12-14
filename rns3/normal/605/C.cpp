#include <cstdio>
#include <algorithm>

using namespace std;

#define N 100100

struct pnt {
	int x, y;
	pnt(int x = 0, int y = 0) : x(x), y(y) {}
	pnt operator -(pnt a) { return pnt(x - a.x, y - a.y); }
	long long operator ^(pnt a) { return 1LL * x * a.y - 1LL * y * a.x; }
}p[N], q[N];

bool cmp(pnt a, pnt b) {
	if(a.y != b.y) return a.y > b.y;
	return a.x > b.x;
}

int n, P, Q, m;

double run() {
	if(1LL * P * q[0].y <= 1LL * Q * q[0].x) return 1. * Q / q[0].y;
	if(1LL * P * q[m-1].y >= 1LL * Q * q[m-1].x) return 1. * P / q[m-1].x;
	n = 1; p[0] = q[0];
	for(int i = 1; i < m; i ++) {
		while(n > 1) {
			if(((p[n-1] - p[n-2]) ^ (q[i] - p[n-1]))>=0) n --; else break;
		}
		p[n ++] = q[i];
	}
	for(int i = 0; i < n; i ++) {
		if(1LL * P * p[i].y <= 1LL * Q * p[i].x) {
			long long X = 1LL * (p[i].x - p[i-1].x) * Q + 1LL * (p[i-1].y - p[i].y) * P;
			long long Y = 1LL * p[i].x * p[i-1].y - 1LL * p[i].y * p[i-1].x;
			return 1. * X / Y;
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &P, &Q);
	for(int i = 0; i < n; i ++) scanf("%d%d", &p[i].x, &p[i].y);
	sort(p, p + n, cmp);
	for(int i = 0; i < n; i ++) {
		if(i && p[i].y == p[i-1].y) continue;
		if(!m || p[i].x > q[m-1].x) q[m ++] = p[i];
	}
	printf("%.16lf\n", run());
	return 0;
}