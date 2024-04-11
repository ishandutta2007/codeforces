#include<bits/stdc++.h>

using namespace std;

typedef long long INT;

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}

int power(int a, int b, int m, int ans=1) {
	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
	return ans;
}

#define mod 1000000007
#define NN 200010

int fac[NN], rev[NN];
int f, w, h;

inline int c(int n, int k) {
	return (INT) fac[n] * rev[k] % mod * rev[n-k] % mod;
}

inline int calc(int n, int k, int h) {
	if((INT) k * h > n) return 0;
	n -= k * h;
	return c(n + k -1, k - 1);
}

INT tot, tot_like = 0;

inline int solve(int u, int v) {
	if(u == 0 || v == 0) return 0;
	int s = calc(f, u, 1);
	int mul = 1 + (u == v);
	tot += (INT) mul * s * calc(w, v, 1) % mod;
	tot_like += (INT) mul * s * calc(w, v, h+1) % mod;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	fac[0] = 1;
	for(int i=1; i<NN; i++) fac[i] = (INT) fac[i-1] * i % mod;
	rev[NN-1] = power(fac[NN-1], mod-2, mod);
	for(int i=NN-2; i>=0; i--) rev[i] = (INT) rev[i+1] * (i + 1) % mod;
	gn(f, w); gn(h);
	
	if(f == 0) {
		if(w >= h + 1) return puts("1"), 0;
		else return puts("0"), 0;
	}
	if(w == 0) return puts("1"), 0;
	
	for(int i=1; i<=f; i++) solve(i, i-1), solve(i, i+1), solve(i, i);
	
	tot %= mod, tot_like %= mod;
	
	printf("%d\n", tot_like * power(tot, mod-2, mod) % mod);
}