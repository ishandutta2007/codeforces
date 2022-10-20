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
	inline void flush () {fwrite (obuf, 1, oS - obuf, stdout); oS = obuf;}
	inline void putc (char x) {*oS ++ = x; if (oS == oT) flush ();}
	template <class I> inline void gi (I &x) {for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;}
	template <class I> inline void print (I x) {if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;while (x) qu[++ qr] = x % 10 + '0',  x /= 10;while (qr) putc (qu[qr --]);}
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi; using io :: putc; using io :: print;

const int N = 300005;
int a[N], disc[N], L[N], R[N];

int main(){
	// File("b");
	int T;
	gi(T);
	while(T--){
		int n, cc;
		gi(n);
		for(int i=1; i<=n; i++) gi(a[i]), disc[i] = a[i];
		sort(disc+1, disc+1+n);
		cc = unique(disc+1, disc+1+n) - disc - 1;
		for(int i=1; i<=cc; i++) L[i] = 0x3f3f3f3f, R[i] = 0;
		// memset(L, 0x3f, sizeof(L)); memset(R, 0, sizeof(R));
		for(int i=1; i<=n; i++){
			a[i] = lower_bound(disc+1, disc+1+cc, a[i]) - disc;
			L[a[i]] = min(L[a[i]], i);
			R[a[i]] = max(R[a[i]], i);
		}
		int res = 1;
		for(int i=1; i<=cc; i++){
			int r = R[i];
			bool flag = true;
			for(int j=i+1; j<=cc; j++){
				if(L[j] < r){
					i = j - 1; flag = false; break;
				}
				r = R[j];
				res = max(res, j - i + 1);
			}
			if(flag) break;
		}
		printf("%d\n", cc - res);
	}
	return 0;
}