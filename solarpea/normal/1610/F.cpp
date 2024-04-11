#include <bits/stdc++.h>
using namespace std;
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
		x = 0; char c = getchar(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getchar();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
		if (neg) x = (~x) + 1;
	}
	template <typename T> void recursive_print(T x) {
		if (!x) return;
		recursive_print (x / 10);
		putc (x % 10 ^ 48);
	}
	template <typename T> void print(T x) {
		if (!x) putc('0');
		if (x<0) putc('-'), x = -x;
		recursive_print(x);
	}
	template <typename T> void print(T x,char c) {print(x); putc(c);}
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXN = 3e5;
int n, m, d1[MAXN + 5], d2[MAXN + 5];
int hd[MAXN * 2 + 5], nxt[MAXN * 10 + 5], to[MAXN * 10 + 5], ec = 1;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int res[MAXN + 5], vis[MAXN * 10 + 5];
void dfs(int x) {
	for (int &e = hd[x]; e; e = nxt[e]) {
		int y = to[e];
		if (!vis[e >> 1]) {
			vis[e >> 1] = 1;
			if ((e >> 1) <= m) res[e >> 1] = (e & 1) + 1;
			dfs(y);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v, w; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		if (w == 1) {
			adde(u, v); adde(v, u);
			d1[u]++; d1[v]++;
		} else {
			adde(u + n, v + n); adde(v + n, u + n);
			d2[u]++; d2[v]++;
		}
	}
	int sum = 0, c = 0;
	for (int i = 1; i <= n; i++) {
		sum += (d1[i] & 1);
		if ((d1[i] & 1) && (d2[i] & 1)) adde(i, i + n), adde(i + n, i);
		else if ((d1[i] & 1)) adde(i, n * 2 + 1), adde(n * 2 + 1, i), c++;
		else if ((d2[i] & 1)) adde(i + n, n * 2 + 2), adde(n * 2 + 2, i + n);
	}
	if (c & 1) adde(n * 2 + 1, n * 2 + 2), adde(n * 2 + 2, n * 2 + 1);
	for (int i = 1; i <= n * 2 + 2; i++) dfs(i);
	printf("%d\n", sum);
	for (int i = 1; i <= m; i++) printf("%d", res[i]);
	return 0;
}