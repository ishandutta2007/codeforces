#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cassert>
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

const int mod = 1000000007;
inline int add(int x, int y){return x+y>=mod ? x+y-mod : x+y;}
inline int sub(int x, int y){return x-y<0 ? x-y+mod : x-y;}
inline int mul(int x, int y){return 1LL * x * y % mod;}
inline int power(int x, int y){
	int res = 1;
	for(; y; y>>=1, x = mul(x, x)) if(y & 1) res = mul(res, x);
	return res;
}
inline int inv(int x){return power(x, mod - 2);}

const int N = 300005, Node = 2400005;
int p[N];
int pow2[N];
int n, q;

int v[N * 2], vc = 0;
int pos[N], val[N], single[N];
#define Rt 1, 1, vc

int pre[Node], suf[Node], sum[Node], sz[Node];
void modify(int x, int l, int r, int p, int d){
	if(l == r){
		// printf("Update p %d d %d\n", p, d);
		sz[x] += d;
		sum[x] = mul(mul(v[p], v[p]), single[sz[x]]);
		if(d == 1) pre[x] = add(pre[x], mul(v[p], pow2[sz[x] - 1])), suf[x] = add(suf[x], mul(v[p], pow2[sz[x] - 1]));
		else pre[x] = sub(pre[x], mul(v[p], pow2[sz[x]])), suf[x] = sub(suf[x], mul(v[p], pow2[sz[x]]));
		return ;
	}
	int mid = (l + r) >> 1;
	p <= mid ? modify(x << 1, l, mid, p, d) : modify(x << 1 | 1, mid + 1, r, p, d);
	sz[x] = sz[x << 1] + sz[x << 1 | 1];
	pre[x] = add(pre[x << 1], mul(pow2[sz[x << 1]], pre[x << 1 | 1]));
	suf[x] = add(suf[x << 1 | 1], mul(pow2[sz[x << 1 | 1]], suf[x << 1]));
	sum[x] = add(add(mul(sum[x << 1], pow2[sz[x << 1 | 1]]), mul(sum[x << 1 | 1], pow2[sz[x << 1]])), mul(pre[x << 1], suf[x << 1 | 1]));
}
#define Rt 1, 1, vc

int main(){
	// File("cf1316f");
	int allinv;
	gi(n);
	pow2[0] = 1;
	for(int i=1; i<=n; i++)
		pow2[i] = add(pow2[i-1], pow2[i-1]);
	for(int i=2; i<=n; i++)
		single[i] = add(add(single[i-1], single[i-1]), sub(pow2[i - 1], 1));
	allinv = inv(pow2[n]);
	for(int i=1; i<=n; i++) gi(p[i]), v[++vc] = p[i];
	gi(q);
	for(int i=1; i<=q; i++){
		gi(pos[i]); gi(val[i]);
		v[++vc] = val[i];
	}
	sort(v+1, v+1+vc);
	vc = unique(v+1, v+1+vc) - v - 1;
	for(int i=1; i<=n; i++){
		p[i] = lower_bound(v+1, v+1+vc, p[i]) - v;
		modify(Rt, p[i], 1);
	}
	// printf("sum[1] = %d\n", sum[1]);
	print(mul(sum[1], allinv)); putc('\n');
	for(int i=1; i<=q; i++){
		val[i] = lower_bound(v+1, v+1+vc, val[i]) - v;
		modify(Rt, p[pos[i]], -1);
		modify(Rt, val[i], 1);
		p[pos[i]] = val[i];
		print(mul(sum[1], allinv)); putc('\n');
	}
	return 0;
}