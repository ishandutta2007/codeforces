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
const int MAXN = 2e5;
const int LOG_N = 18;
int n, qu, tim[MAXN + 5], sta[MAXN + 5], sum[MAXN + 5];
struct qry {int opt, l, r, x;} q[MAXN + 5];
int st1[LOG_N + 2][MAXN + 5]; pii st2[LOG_N + 2][MAXN + 5];
int hib[MAXN + 5];
int query_st1(int l, int r) {
	int k = hib[r - l + 1];
	return max(st1[k][l], st1[k][r - (1 << k) + 1]);
}
pii query_st2(int l, int r) {
	int k = hib[r - l + 1];
	return max(st2[k][l], st2[k][r - (1 << k) + 1]);
}
int main() {
	scanf("%d%d", &n, &qu);
	for (int i = 2; i <= MAXN; i++) hib[i] = hib[i >> 1] + 1;
	memset(tim, 63, sizeof(tim)); memset(sta, -1, sizeof(sta));
	set<int> st; for (int i = 1; i <= n; i++) st.insert(i);
	for (int i = 1; i <= qu; i++) {
		scanf("%d", &q[i].opt);
		if (q[i].opt == 0) scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].x);
		else scanf("%d", &q[i].x);
	}
	for (int i = 1; i <= qu; i++) {
		if (q[i].opt == 0 && q[i].x == 0) {
			while (1) {
				set<int> :: iterator it = st.lower_bound(q[i].l);
				if (it == st.end() || (*it) > q[i].r) break;
				tim[*it] = i; sta[*it] = 0;
				st.erase(st.find(*it));
			}
		}
	}
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (sta[i] == 0);
	for (int i = 1; i <= n; i++) {
		st1[0][i] = (sta[i] == 0) ? tim[i] : 0;
		st2[0][i] = mp(tim[i], i);
	}
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j + (1 << i) - 1 <= n; j++) {
		st1[i][j] = max(st1[i - 1][j], st1[i - 1][j + (1 << i - 1)]);
		st2[i][j] = max(st2[i - 1][j], st2[i - 1][j + (1 << i - 1)]);
	}
	for (int i = 1; i <= qu; i++) {
		if (q[i].opt == 0 && q[i].x == 1 && sum[q[i].r] - sum[q[i].l - 1] == q[i].r - q[i].l) {
			int pos = query_st2(q[i].l, q[i].r).se;
			sta[pos] = 1; chkmin(tim[pos], max(i, query_st1(q[i].l, q[i].r)));
		}
	}
	for (int i = 1; i <= qu; i++) if (q[i].opt == 1) {
		if (!~sta[q[i].x] || tim[q[i].x] > i) printf("N/A\n");
		else printf("%s\n", (sta[q[i].x]) ? "YES" : "NO");
	}
	return 0;
}