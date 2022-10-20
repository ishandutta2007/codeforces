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
const int N = 1000005;
int s[N], t = 0;
ll sum[N];

int main(){
	// File("cf1299c");
	int n;
	gi(n);
	for(int i=1; i<=n; i++){
		gi(sum[i]), sum[i] += sum[i-1];
		while(t && (sum[s[t]] - sum[s[t-1]]) * (i - s[t]) >= (sum[i] - sum[s[t]]) * (s[t] - s[t-1])) --t;
		s[++t] = i;
	}
	// for(int i=1; i<=t; i++) printf("%d ", s[i]);
	// putchar('\n');
	int p = 1;
	long double now = (long double)sum[s[1]] / s[1];
	for(int i=1; i<=n; i++){
		printf("%.15Lf\n", now);
		if(p < t && i == s[p]){
			++p;
			now = (long double)(sum[s[p]] - sum[s[p-1]]) / (s[p] - s[p-1]);
		}
		// printf("i = %d s[p+1] = %d\n", i, s[p+1]);
	}
	return 0;
}