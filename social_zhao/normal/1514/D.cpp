#include<stdio.h>
#include<cmath>
#include<cstdlib>
#define isdigit(x) (x >= '0' && x <= '9')
#define mid ((l + r) >> 1)
using namespace std;
 
int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}
 
const int N = 3e5 + 5, M = N * 30;
int n, q, a[N];
int lc[M], rc[M], sum[M], T[N], tot;
 
int Rand() { return rand() * rand(); }
int Rand(int l, int r) { return l + Rand() % (r - l + 1); }
 
int build(int l, int r) {
	int rt = ++tot;
	if(l != r) lc[rt] = build(l, mid), rc[rt] = build(mid + 1, r);
	return rt;
}

int update(int pre, int l, int r, int x) {
	int rt = ++tot; lc[rt] = lc[pre], rc[rt] = rc[pre], sum[rt] = sum[pre] + 1;
	if(l == r) return rt;
	if(x <= mid) lc[rt] = update(lc[pre], l, mid, x);
	else rc[rt] = update(rc[pre], mid + 1, r, x);
	return rt;
}
 
int queryTim(int u, int v, int l, int r, int x) {
	if(l == r) return sum[v] - sum[u];
	if(x <= mid) return queryTim(lc[u], lc[v], l, mid, x);
	else return queryTim(rc[u], rc[v], mid + 1, r, x);
}

int queryKth(int u, int v, int l, int r, int x) {
	if(l == r) return l;
	int lsum = sum[lc[v]] - sum[lc[u]];
	if(lsum >= x) return queryKth(lc[u], lc[v], l, mid, x);
	else return queryKth(rc[u], rc[v], mid + 1, r, x - lsum);
}

int solve(int n, int m) { //  x  m - x <= ceil((n - x) / 2) 
	int l = 1, r = m, ans = -1;
	while(l <= r) {
		int x = mid;
		if(m - x <= (n - x + 1) / 2) ans = x, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}

int GetTim(int l, int r) {
	int len = r - l + 1;
	int md = queryKth(T[l - 1], T[r], 1, n, len / 2);
	int tim = queryTim(T[l - 1], T[r], 1, n, md);
	if(tim > (len + 1) / 2) return tim;
	else return -1;
}

int main() {
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	n = get(), q = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	T[0] = build(1, n);
	for(int i = 1; i <= n; i++) T[i] = update(T[i - 1], 1, n, a[i]);
	while(q--) {
		int l = get(), r = get(), ans = GetTim(l, r);
		if(ans == -1) printf("1\n");
		else printf("%d\n", solve(r - l + 1, ans) + 1);
	}
	return 0;
}