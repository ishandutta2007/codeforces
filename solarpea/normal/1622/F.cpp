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
mt19937 rng(20060729 ^ chrono :: steady_clock :: now().time_since_epoch().count());
template<typename T> T rand(T l, T r) {return uniform_int_distribution<T>(l, r)(rng);}
const int MAXN = 1e6;
int n, pr[MAXN / 2 + 5], prcnt = 0, vis[MAXN + 5], mnp[MAXN + 5];
int cnt[MAXN + 5], book[MAXN + 5];
u64 v[MAXN + 5], pre[MAXN + 5];
void sieve(int n) {
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) pr[++prcnt] = i, mnp[i] = i;
		for (int j = 1; j <= prcnt && pr[j] * i <= n; j++) {
			vis[pr[j] * i] = 1; mnp[pr[j] * i] = pr[j];
			if (i % pr[j] == 0) break;
		}
	}
}
int main() {
	scanf("%d", &n); sieve(MAXN);
	if (n == 1) return puts("1\n1"), 0;
	for (int i = 1; i <= n; i++) if ((n - i + 1) & 1) {
		int tmp = i;
		while (tmp ^ 1) {
			int p = mnp[tmp];
			while (tmp % p == 0) tmp /= p, cnt[p] ^= 1;
		}
	}
	bool flg = 1;
	for (int i = 1; i <= n; i++) flg &= (!cnt[i]);
	if (flg) {
		for (int i = 1; i <= n; i++) printf("%d%c", i, " \n"[i == n]);
		return 0;
	}
	for (int i = 1; i <= n; i++) v[i] = rand(1ull, ULLONG_MAX);
	u64 hs = 0;
	for (int i = 1; i <= n; i++) if (cnt[i]) hs ^= v[i];
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1]; int tmp = i;
		while (tmp ^ 1) {
			int p = mnp[tmp];
			while (tmp % p == 0) tmp /= p, pre[i] ^= v[p];
		}
	}
	for (int i = 1; i <= n; i++) if (pre[i] == hs) {
		printf("%d\n", n - 1);
		for (int j = 1; j <= n; j++) if (j != i) printf("%d ", j);
		return 0;
	}
	unordered_map<u64, int> pos;
	for (int i = 1; i <= n; i++) {
		if (pos[pre[i] ^ hs]) {
			int X = i, Y = pos[pre[i] ^ hs];
			printf("%d\n", n - 2);
			for (int i = 1; i <= n; i++) if (i != X && i != Y)
				printf("%d ", i);
			return 0;
		}
		pos[pre[i]] = i;
	}
	printf("%d\n", n - 3);
	for (int i = 1; i <= n; i++) if (i != 2 && i != (n >> 1) && i != n)
		printf("%d ", i);
	return 0;
}