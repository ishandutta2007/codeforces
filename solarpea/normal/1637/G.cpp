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
int lg[65538], cnt[19];
vector<pii> res;
void work(int n, int coef) {
	if (!n) return;
	if (n == 1) return cnt[lg[coef]]++, void();
	int N = 1, cur = 0; while ((N << 1) <= n) N <<= 1, cur++;
	if (N == n) return cnt[lg[N * coef]]++, work(n - 1, coef), void();
	cnt[lg[N * coef]]++;
	for (int i = N + 1; i <= n; i++) {
		res.pb(mp(i * coef, (N - (i - N)) * coef));
		cnt[lg[N * 2 * coef]]++;
	}
	work(n - N, coef * 2); work(N - (n - N) - 1, coef);
}
int main() {
	for (int i = 1; i <= 16; i++) lg[1 << i] = i;
	int qu; scanf("%d", &qu);
	while (qu--) {
		int n; scanf("%d", &n); res.clear();
		if (n == 2) {puts("-1"); continue;}
		fill0(cnt); work(n, 1); int cnt0 = 0;
		int lg = 1;
		while ((1 << lg) < n) ++lg; --lg;
//		printf("! %d\n", res.size());
//		for (int j = 0; j <= lg + 1; j++) printf("%d ", cnt[j]); printf("\n");
		for (int j = 0; j <= lg - 1; j++) {
			while (cnt[j] >= 2) {
				cnt0++; cnt[j + 1]++; res.pb(mp(1 << j, 1 << j));
				cnt[j] -= 2;
			}
			if (cnt[j]) {
				res.pb(mp(1 << j, 1 << j + 1));
				res.pb(mp((1 << j), (1 << j + 1) + (1 << j)));
				cnt[j]--; cnt[j + 2]++;
			}
		}
		while (cnt[lg] >= 2) {
			res.pb(mp(1 << lg, 1 << lg));
			cnt[lg] -= 2; cnt0++; cnt[lg + 1]++;
		}
		if (cnt[lg]) {
			res.pb(mp(1 << lg, 0));
			res.pb(mp(1 << lg, 1 << lg));
			cnt[lg] = 0;
		}
		for (int i = 1; i <= cnt0; i++) res.pb(mp(1 << lg + 1, 0));
		printf("%d\n", res.size());
		for (pii p : res) printf("%d %d\n", p.fi, p.se);
	}
	return 0;
}