///	Choe Kwang D

#include <bits/stdc++.h>
using namespace std;

#define N 505
typedef long long LL;

struct pnt {
	LL x, y;
	pnt (LL x = 0, LL y = 0): x(x), y(y) {}
	inline LL operator ^ (const pnt &a) const { return x * a.y - y * a.x; }
	inline void input() { x = y = 0, scanf("%I64d %I64d", &x, &y); }
} p[N], q[N];

LL wide(pnt A, pnt B, pnt C) {
	return (A ^ B) + (B ^ C) + (C ^ A);
}

int n, m, f[N][N], g[N], sign[N][N];
int sum, mn, mx, xx;

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++) p[i].input();
	for (int j = 0; j < m; j ++) q[j].input();
	for (int i = 0; i < n; i ++) {
		for (int j = i + 1; j < n; j ++) {
			LL x1 = p[i].x, x2 = p[j].x;
			sign[i][j] = 1;
			if (x1 > x2) swap(x1, x2), sign[i][j] = -1;
			for (int k = 0; k < m; k ++) {
				if (q[k].x > x1 && q[k].x < x2 && wide(p[i], p[j], q[k]) * sign[i][j] < 0) f[i][j] ++;
			}
			if (sign[i][j] < 0) f[i][j] = -f[i][j];
			f[j][i] = -f[i][j];
			sign[j][i] = -sign[i][j];
		}
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) if (p[i].x == q[j].x && p[i].y > q[j].y) g[i] ++;
	}
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = i + 1; j < n; j ++) {
			for (int k = j + 1; k < n; k ++) {
				sum = f[i][j] + f[j][k] + f[k][i];
				mn = min(p[i].x, p[j].x), mx = p[i].x + p[j].x - mn, xx;
				if (p[k].x < mn) xx = mn;
				else if (p[k].x > mx) xx = mx;
				else xx = p[k].x;
				if (p[i].x == xx) sum += sign[i][j] * g[i];
				else if (p[j].x == xx) sum += sign[j][k] * g[j];
				else sum += sign[k][i] * g[k];
				if (sum == 0) ans ++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}