#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
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

const int N = 1000005, FAC = 13970033 + 5;
int mu[N], p[N], pc = 0;
int a[N], A = 0;
int f[FAC], fc = 0;
int stk[FAC], top = 0;
bool app[N], np[N];
vector<int> fac[N];
int cnt[N], now, nowsum = 0;

void getmu(int n){
	mu[1] = 1;
	for(int i=2; i<=n; i++){
		if(!np[i]) p[++pc] = i, mu[i] = -1;
		for(int j=1; j<=pc && i * p[j] <= n; j++){
			int v = i * p[j];
			np[v] = true;
			if(i % p[j] == 0){
				mu[v] = 0;
				break;
			}
			mu[v] = -mu[i];
		}
	}
	// puts("Prime list:");
	// for(int i=1; i<=20; i++) printf("%d ", p[i]);
	// putchar('\n');
}

void modify(int p, int v){
	for(int x : fac[p]){
		cnt[x] += v;
		// printf("cnt[%d] += %d\n", x, v);
		if(now % x == 0) nowsum += v * mu[x];
	}
}
int gcd(int x, int y){
	int t;
	while(y) t = x, x = y, y = t % y;
	return x;
}

ll work(int n){
	ll res = 0;
	for(int i=n; i>=1; i--){
		// printf("f[%d] = %d\n", i, f[i]);
		upmax(res, 0LL + f[i]);
		now = f[i];
		nowsum = 0;
		for(int x : fac[f[i]]) nowsum += cnt[x] * mu[x];//, printf("cnt[%d](%d) * mu[%d](%d)\n", x, cnt[x], x, mu[x]);
		// printf("nowsum = %d\n", nowsum);
		while(nowsum && top){
			while(top && gcd(f[i], stk[top]) != 1) modify(stk[top], -1), --top;
			if(top){
				upmax(res, 1LL * f[i] * stk[top]);
				modify(stk[top], -1); --top;
			}
		}
		stk[++top] = f[i];
		modify(f[i], 1);
	}
	return res;
}

int main(){
	// File("4028");
	// setbuf(stdout, NULL);
	int n;
	gi(n);
	for(int i=1; i<=n; i++) gi(a[i]), A = max(A, a[i]), app[a[i]] = true;
	getmu(A);
	for(int i=1; i<=A; i++)
		for(int j=i; j<=A; j+=i)
			fac[j].push_back(i);
	sort(a+1, a+1+n);
	n = unique(a+1, a+1+n) - a - 1;
	for(int i=1; i<=A; i++)
		for(int j=i; j<=A; j+=i)
			if(app[j]){
				f[++fc] = i;
				// printf("Inserted %d\n", i);
				break;
			}
	printf("%lld\n", work(fc));
	return 0;
}