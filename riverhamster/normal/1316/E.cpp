#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	char getc () {return gc();}
	inline void flush () {fwrite (obuf, 1, oS - obuf, stdout); oS = obuf;}
	inline void putc (char x) {*oS ++ = x; if (oS == oT) flush ();}
	template <class I> inline void gi (I &x) {for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;}
	template <class I> inline void print (I x) {if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;while (x) qu[++ qr] = x % 10 + '0',  x /= 10;while (qr) putc (qu[qr --]);}
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi; using io :: putc; using io :: print; using io :: getc;
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

const int N = 100005, ST = (1 << 7) + 2, P = 8;
ll f[2][ST];
int popc[ST];

struct Par{
	int v, s[7];
}a[N];
bool cmp(Par a, Par b){return a.v > b.v;}

int main(){
	// File("cf1316e");
	int n, p, k;
	gi(n); gi(p); gi(k);
	for(int i=1; i<=n; i++) gi(a[i].v);
	for(int i=1; i<=n; i++)
		for(int j=0; j<p; j++) gi(a[i].s[j]);
	sort(a+1, a+1+n, cmp);
	ll s = 0;
	for(int i=1; i<=p+k; i++) s += a[i].v;
	int U = (1 << p) - 1;
	for(int i=1; i<=U; i++)
		popc[i] = popc[i >> 1] + (i & 1);
	int now, lst;
	fill_n(f[0] + 1, U, -(1LL<<61));
	f[0][0] = 0;
	for(int i=1; i<=n; i++){
		now = i & 1; lst = now ^ 1;
		fill_n(f[now], U + 1, -(1LL << 61));
		for(int S=0; S<=U; S++){
			upmax(f[now][S], f[lst][S] + (i - popc[S] <= k ? a[i].v : 0));
			for(int j=0; j<p; j++)
				if(((S >> j) & 1) == 0)
					upmax(f[now][S | (1 << j)], f[lst][S] + a[i].s[j]);
		}
	}
	printf("%lld\n", f[n & 1][U]);
	return 0;
}