#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/hash_policy.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
using namespace std;
// using namespace __gnu_pbds;
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
#ifdef FASTIO
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
using namespace fastio;
#endif
const int MAXN = 5e4;
const int MAXM = 1e5;
const int MAXP = MAXM << 6;
const int INF = 0x3f3f3f3f;
int n, m, L[MAXM + 5], R[MAXM + 5];
struct node {int ch[2], mn;} s[MAXP + 5];
int rt[MAXN + 5], ncnt;
void insert_in(int &k, int l, int r, int p, int v) {
	if (!k) k = ++ncnt, s[k].mn = INF; chkmin(s[k].mn, v);
	if (l == r) return; int mid = l + r >> 1;
	(p <= mid) ? insert_in(s[k].ch[0], l, mid, p, v) : insert_in(s[k].ch[1], mid + 1, r, p, v);
}
int query_in(int k, int l, int r, int ql, int qr) {
	if (!k || ql > qr) return INF; if (ql <= l && r <= qr) return s[k].mn;
	int mid = l + r >> 1;
	if (qr <= mid) return query_in(s[k].ch[0], l, mid, ql, qr);
	else if (ql > mid) return query_in(s[k].ch[1], mid + 1, r, ql, qr);
	else return min(query_in(s[k].ch[0], l, mid, ql, mid), query_in(s[k].ch[1], mid + 1, r, mid + 1, qr));
}
void insert_out(int l, int r, int id) {for (int i = l; i; i &= (i - 1)) insert_in(rt[i], 1, n, r, id);}
int query_out(int l, int r) {int ret = INF; for (int i = l; i <= n; i += (i & (-i))) chkmin(ret, query_in(rt[i], 1, n, l, r)); return ret;}
vector<int> vec[MAXN + 5];
int res[MAXN + 5];
int calc(int l, int r) {
	if (l > r) return 0;
	int id = query_out(l, r);
	if (id == INF) return 0;
	else return R[id] - L[id] + 1 + calc(l, L[id] - 1) + calc(R[id] + 1, r);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &L[i], &R[i]);
		vec[R[i] - L[i] + 1].pb(i);
	}
	for (int i = n; i; i--) {
		for (int id : vec[i]) insert_out(L[id], R[id], id);
		res[i] = calc(1, n);
	}
	for (int i = 1; i <= n; i++) printf("%d\n", res[i]);
	return 0;
}