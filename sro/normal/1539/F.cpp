#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 1 << 18;

struct Node {
	int sm, pre, suf;
	Node operator + (const Node &b) const {
		return Node{sm + b.sm, min(pre, sm + b.pre), min(b.suf, suf + b.sm)};
	}
};

struct Segtree {
	Node dt[maxn << 1];
	void inline init() { memset(dt, 0, sizeof(dt)); }
	void inline add(int a, int x) {
		dt[a += maxn] = Node{x, min(0, x), min(0, x)};
		while (a >>= 1) dt[a] = dt[a << 1] + dt[a << 1 | 1];
	}
	Node inline sum(int l, int r) {
		Node resl({0, 0, 0}), resr({0, 0, 0});
		for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
			if (l & 1) resl = resl + dt[l++];
			if (r & 1) resr = dt[--r] + resr;
		}
		return resl + resr;
	}
} seg;

int n;
int a[200005];
vector<int> hv[200005];
int ans[200005];

int main() {
	scanf("%d", &n);
	cont(i, n) scanf("%d", a + i), hv[a[i]].pub(i);
	cont(i, n) seg.add(i, -1);
	cont(i, n) {
		parse(j, hv[i]) {
			int res = 1 - seg.sum(1, j - 1).suf - seg.sum(j + 1, n).pre;
			ans[j] = max(ans[j], res >> 1);
		}
		parse(j, hv[i]) seg.add(j, 1);
	}
	seg.init();
	cont(i, n) seg.add(i, -1);
	range(i, n, 1, -1) {
		parse(j, hv[i]) {
			int res = -seg.sum(1, j - 1).suf - seg.sum(j + 1, n).pre;
			ans[j] = max(ans[j], res >> 1);
		}
		parse(j, hv[i]) seg.add(j, 1);
	}
	cont(i, n) printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}