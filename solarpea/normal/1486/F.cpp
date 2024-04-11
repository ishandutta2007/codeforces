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
const int MAXN = 3e5;
const int LOG_N = 18;
int n, m, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int fa[MAXN + 5][LOG_N + 2], dep[MAXN + 5], dfn[MAXN + 5], edt[MAXN + 5], tim = 0;
void dfs(int x, int f) {
	fa[x][0] = f; dfn[x] = ++tim;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dep[y] = dep[x] + 1; dfs(y, x);
	}
	edt[x] = tim;
}
int getlca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = LOG_N; ~i; i--) if (dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	for (int i = LOG_N; ~i; i--) if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
int get_kanc(int x, int k) {
	for (int i = LOG_N; ~i; i--) if (k >> i & 1) x = fa[x][i];
	return x;
}
struct path {
	int u, v, lc, _u, _v;
	bool operator < (const path &rhs) {
		return dep[lc] < dep[rhs.lc];
	}
} a[MAXN + 5];
vector<int> pth[MAXN + 5];
int buc[MAXN + 5];
map<pii, int> buc_pii;
int t[MAXN + 5];
void add(int x, int v) {for (int i = x; i <= n; i += (i & (-i))) t[i] += v;}
int query(int x) {int ret = 0; for (int i = x; i; i &= (i - 1)) ret += t[i]; return ret;}
int clc_cov(int x) {return query(edt[x]) - query(dfn[x] - 1);}
int calc(int id) {
	int ret = clc_cov(a[id].lc);
	if (a[id]._u) ret -= clc_cov(a[id]._u);
	if (a[id]._v) ret -= clc_cov(a[id]._v);
	return ret;
}
void ins(int id) {
	add(dfn[a[id].u], 1); add(dfn[a[id].v], 1); add(dfn[a[id].lc], -1);
	if (fa[a[id].lc][0]) add(dfn[fa[a[id].lc][0]], -1);
}
int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
	scanf("%d", &m); dfs(1, 0);
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j <= n; j++)
		fa[j][i] = fa[fa[j][i - 1]][i - 1];
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a[i].u, &a[i].v), a[i].lc = getlca(a[i].u, a[i].v);
		if (a[i].u != a[i].lc) a[i]._u = get_kanc(a[i].u, dep[a[i].u] - dep[a[i].lc] - 1);
		if (a[i].v != a[i].lc) a[i]._v = get_kanc(a[i].v, dep[a[i].v] - dep[a[i].lc] - 1);
	}
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= m; i++) pth[a[i].lc].pb(i);
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < pth[i].size(); j++) {
			int id = pth[i][j]; res += j;
			if (a[id]._u) res -= buc[a[id]._u];
			if (a[id]._v) res -= buc[a[id]._v];
			if (a[id]._u && a[id]._v) res += buc_pii[mp(a[id]._u, a[id]._v)];
			if (a[id]._u) buc[a[id]._u]++;
			if (a[id]._v) buc[a[id]._v]++;
			if (a[id]._u && a[id]._v) {
				buc_pii[mp(a[id]._u, a[id]._v)]++;
				buc_pii[mp(a[id]._v, a[id]._u)]++;
			}
		}
	}
	for (int l = 1, r; l <= m; l = r) {
		r = l; while (r <= m && dep[a[r].lc] == dep[a[l].lc]) ++r;
		for (int i = l; i < r; i++) res += calc(i);
		for (int i = l; i < r; i++) ins(i);
	}
	printf("%lld\n", res);
	return 0;
}