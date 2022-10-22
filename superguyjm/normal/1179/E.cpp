#include <bits/stdc++.h>

#define LL long long
#define pll pair<LL,LL>
using namespace std;
const int inf = 2147483647;
const int N = 1001;

int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
inline LL read() {
    LL x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
void put(LL x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

LL v, L; int n, id[N], c[N], b[N];
pll ans[N];

LL query(int x, LL y) {
	putchar('?'), putchar(' ');
	put(x), putchar(' '), put(y), puts("");
	fflush(stdout);
	LL hh = read();
	return hh;
}

LL findpos(int x, LL k, LL ql, LL qr) {
	LL mid = (ql + qr) / 2;
	while(1) {
		LL hh = query(x, mid);
		if(hh == k) return mid;
		if(hh < k) ql = mid + 1;
		else qr = mid - 1;
		mid = (ql + qr) / 2;
	}
}

void qst(int l, int r, int mid, LL ql, LL qr) {
	int x = rand() % (r - l + 1) + l;
	LL uu = (L / n) * mid, pos = findpos(id[x], uu, ql, qr);
	int tp = 0, l1 = l - 1, l2 = r + 1; c[++tp] = id[x];
	for(int i = l; i <= r; i++) if(x != i){
		LL hh = query(id[i], pos);
		if(hh > uu) b[++l1] = id[i];
		else if(hh < uu) b[--l2] = id[i];
		else c[++tp] = id[i];
	} while(tp && l1 < mid) b[++l1] = c[tp--];
	if(l1 == mid) {
		v = pos;
		while(tp) b[--l2] = c[tp--];
		for(int i = l; i <= r; i++) id[i] = b[i];
		return ;
	} if(l1 < mid) {
		for(int i = l; i <= r; i++) id[i] = b[i];
		qst(l2, r, mid, ql, qr);
		return ;
	} while(tp) b[--l2] = c[tp--];
	for(int i = l; i <= r; i++) id[i] = b[i];
	qst(l, l1, mid, ql, qr);
}

void solve(int l, int r, LL ql, LL qr) {
	if(l == r) {ans[id[l]] = pll(ql, qr); return ;}
	int mid = (l + r) / 2;
	qst(l, r, mid, ql, qr);
	LL zz = v;
	solve(l, mid, ql, zz);
	solve(mid + 1, r, zz, qr);
}

int main() {
	n = read(), L = read();
	for(int i = 1; i <= n; i++) id[i] = i;
	solve(1, n, 0, 1e18);
	puts("!");
	for(int i = 1; i <= n; i++) put(ans[i].first), putchar(' '), put(ans[i].second), puts("");
	fflush(stdout);
	return 0;
}