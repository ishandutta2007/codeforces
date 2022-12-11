#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;

int a[200010];
vector <pii> ord;

struct Segment_tree {
#define MAXTYPE 0
#define MINTYPE 1
	int TYPE;
	int T[800010][2], tag[800010];
	int fun(int x, int y) {return TYPE == MAXTYPE ? max(x, y) : min(x, y);}
	void pushup(int now) {
		T[now][0] = fun(T[now << 1][0], T[now << 1 | 1][0]);
		T[now][1] = fun(T[now << 1][1], T[now << 1 | 1][1]);
	}
	void addtag(int now, int x) {T[now][0] += x, T[now][1] += x, tag[now] += x;}
	void pushdown(int now) {
		if (tag[now]) addtag(now << 1, tag[now]), addtag(now << 1 | 1, tag[now]), tag[now] = 0;
	}
	void Build(int now, int l, int r, int val) {
		tag[now] = 0;
		if (l == r) {T[now][l & 1] = l * val, T[now][(l & 1) ^ 1] = TYPE == MAXTYPE ? -INF : INF; return ;}
		int mid = l + r >> 1;
		Build(now << 1, l, mid, val), Build(now << 1 | 1, mid + 1, r, val);
		pushup(now);
	}
	void Update(int now, int l, int r, int L, int R, int x) {
		if (l == L && r == R) {addtag(now, x); return ;}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, x);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, x);
		else Update(now << 1, l, mid, L, mid, x), Update(now << 1 | 1, mid + 1, r, mid + 1, R, x);
		pushup(now);
	}
	int Query(int now, int l, int r, int L, int R, int d) {
		if (l == L && r == R) return T[now][d];
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R, d);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R, d);
		return fun(Query(now << 1, l, mid, L, mid, d), Query(now << 1 | 1, mid + 1, r, mid + 1, R, d));
	}
}seg[2][2];

int ans[200010];

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), ord.push_back(mp(a[i], i));
	for (int p = 0; p < 2; p++) for (int q = 0; q < 2; q++) seg[p][q].TYPE = q ? MAXTYPE : MINTYPE;
	for (int p = 0; p < 2; p++) for (int q = 0; q < 2; q++) seg[p][q].Build(1, 0, n, p ? -1 : 1);
	sort(ord.begin(), ord.end());
	for (int i = 0; i < ord.size(); i++) {
		int j = i; while (j < ord.size() && ord[j].fi == ord[i].fi) j++;
		for (int k = i; k < j; k++) {
			int x = ord[k].se;
			for (int q = 0; q < 2; q++) seg[1][q].Update(1, 0, n, x, n, 2);
		}
		for (int k = i; k < j; k++) {
			int x = ord[k].se;
			for (int p = 0; p < 2; p++) {
				for (int d1 = 0; d1 < 2; d1++) {
					for (int d2 = 0; d2 < 2; d2++) {
						int d = d1 ^ d2, base = d & 1 ? 0 : p ? -1 : 1;
						int R = seg[p][1].Query(1, 0, n, x, n, d2);
						int L = seg[p][0].Query(1, 0, n, 0, x - 1, d1) + 1;
						ans[x] = max(ans[x], R - L + base);
					}
				}
			}
		}
		for (int k = i; k < j; k++) {
			int x = ord[k].se;
			for (int q = 0; q < 2; q++) seg[0][q].Update(1, 0, n, x, n, -2);
		}
		i = j - 1;
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i] / 2); printf("\n");
	return 0;
}