#include<bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (u << 1)
#define rc (u << 1 | 1)
using namespace std;

void Assert(int x) { if(!x) exit(0); }

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5, inf = 0x3f3f3f3f;
int n, k, d, a[N];
int lst[N];
map<int, int> pos;
set<int> ban;
int stx[N], tpx, stn[N], tpn;

int ans[N << 2], taga[N << 2];

void pushup(int u) { ans[u] = min(ans[lc], ans[rc]); }
void pusha(int u, int v) { taga[u] += v, ans[u] += v; }
void pushdown(int u) { if(taga[u]) pusha(lc, taga[u]), pusha(rc, taga[u]), taga[u] = 0; }

void updatea(int u, int l, int r, int a, int b, int v) {
	Assert(a <= b);
	if(a == l && r == b) return pusha(u, v);
	pushdown(u);
	if(b <= mid) updatea(lc, l, mid, a, b, v);
	else if(a > mid) updatea(rc, mid + 1, r, a, b, v);
	else updatea(lc, l, mid, a, mid, v), updatea(rc, mid + 1, r, mid + 1, b, v);
	pushup(u);
}

int query(int u, int l, int r, int a, int b, int v) {
	Assert(a <= b);
	if(l == r) { if(ans[u] <= v) return l; return inf; }
	pushdown(u);
	if(a == l && r == b) {
		if(ans[lc] <= v) return query(lc, l, mid, a, mid, v);
		else return query(rc, mid + 1, r, mid + 1, b, v);
	}
	if(b <= mid) return query(lc, l, mid, a, b, v);
	else if(a > mid) return query(rc, mid + 1, r, a, b, v);
	else return min(query(lc, l, mid, a, mid, v), query(rc, mid + 1, r, mid + 1, b, v));
}

void push(int i, int x) {
	int pre = i;
	while(tpx && a[stx[tpx]] <= x) 
		updatea(1, 1, n, stx[tpx - 1] + 1, pre - 1, x - a[stx[tpx]]), pre = stx[tpx - 1] + 1, --tpx; 
	stx[++tpx] = i;
	pre = i;
	while(tpn && a[stn[tpn]] >= x) 
		updatea(1, 1, n, stn[tpn - 1] + 1, pre - 1, a[stn[tpn]] - x), pre = stn[tpn - 1] + 1, --tpn;
	stn[++tpn] = i;
	if(i > 1) updatea(1, 1, n, 1, i - 1, -d);
	if(lst[i]) { if(lst[lst[i]]) ban.erase(lst[lst[i]]); ban.insert(lst[i]); }
}

int QueryLeft() { return (*ban.rbegin()) + 1; }

main() {
	n = get(), k = get(), d = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	if(d == 0) {
		int l = 1, r = 1, ansl = 1, ansr = 1;
		for(int i = 2; i <= n; i++) {
			if(a[i] == a[i - 1]) r = i;
			else l = r = i;
			if(r - l + 1 > ansr - ansl + 1) ansl = l, ansr = r;
		}
		printf("%lld %lld\n", ansl, ansr);
		return 0;
	}
	ban.insert(0);
	for(int i = 1; i <= n; i++) lst[i] = pos[a[i]], pos[a[i]] = i;
	int ansl = 1, ansr = 1;
	for(int i = 1, l = 1; i <= n; i++) {
		push(i, a[i]);
		while((a[l] % d + d) % d != (a[i] % d + d) % d) ++l;
		int lb = max(l, QueryLeft());
		int lmn = query(1, 1, n, lb, i, k * d);
		if(lmn != inf && i - lmn + 1 > ansr - ansl + 1) ansl = lmn, ansr = i;
	}
	printf("%lld %lld\n", ansl, ansr);
	return 0;
}