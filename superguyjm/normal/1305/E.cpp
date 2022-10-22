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
const int N = 5e3 + 1;

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

int a[N];

int main() {
	reg n = read(), m = read(), p = n + 1;
	reg s = 0;
	fo(i, 1, n) {
		a[i] = i;
		if((i - 1) / 2 + s > m) {p = i; break;}
		s += (i - 1) / 2;
	} if(p == n + 1 && s < m) {puts("-1"); return 0;}
	if(s == m);
	else {
		m -= s;
		reg z = p - 2 * m + p - 1;
		a[p] = z; p++;
	} int q = 1e9;
	fo(i, p, n) a[i] = (int)(1e8+1e4*(i-p));
	fo(i, 1, n) pr1(a[i]);
	return 0;
}