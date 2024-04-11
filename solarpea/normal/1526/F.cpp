//#define INTERACTOR_MODE
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
const int MAXN = 1e5;
int n; pii p[MAXN + 5];
int val[MAXN + 5], pos[MAXN + 5], seq[MAXN + 5];
#ifdef INTERACTOR_MODE
namespace myratingis1064 {
	int cnt, perm[MAXN + 5];
	void gen(int n) {
		for (int i = 1; i <= n; i++) perm[i] = i;
		random_shuffle(perm + 1, perm + n + 1);
		if (perm[1] > perm[2]) {
			for (int i = 1; i <= n; i++) perm[i] = n + 1 - perm[i];
		}
		for (int i = 1; i <= n; i++) printf("%d%c", perm[i], " \n"[i == n]);
		cnt = 0;
	}
	int query(int x, int y, int z) {
		cnt++;
		if (cnt > 2 * n + 420) assert(0);
		int A = abs(perm[x] - perm[y]);
		int B = abs(perm[x] - perm[z]);
		int C = abs(perm[y] - perm[z]);
		return A + B + C - min(min(A, B), C) - max(max(A, B), C);
	}
}
#endif
int query(int x, int y, int z) {
#ifdef INTERACTOR_MODE
	return myratingis1064 :: query(x, y, z);
#else
	printf("? %d %d %d\n", x, y, z); fflush(stdout);
	int val; scanf("%d", &val); assert(val != -1);
	return val;
#endif
}
void solve() {
	scanf("%d", &n);
#ifdef INTERACTOR_MODE
	myratingis1064 :: gen(n);
#endif
	for (int i = 1; i <= n; i++) seq[i] = i; random_shuffle(seq + 1, seq + n + 1);
	int A = 0, B = 0, flg = 0;
	for (int i = 1; i <= 14; i++) {
		for (int j = i + 1; j <= 14; j++) {
			for (int k = j + 1; k <= 14; k++) {
				if (query(seq[i], seq[j], seq[k]) * 6 <= n - 4) {
					A = seq[i]; B = seq[j]; flg = 1; break;
				}
			}
			if (flg) break;
		}
		if (flg) break;
	}
	for (int i = 1; i <= n; i++) p[i] = mp(0, 0);
	for (int i = 1; i <= n; i++) if (i != A && i != B) p[i] = mp(query(i, A, B), i);
	sort(p + 1, p + n + 1, greater<pii>());
	int P1 = p[1].se, P2 = 0;
	for (int i = 2; i <= 4; i++) if (p[i].fi == p[1].fi - 1) {
		if (query(A, P1, p[i].se) == query(P1, A, B) - 1 ||
		    query(B, P1, p[i].se) == query(P1, A, B) - 1) {
			assert(!P2), P2 = p[i].se;
		}
	}
//	printf("%d %d\n", P1, P2);
	for (int i = 1; i <= n; i++) if (i != P1 && i != P2)
		val[i] = query(i, P1, P2) + 2, pos[val[i]] = i;
//	printf("%d %d\n", P1, P2);
	if (query(P1, pos[n - 1], pos[n]) == n - 2) val[P1] = 1, val[P2] = 2;
	else val[P1] = 2, val[P2] = 1;
	if (val[1] > val[2]) {
		for (int i = 1; i <= n; i++) val[i] = n - val[i] + 1;
	}
	printf("!"); for (int i = 1; i <= n; i++) printf(" %d", val[i]);
	printf("\n"); fflush(stdout);
#ifndef INTERACTOR_MODE
	int orz; scanf("%d", &orz); assert(orz == 1);
#else
	int orz = 1;
	for (int i = 1; i <= n; i++) if (val[i] != myratingis1064 :: perm[i]) orz = -1;
	assert(orz == 1);
#endif
}
int main() {
	srand(time(0));
	int qu; scanf("%d", &qu);
	while (qu--) solve(); 
	return 0;
}