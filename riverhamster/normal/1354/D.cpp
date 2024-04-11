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
int tr[N];
int n, q, high;
inline void modify(int p, int v){
	for(; p<=n; p += p & -p) tr[p] += v;
}
inline int kth(int k){
	int s = 0;
	for(int p=high; p; p >>= 1)
		if(s + p <= n && tr[s + p] < k) k -= tr[s + p], s += p;
	return s + 1;
}

int main(){
	// File("cf1345d");
	gi(n); gi(q);
	high = 1;
	while((high << 1) <= n) high <<= 1;
	for(int i=1; i<=n; i++){
		int x; gi(x);
		modify(x, 1);
	}
	for(int i=1; i<=q; i++){
		int x; gi(x);
		if(x > 0) modify(x, 1);
		else modify(kth(-x), -1);
	}
	printf("%d\n", kth(1) == n + 1 ? 0 : kth(1));
	return 0;
}