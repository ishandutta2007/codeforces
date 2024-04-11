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
const int MAXN = 1.5e5;
const int MAXP = MAXN << 5;
const int LOG_V = 30;
const int MOD = 998244353;
int n, X, pw2[MAXN + 5], rt, ch[MAXP + 5][2], ncnt, siz[MAXP + 5];
void insert(int &k, int v, int d) {
	if (!k) k = ++ncnt; siz[k]++; if (d == -1) return;
	insert(ch[k][v >> d & 1], v, d - 1);
}
int calc(int x, int y, int d) {
//	printf("%d %d %d\n", x, y, d);
	if (!x) return pw2[siz[y]];
	if (!y) return pw2[siz[x]];
	if (x == y) {
		if (!~d) return pw2[siz[x]];
		if (X >> d & 1) return calc(ch[x][0], ch[x][1], d - 1) % MOD;
		else return (0ll + calc(ch[x][0], ch[x][0], d - 1) + calc(ch[x][1], ch[x][1], d - 1) - 1 + MOD) % MOD;
	} else {
		if (!~d) return pw2[siz[x] + siz[y]];
		if (X >> d & 1) return 1ll * calc(ch[x][0], ch[y][1], d - 1) * calc(ch[x][1], ch[y][0], d - 1) % MOD;
		else {
			int res = (0ll + calc(ch[x][0], ch[y][0], d - 1) + calc(ch[x][1], ch[y][1], d - 1) - 1 + MOD) % MOD;
			res = (res + 1ll * (pw2[siz[ch[x][0]]] - 1) * (pw2[siz[ch[x][1]]] - 1)) % MOD;
			res = (res + 1ll * (pw2[siz[ch[y][0]]] - 1) * (pw2[siz[ch[y][1]]] - 1)) % MOD;
			return res;
		}
	}
}
int main() {
	scanf("%d%d", &n, &X);
	for (int i = 1, v; i <= n; i++) {scanf("%d", &v); insert(rt, v, LOG_V - 1);}
	for (int i = (pw2[0] = 1); i <= MAXN; i++) pw2[i] = (pw2[i - 1] << 1) % MOD;
	printf("%d\n", (calc(rt, rt, 29) - 1 + MOD) % MOD);
	return 0;
}