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
const int N = 2e5 + 1;

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

char ss[N];
int g[N][26], s[N];

int main() {
	reg T = read();
	while(T--) {
		reg n = read(), k = read();
		scanf("%s", ss);
		fo(i, 0, n - 1) 
		g[_min(i % k, k - 1 - i % k)][ss[i] - 'a']++, s[_min(i % k, k - 1 - i % k)]++;
		reg ans = 0;
		fo(i, 0, k - 1) {
			reg c = 0;
			fo(j, 0, 25) c = _max(c, g[i][j]);
			ans += s[i] - c;
		} pr2(ans);
		fo(i, 0, k - 1) fo(j, 0, 25) g[i][j] = 0, s[i] = 0;
	}
	return 0;
}