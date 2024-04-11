//Created time: 2022/3/6 17:53:19
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x, T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x, T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
#ifdef FASTIO
namespace fastio {
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getc();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getc();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getc();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=-x;recursive_print(x);}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void readstr(char *s){
		char c=getc();
		while(c<=32||c>=127) c=getc();
		while(c>32&&c<127) s[0]=c,s++,c=getc();
		(*s)=0;
	}
	void printstr(string s){for(int i=0;i<s.size();i++) putc(s[i]);}
	void printstr(char *s){int len=strlen(s);for(int i=0;i<len;i++) putc(s[i]);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
using namespace fastio;
#endif
const int MAXN = 2e5;
const int MOD = 998244353;
int n, m, a[MAXN + 5], b[MAXN + 5];
int cnta[MAXN + 5], cntb[MAXN + 5];
int fac[MAXN + 5], ifac[MAXN + 5], inv[MAXN + 5];
void init_fac(int n) {
	for (int i = (fac[0] = ifac[0] = inv[0] = inv[1] = 1) + 1; i <= n; i++)
		inv[i] = 1ll * inv[MOD % i] * (MOD - MOD / i) % MOD;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % MOD;
		ifac[i] = 1ll * ifac[i - 1] * inv[i] % MOD;
	}
}
int t[MAXN + 5];
void add(int x, int v) {for (int i = x; i <= MAXN; i += (i & (-i))) t[i] = (t[i] + v) % MOD;}
int query(int x) {int ret = 0; for (int i = x; i; i &= (i - 1)) ret = (ret + t[i]) % MOD; return ret;}
int main(){
	init_fac(MAXN); scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cnta[a[i]]++;
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]), cntb[b[i]]++;
	int prd = 1, ret = 0;
	for (int i = 1; i <= MAXN; i++) prd = 1ll * prd * ifac[cnta[i]] % MOD;
	for (int i = 1; i <= MAXN; i++) add(i, cnta[i]);
	for (int i = 1; i <= m; i++) {
		if (!query(MAXN)) ret = (ret + 1) % MOD;
		ret = (ret + 1ll * fac[n - i] * prd % MOD * query(b[i] - 1)) % MOD;
		if (!cnta[b[i]]) break;
		prd = 1ll * prd * cnta[b[i]] % MOD;
		cnta[b[i]]--; add(b[i], MOD - 1);
	}
	printf("%d\n", ret);
	return 0;
}