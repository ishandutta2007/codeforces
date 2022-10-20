#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush () {fwrite (obuf, 1, oS - obuf, stdout); oS = obuf;}
	inline void putc (char x) {*oS ++ = x; if (oS == oT) flush ();}
	template <class I> inline void gi (I &x) {for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;}
	template <class I> inline void print (I x) {if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;while (x) qu[++ qr] = x % 10 + '0',  x /= 10;while (qr) putc (qu[qr --]);}
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi; using io :: putc; using io :: print;

const int N = 200005;
ll p[N], ps[N], a, b, x, y;

int main(){
	// File("a");
	int T;
	gi(T);
	while(T--){
		int n;
		gi(n);
		for(int i=1; i<=n; i++) gi(p[i]), p[i] /= 100;
		gi(x); gi(a);
		gi(y); gi(b);
		ll k; gi(k);
		sort(p+1, p+1+n, greater<int>());
		for(int i=1; i<=n; i++) ps[i] = ps[i-1] + p[i];
		if(x < y) swap(x, y), swap(a, b);
		ll p1 = a, p2 = b, lp1 = 0, lp2 = 0, c1 = 0, c2 = 0, c3 = 0, now = 0;
		while(p1 <= n && p2 <= n){
			if(p1 < p2){
				++c2; lp1 = p1;
				now = ps[c1] * (x+y) + (ps[c1 + c2] - ps[c1]) * x + (ps[c1 + c2 + c3] - ps[c1 + c2]) * y;
				if(now >= k) break;
				p1 += a;
			}
			else if(p1 > p2){
				++c3; lp2 = p2;
				now = ps[c1] * (x+y) + (ps[c1 + c2] - ps[c1]) * x + (ps[c1 + c2 + c3] - ps[c1 + c2]) * y;
				if(now >= k) break;
				p2 += b;
			}
			else{
				++c1; lp1 = p1; lp2 = p2;
				now = ps[c1] * (x+y) + (ps[c1 + c2] - ps[c1]) * x + (ps[c1 + c2 + c3] - ps[c1 + c2]) * y;
				if(now >= k) break;
				p1 += a; p2 += b;
			}
			// printf("p1 = %lld p2 = %lld now = %lld\n", p1, p2, now);
			// if(now >= k) break;
		}
		// printf("Finalizing p1 %lld p2 %lld now %lld\n", p1, p2, now);
		if(now >= k) printf("%lld\n", max(lp1, lp2));
		else{
			while(p1 <= n){
				++c2; lp1 = p1;
				now = ps[c1] * (x+y) + (ps[c1 + c2] - ps[c1]) * x + (ps[c1 + c2 + c3] - ps[c1 + c2]) * y;
				if(now >= k) break;
				p1 += a;
			}
			while(p2 <= n){
				++c3; lp2 = p2;
				now = ps[c1] * (x+y) + (ps[c1 + c2] - ps[c1]) * x + (ps[c1 + c2 + c3] - ps[c1 + c2]) * y;
				if(now >= k) break;
				p2 += b;
			}
			if(now < k) puts("-1");
			else printf("%lld\n", max(lp1, lp2));
		}
	}
	return 0;
}