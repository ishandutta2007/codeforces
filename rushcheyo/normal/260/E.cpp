#include <bits/stdc++.h>
using namespace std;

const int N = 100005, inf = 1000000000;
int n, a[10];
struct point { int x, y; };
bool cmpx(const point &a, const point &b) { return a.x < b.x; }
bool cmpy(const point &a, const point &b) { return a.y < b.y; }
point p[N], px[N], py[N];

int round(int x) { return x >= 0 ? x : x + 1; }

struct node { int size; node *l, *r; } null[1], *root[N];
node *newnode() {
	const int L = 100000;
	static node *S, *T;
	if (S == T) T = (S = new node[L]) + L;
	*S = *null;
	return S++;
}

int query(node *u, int l, int r, int qr) {
	if (r <= qr) return u->size;
	int mid = l + r >> 1;
	if (qr <= mid) return query(u->l, l, mid, qr);
	else return u->l->size + query(u->r, mid + 1, r, qr);
}

node *insert(node *pre, int l, int r, int p) {
	node *u = newnode();
	u->l = pre->l, u->r = pre->r, u->size = pre->size + 1;
	if (l < r) {
		int mid = l + r >> 1;
		if (p <= mid) u->l = insert(pre->l, l, mid, p);
		else u->r = insert(pre->r, mid + 1, r, p);
	}
	return u;
}

int prefix(int x, int y) {
	int pos = upper_bound(px + 1, px + 1 + n, (point){x, inf}, cmpx) - px - 1;
	return query(root[pos], -inf, inf, y);
}

bool judge(int x1, int x2, int y1, int y2) {
	int s1 = prefix(x1, y1);
	if (s1 != a[1]) return false;
	int s14 = prefix(x1, y2);
	int s4 = s14 - s1;
	if (s4 != a[4]) return false;
	int s147 = prefix(x1, inf);
	int s7 = s147 - s1 - s4;
	if (s7 != a[7]) return false;
	int s12 = prefix(x2, y1);
	int s2 = s12 - s1;
	if (s2 != a[2]) return false;
	int s123 = prefix(inf, y1);
	int s3 = s123 - s1 - s2;
	if (s3 != a[3]) return false;
	int s1245 = prefix(x2, y2);
	int s5 = s1245 - s1 - s2 - s4;
	if (s5 != a[5]) return false;
	int s124578 = prefix(x2, inf);
	int s8 = s124578 - s1 - s2 - s4 - s5 - s7;
	if (s8 != a[8]) return false;
	int s123456 = prefix(inf, y2);
	int s6 = s123456 - s1 - s2 - s3 - s4 - s5;
	if (s6 != a[6]) return false;
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &p[i].x, &p[i].y), px[i] = py[i] = p[i];
	sort(px + 1, px + 1 + n, cmpx);
	root[0] = null->l = null->r = null;
	for (int i = 1; i <= n; i++)
		root[i] = insert(root[i - 1], -inf, inf, px[i].y);
	sort(py + 1, py + 1 + n, cmpy);
	for (int i = 1; i <= 9; i++)
		scanf("%d", a + i);
	sort(a + 1, a + 10);
	do {
		int x1 = a[1] + a[4] + a[7];
		if (px[x1].x == px[x1 + 1].x) continue;
		x1 = px[x1].x;
		int x2 = a[1] + a[2] + a[4] + a[5] + a[7] + a[8];
		if (px[x2].x == px[x2 + 1].x) continue;
		x2 = px[x2].x;
		int y1 = a[1] + a[2] + a[3];
		if (py[y1].y == py[y1 + 1].y) continue;
		y1 = py[y1].y;
		int y2 = a[1] + a[2] + a[3] + a[4] + a[5] + a[6];
		if (py[y2].y == py[y2 + 1].y) continue;
		y2 = py[y2].y;
		if (judge(x1, x2, y1, y2)) {
			printf("%d.5 %d.5\n%d.5 %d.5\n", round(x1), round(x2), round(y1), round(y2));
			return 0;
		}
	} while (next_permutation(a + 1, a + 10));
	puts("-1");
}

/*
1 2 3
4 5 6
7 8 9
*/