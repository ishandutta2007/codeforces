//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 3e5+5, K = N << 5;

int n, m, a[N], rt[N], tot;
struct Node {
	int s, lc, rc;
	Node() : s(0), lc(0), rc(0) {}
	~Node() {}
}t[K];
int insert(int u, int x, int l, int r) {
	int v = ++tot;
	t[v] = t[u];
	t[v].s = t[u].s + 1;
	if(l == r) return v;
	int mid = (l + r) >> 1;
	if(x <= mid) t[v].lc = insert(t[u].lc, x, l, mid);
	else t[v].rc = insert(t[u].rc, x, mid+1, r);
	return v;
}
int query(int u, int v, int x, int y, int l, int r) {
	if(l == r) return l;
	int mid = (l + r) >> 1, res = -1;
	if(y * (t[t[v].lc].s - t[t[u].lc].s) > x) res = query(t[u].lc, t[v].lc, x, y, l, mid);
	if(y * (t[t[v].rc].s - t[t[u].rc].s) > x && res < 0) res = query(t[u].rc, t[v].rc, x, y, mid+1, r);
	return res;
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) rt[i] = insert(rt[i-1], a[i], 1, n);
	while(m--) {
		int l, r, x, len;
		scanf("%d%d%d", &l, &r, &x);
		len = r - l + 1;
		printf("%d\n", query(rt[l-1], rt[r], len, x, 1, n));
	}
	return 0;
}