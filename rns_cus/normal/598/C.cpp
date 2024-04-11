#include <bits/stdc++.h>
using namespace std;
#define N 100100

const long double pie = acos(-1);

struct pnt {
	double x, y;
	pnt (double x = 0, double y = 0): x(x), y(y) {}
	inline pnt operator - (const pnt &a) const { return pnt(x - a.x, y - a.y); }
	inline pnt operator + (const pnt &a) const { return pnt(x + a.x, y + a.y); }
	inline pnt operator * (const double &a) const { return pnt(x * a, y * a); }
	inline pnt operator / (const double &a) const { return pnt(x / a, y / a); }
	inline double operator & (const pnt &a) const { return x * a.x + y * a.y; }
	inline double operator ^ (const pnt &a) const { return x * a.y - y * a.x; }
	inline void input() { x = y = 0, scanf("%lf %lf", &x, &y); }
	inline void print() { printf("%lf %lf\n", x, y); }
} p[N];

long double deg[N];
int n, id[N];

bool cmp(int i, int j) {return deg[i] < deg[j];}

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) p[i].input();
	for (int i = 0; i < n; i ++) id[i] = i;
	for (int i = 0; i < n; i ++) deg[i] = atan2(p[i].y, p[i].x);
	sort(id, id + n, cmp);
	long double mn = pie * 2;
	int x = 1;
	for (int i = 1; i < n; i ++) {
		if (mn > deg[id[i]] - deg[id[i-1]]) x = i, mn = deg[id[i]] - deg[id[i-1]];
	}
	if (2.0 * pie - (deg[id[n-1]] - deg[id[0]]) < mn) {
		printf("%d %d\n", id[0] + 1, id[n-1] + 1); return 0;
	}
	printf("%d %d\n", id[x-1] + 1, id[x] + 1);
	return 0;
}