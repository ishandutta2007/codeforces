#include <bits/stdc++.h>

#define I inline
#define fi first
#define se second
#define R register
#define LL long long
#define mp make_pair
#define reg register int
#define pii pair<int,int>
#define fo(i, a, b) for(reg i = a; i <= b; i++)
#define fd(i, a, b) for(reg i = a; i >= b; i--)
#define cr const reg&
using namespace std;
const int mod = 998244353, N = 3e5 + 1;

I int _max(cr x, cr y) {return x > y ? x : y;}
I int _min(cr x, cr y) {return x < y ? x : y;}
I int read() {
	reg x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return x * f;
}
I void ptt(LL x) {if(x >= 10) ptt(x / 10); putchar(x % 10 + '0');}
I void put(LL x) {x < 0 ? putchar('-'), ptt(-x) : ptt(x);}
I void pr1(LL x) {put(x), putchar(' ');}
I void pr2(LL x) {put(x), puts("");}

struct edge {
	int x, y, next;
} e[N * 2]; int len, last[N];
LL f[N][3];
//012 

I void ins(cr x, cr y) {e[++len] = edge{x, y, last[x]}, last[x] = len;}

void dfs(cr x, cr fa) {
	reg tt = 1, zz = 1, ss = 1;
	for(reg k = last[x]; k; k = e[k].next) if(e[k].y ^ fa){
		reg y = e[k].y; dfs(y, x);
		LL c = (f[y][0] + f[y][1] + f[y][2]) % mod;
		tt = c * tt % mod;
		zz = (c + f[y][0] * 2 + f[y][1] + f[y][2]) % mod * zz % mod;
		ss = (c + f[y][0] + f[y][2]) % mod * ss % mod;
	} f[x][0] = tt, f[x][2] = (zz - tt + mod) % mod, f[x][1] = (ss - tt + mod) % mod;
	
}

int main() {
	reg n = read();
	fo(i, 1, n - 1) {
		reg x = read(), y = read();
		ins(x, y), ins(y, x);
	} dfs(1, 0);
	pr2((f[1][0] + f[1][1] + f[1][2] - 1 + mod) % mod);
	return 0;
}