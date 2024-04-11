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

I int _max(cr x, cr y) {return x > y ? x : y;}
I int _min(cr x, cr y) {return x < y ? x : y;}
I LL read() {
	LL x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return x * f;
}
I void ptt(LL x) {if(x >= 10) ptt(x / 10); putchar(x % 10 + '0');}
I void put(LL x) {x < 0 ? putchar('-'), ptt(-x) : ptt(x);}
I void pr1(LL x) {put(x), putchar(' ');}
I void pr2(LL x) {put(x), puts("");}

int main() {
	reg T = read();
	while(T--) {
		LL a = read(), b = read(), c = read(), d = read();
		LL x = read(), y = read(), x1 = read(), y1 = read(), x2 = read(), y2 = read();
		if(x1 == x2 && a && b) puts("NO");
		else if(y1 == y2 && c && d) puts("NO");
		else if(x + b - a >= x1 && x + b - a <= x2 && y + d - c >= y1 && y + d - c <= y2) puts("YES");
		else puts("NO");
	}
	return 0;
}