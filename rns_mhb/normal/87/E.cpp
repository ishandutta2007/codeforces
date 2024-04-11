#include <cstdio>
#include <vector>
#include <algorithm>

#define N 150010

using namespace std;

typedef __int64 INT;

struct pnt {
	INT x, y;
	pnt (INT x = 0, INT y = 0): x(x), y(y) {}
	inline pnt operator - (const pnt &a) const { return pnt(x - a.x, y - a.y); }
	inline pnt operator + (const pnt &a) const { return pnt(x + a.x, y + a.y); }
	inline pnt operator * (const INT &a) const { return pnt(x * a, y * a); }
	inline INT operator & (const pnt &a) const { return x * a.x + y * a.y; }
	inline INT operator ^ (const pnt &a) const { return x * a.y - y * a.x; }
	inline void input() { x = y = 0, scanf("%I64d %I64d", &x, &y); }
	inline void print() { printf("%I64d %I64d\n", x, y); }
	bool operator < (const pnt &p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
};

typedef vector <pnt> poly;

inline int sgn(INT a) { return a > 0 ? 1 : a < 0 ? -1 : 0; }

bool InsideCP(pnt q, const poly &p) {
	int n = p.size();
	bool ccw = (p[1] - p[0] ^ p[2] - p[1]) > 0;
	int below = sgn(q - p[0] ^ p[n - 1] - p[0]);

	if (ccw && below < 0) return 0;
	if (!ccw && below > 0) return 0;

	int lo = 0, hi = n - 1;
	while (hi - lo > 1) {

		int mid = (hi + lo) >> 1;
		int s1 = sgn(p[mid] - p[lo] ^ q - p[lo]);
		int s2 = sgn(q - p[hi] ^ p[mid] - p[hi]);
		bool f1 = ccw ? (s1 >= 0) : (s1 <= 0);
		bool f2 = ccw ? (s2 >= 0) : (s2 <= 0);
		if (f1 && f2) return 1;
		if (!f1 && !f2) return 0;
		if (f1) lo = mid;
		else hi = mid;
	}
	return 0;
}

poly P;
pnt D[N], S;

inline int half(pnt a) { return a.x > 0 || (!a.x && a.y > 0); }

bool cmp(pnt a, pnt b) {
	int A = half(a), B = half(b);
	if (A != B) return A > B;
	return (a ^ b) > 0;
}

bool can(pnt a, pnt b) {
	return half(a) == half(b) && (a ^ b) == 0;
}

int main() {
	int n = 0, m, q;
//	freopen ("in.txt", "r", stdin);
	S = pnt(0, 0);
	for (int i = 0; i < 3; i ++) {
		scanf("%d", &m);
		P.clear(), P.resize(m);
		int Min = 0;
		for (int j = 0; j < m; j ++) {
			P[j].input();
			if (P[j] < P[Min]) Min = j;
		}
		S = S + P[Min];
		for (int j = 0; j < m; j ++) D[n ++] = P[(j + 1) % m] - P[j];
	}
	sort(D, D + n, cmp);
	int cnt = 0;
	for (int i = 0, j; i < n; i = j) {
		pnt R = pnt(0, 0);
		for (j = i; j < n && can(D[i], D[j]); j ++) R = R + D[j];
		D[cnt ++] = R;
	}
	n = cnt;
	P.clear(), P.resize(n);
	P[0] = S;
	for (int i = 1; i < n; i ++) P[i] = P[i - 1] + D[i - 1];
	for (scanf("%d", &q); q --; ) {
		pnt c;
		c.input(), c = c * 3;
		puts(InsideCP(c, P) ? "YES" : "NO");
	}
}