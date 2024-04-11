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
const int mod = 998244353;

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

I int pow_mod(reg a, reg k) {reg ans = 1; if(a % mod == 0) return 0; for(; k; k >>= 1, a = (LL)a * a % mod) if(k & 1) ans = (LL)ans * a % mod; return ans;}

int main() {
	reg n = read(), m = read(), l = read(), r = read();
	if(n % 2 == 1 && m % 2 == 1) {pr2(pow_mod(r - l + 1, (LL)n * m % (mod - 1))); return 0;}
	reg c1 = r / 2 - (l - 1) / 2, c2 = (r - l + 1) - c1;
	reg gg = ((LL)pow_mod(c1 + c2, (LL)n * m % (mod - 1)) + pow_mod((c1 - c2 + mod) % mod, (LL)n * m % (mod - 1))) % mod;
	reg inv2 = mod + 1 >> 1;
	gg = (LL)gg * inv2 % mod;
	pr2(gg);
	return 0;
}