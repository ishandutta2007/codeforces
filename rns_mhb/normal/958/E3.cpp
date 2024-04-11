#include <bits/stdc++.h>
using namespace std;

struct pnt {
	int x, y;
	pnt(int x = 0, int y = 0) : x(x), y(y) {}
	pnt operator + (const pnt &b) const {return pnt(x + b.x, y + b.y);}
	pnt operator - (const pnt &b) const {return pnt(x - b.x, y - b.y);}
	int operator & (const pnt &b) const {return x * b.x + y * b.y;}
	int operator ^ (const pnt &b) const {return x * b.y - y * b.x;}
	bool operator < (const pnt &b) const {return 917 * x + 1997 * y < 917 * b.x + 1997 * b.y;}
	int dist() {return x * x + y * y;}
	void input() {scanf("%d %d", &x, &y);}
};

#define N 10101

const int INF = 1e9;

pnt A[N], B[N];

int n, id[N], ans[N], jd[N];

bool cross(pnt a, pnt b, pnt c, pnt d) {
	int x, y;
	x = (a - b) ^ (a - c);
	y = (a - b) ^ (a - d);
	if (x <= 0 && y <= 0) return 0;
	if (x >= 0 && y >= 0) return 0;
	x = (c - d) ^ (c - a);
	y = (c - d) ^ (c - b);
	if (x <= 0 && y <= 0) return 0;
	if (x >= 0 && y >= 0) return 0;
	return 1;
}

bool good(pnt a, pnt b, pnt c, pnt d) {
	return (a - b).dist() + (c - d).dist() > (a - d).dist() + (c - b).dist();
}

bool to[N], too[N];

void solve_1() {
	for (int i = 1; i <= n; i ++) to[i] = 1;
	while (1) {
		bool flag = 0;
		for (int i = 1; i <= n; i ++) if (to[i]) {
			for (int j = 1; j <= n; j ++) if (i != j) {
				if (cross(A[i], B[id[i]], A[j], B[id[j]])) swap(id[i], id[j]), flag = 1, too[i] = 1, too[j] = 1;
			}
		}
		if (!flag) break;
		for (int i = 1; i <= n; i ++) to[i] = too[i];
		memset(too, 0, sizeof too);
	}
}

int rk[N], rkk[N];

bool cmp_1(int i, int j) {
	return A[i] < A[j];
}

bool cmp_2(int i, int j) {
	return B[i] < B[j];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) A[i].input();
	for (int i = 1; i <= n; i ++) B[i].input();
	for (int i = 1; i <= n; i ++) rk[i] = i, rkk[i] = i;
	sort(rk + 1, rk + n + 1, cmp_1);
	sort(rkk + 1, rkk + n + 1, cmp_2);
	for (int i = 1; i <= n; i ++) id[rk[i]] = rkk[i];

	solve_1();

	for (int i = 1; i <= n; i ++) printf("%d\n", id[i]);

	return 0;
}