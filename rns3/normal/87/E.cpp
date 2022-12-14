#include <bits/stdc++.h>
using namespace std;
#define M 400010
#define ep 1e-10
#define INF 2e9

typedef long long LL;

const int pi = acos(-1);

struct pnt {
	int x, y;
	pnt (int x = 0, int y = 0) : x(x), y(y) {}
	pnt operator +(pnt a) {return pnt(x + a.x, y + a.y);}
	pnt operator -(pnt a) {return pnt(x - a.x, y - a.y);}
	pnt operator /(int a) {return pnt(x / a, y / a);}
	pnt operator *(int a) {return pnt(x * a, y * a);}
	LL operator ^ (pnt a) {return 1LL * x * a.y - 1LL * y * a.x;}
	LL operator & (pnt a) {return 1LL * x * a.x + 1LL * y * a.y;}
	double dist() {return sqrt(1LL * x * x + 1LL * y * y);}
	void input() {scanf("%d %d", &x, &y);}
	void print() {printf("%d %d\n", x, y);}
} vec[M], p[M], tmp[M];

int n, un, dn, up[M], down[M];
int st, en;

void init() {
	int m = 0;
	tmp[m++] = p[0], tmp[m++] = p[1];
	for (int i = 2; i < n; i++) {
		if (!(p[i] - tmp[m - 2] ^ tmp[m - 1] - tmp[m - 2])) m--;
		tmp[m++] = p[i];
	}
	if (!(tmp[m-1] - tmp[0] ^ tmp[m-1] - tmp[m-2])) m--;
	n = m;
	for (int i = 0; i < n; i++) p[i] = tmp[i];
	int minx = INF, maxx = -INF;
	for (int i = 0; i < n; i++) {
		if (p[i].x < minx) minx = p[i].x, st = i;
		if (p[i].x > maxx) maxx = p[i].x, en = i;
		p[i+n] = p[i];
	}
	if (st < en) {
		for (int i = st; i <= en; i++) down[dn++] = p[i].x;
		for (int i = en; i <= st + n; i++) up[un++] = p[i].x;
	}
	else {
		for (int i = st; i <= en + n; i++) down[dn++] = p[i].x;
		for (int i = en; i <= st; i++) up[un++] = p[i].x;
	}
	reverse(up, up + un);
}

bool Up(pnt a, pnt b, pnt c) {
	if (a.x == b.x) return (c.y >= max(b.y, a.y));
	LL A = b.y - a.y, B = a.x - b.x;
	LL C = -A * a.x - B * a.y;
	LL v = A * c.x + B * c.y + C;
	if (B <= 0) return v <= 0;
	else return (v >= 0);
}

bool inside(pnt a, pnt b, pnt c) {
	return fabs((c - a).dist() + (c - b).dist() - (a - b).dist()) < ep;
}

bool check(int x, int y) {
	int i = lower_bound(down, down + dn, x) - down;
	if ((!i && x < down[i]) || i == dn) return 0;
	if (!i) i++;
	if (!inside(p[st+i], p[st+i-1], pnt(x, y))) {
		if (!Up(p[(st+i)], p[(st+i-1)], pnt(x, y))) return 0;
	}
	else return 1;

	i = lower_bound(up, up + un, x) - up;
	if ((!i && x < up[i]) || i == un) return 0;
	if (!i) i++;
	if (!inside(p[(st-i+1+n)], p[(st-i+n)], pnt(x, y))) {
		if (Up(p[(st-i+1+n)], p[(st-i+n)], pnt(x, y))) return 0;
	}
	return 1;
}

bool cmp(pnt a, pnt b) {
	double x = atan2(a.y, a.x), y = atan2(b.y, b.x);
	return x < y;
}

int main() {
	//freopen("E.in", "r", stdin);
	int sx = 0, sy = 0, T, x, y;
	for (int i = 0; i < 3; i++) {
		int minx = INF, miny = INF, m;
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			p[j].input();
			if (p[j].y < miny) miny = p[j].y, minx = p[j].x;
			else if (p[j].y == miny && minx > p[j].x) minx = p[j].x;
		}
		p[m] = p[0];
		for (int j = 0; j < m; j++) {
			vec[n++] = p[j+1] - p[j];
		}
		sx += minx, sy += miny;
	}
	sort(vec, vec + n, cmp);
	int id;
	for (int i = n - 1; i >= 0; i--) if (vec[i].y >= 0) id = i;
	p[0] = pnt(sx, sy);
	for (int i = 1; i <= n; i++) p[i] = p[i-1] + vec[(n+id+i-1)%n];
	init();
	for (scanf("%d", &T); T--; ) {
		scanf("%d %d", &x, &y); x *= 3, y *= 3;
		if (check(x, y)) puts("YES");
		else puts("NO");
	}
}