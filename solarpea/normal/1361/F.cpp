#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define fi first
#define se second
#define fill0(a) memset(a, 0, sizeof(a))
#define fill1(a) memset(a, -1, sizeof(a))
#define fillbig(a) memset(a, 63, sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
template <typename T1, typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1, typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio {
	#define FILE_SIZE 1 << 23
	char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
	inline char getc() {
		return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1: *p1++;
	}
	inline void putc(char x) {(*p3++ = x);}
	template <typename T> void read(T &x) {
		x = 0; char c = getc(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getc();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getc();
		if (neg) x = (~x) + 1;
	}
	template <typename T> void recursive_print(T x) {
		if (!x) return;
		recursive_print (x / 10);
		putc (x % 10 ^ 48);
	}
	template <typename T> void print(T x) {
		if (!x) putc('0');
		if (x < 0) putc('-'), x = -x;
		recursive_print(x);
	}
	template <typename T> void print(T x,char c) {print(x); putc(c);}
	void readstr(char *s) {
		char c = getc();
		while (c <= 32 || c >= 127) c = getc();
		while (c > 32 && c < 127) s[0] = c, s++, c = getc();
		(*s) = 0;
	}
	void printstr(string s) {
		for (int i = 0; i < s.size(); i++) putc(s[i]);
	}
	void printstr(char *s) {
		int len = strlen(s);
		for (int i = 0; i < len; i++) putc(s[i]);
	}
	void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
}
const int MAXN = 2e5;
const int LOG_N = 18;
const int MAXP = MAXN * 400;
int n, qu, p[MAXN + 5], w[MAXN + 5];
pii st[LOG_N + 2][MAXN + 5];
int query_st(int l, int r) {
	int k = 31 - __builtin_clz(r - l + 1);
	return min(st[k][l], st[k][r - (1 << k) + 1]).se;
}
int ch[MAXN * 2 + 5][2], ncnt, lf[MAXN + 5], fa[MAXN * 2 + 5], siz[MAXN * 2 + 5], R;
void build(int &k, int l, int r) {
	if (l > r) return; if (!k) k = ++ncnt; siz[k] = r - l + 1;
	if (l == r) return lf[l] = k, void();
	int pos = query_st(l, r - 1); build(ch[k][0], l, pos); build(ch[k][1], pos + 1, r);
	fa[ch[k][0]] = fa[ch[k][1]] = k;
}
ll tot = 0, iv[MAXN * 2 + 5];
namespace segtree {
	struct node {int ch[2], val;} s[MAXP + 5];
	int rt[MAXN * 2 + 5], ncnt;
	void insert(int &k, int l, int r, int p, int v) {
		if (!k) k = ++ncnt; s[k].val += v; if (l == r) return;
		int mid = l + r >> 1;
		if (p <= mid) insert(s[k].ch[0], l, mid, p, v);
		else insert(s[k].ch[1], mid + 1, r, p, v);
	}
	int query(int k, int l, int r, int ql, int qr) {
		if (!k || ql > qr) return 0;
		if (ql <= l && r <= qr) return s[k].val;
		int mid = l + r >> 1;
		if (qr <= mid) return query(s[k].ch[0], l, mid, ql, qr);
		else if (ql > mid) return query(s[k].ch[1], mid + 1, r, ql, qr);
		else return query(s[k].ch[0], l, mid, ql, mid) + query(s[k].ch[1], mid + 1, r, mid + 1, qr);
	}
}
using segtree :: rt;
using segtree :: insert;
using segtree :: query;
ll calc(int x) {return min(iv[x], 1ll * siz[ch[x][0]] * siz[ch[x][1]] - iv[x]);}
void ins(int pos, int v, int coef) {
	int pre = lf[pos]; insert(rt[pre], 1, n, v, coef);
	for (int i = fa[lf[pos]]; i; pre = i, i = fa[i]) {
		tot -= calc(i);
		if (ch[i][0] == pre) iv[i] += coef * query(rt[ch[i][1]], 1, n, 1, v - 1);
		else iv[i] += coef * query(rt[ch[i][0]], 1, n, v + 1, n);
		tot += calc(i); insert(rt[i], 1, n, v, coef);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i < n; i++) scanf("%d", &w[i]), st[0][i] = mp(w[i], i);
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j + (1 << i) - 1 < n; j++)
		st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
	build(R, 1, n);
//	for (int i = 1; i <= ncnt; i++) printf("%d: %d %d\n", i, ch[i][0], ch[i][1]);
//	for (int i = 1; i <= n; i++) printf("%d%c", lf[i], " \n"[i == n]);
	for (int i = 1; i <= n; i++) ins(i, p[i], 1);
//	for (int i = 1; i <= ncnt; i++) printf("%lld%c", iv[i], " \n"[i == ncnt]);
	scanf("%d", &qu); while (qu--) {
		int x, y; scanf("%d%d", &x, &y); ins(x, p[x], -1); ins(y, p[y], -1);
		swap(p[x], p[y]); ins(x, p[x], 1); ins(y, p[y], 1);
		printf("%lld\n", tot);
	}
	return 0;
}