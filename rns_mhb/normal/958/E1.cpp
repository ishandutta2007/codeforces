#include <bits/stdc++.h>
using namespace std;

const double ep = 1e-5;

int tmpx, tmpy;
struct pnt {
	double x, y;
	pnt(double x = 0, double y = 0) : x(x), y(y) {}
	pnt operator + (const pnt &b) {return pnt(x + b.x, y + b.y);}
	pnt operator - (const pnt &b) {return pnt(x - b.x, y - b.y);}
	pnt operator * (const double &b) {return pnt(x * b, y * b);}
	pnt operator / (const double &b) {return pnt(x / b, y / b);}
	double operator & (const pnt &b) {return x * b.x + y * b.y;}
	double operator ^ (const pnt &b) {return x * b.y - b.x * y;}
	void input() {scanf("%d %d", &tmpx, &tmpy), x = tmpx, y = tmpy;}
} tmp;

bool inside(pnt a, pnt b, pnt c) {
	return abs(a - b ^ a - c) < ep && (a - b & a - c) <= 0;
}

int inter_seg(pnt a, pnt b, pnt c, pnt d, pnt &rlt) {
	double s = a - b ^ c - d;
	if (abs(s) < ep) return 0;
	double x = (a - d ^ c - d) / s;
	rlt = a * (1 - x) + b * x;
	return inside(rlt, a, b) && inside(rlt, c, d);
}

#define N 11

int id[N];

pnt a[N], b[N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) a[i].input();
	for (int i = 1; i <= m; i ++) b[i].input();
	if (n != m) {
		puts("No");
		return 0;
	}
	random_shuffle(b + 1, b + n + 1);
	for (int i = 1; i <= n; i ++) id[i] = i;
	do {
		bool ok = 1;
		for (int i = 1; i < n && ok; i ++) for (int j = i + 1; j <= n; j ++) {
			if (inter_seg(a[i], b[id[i]], a[j], b[id[j]], tmp)) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			puts("Yes");
			return 0;
		}
	} while (next_permutation(id + 1, id + n + 1));

	puts("No");

	return 0;
}