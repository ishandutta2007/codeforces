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

bool v[100000];
int plen, p[1000];
int ans[10001], z[12];

int main() {
	reg q = sqrt(1000);
	fo(i, 2, q) if(!v[i]){
		for(reg j = i; j <= q; j += i) v[j] = 1;
		p[++plen] = i;
	} reg T = read();
	while(T--) {
		reg n = read();
		memset(z, 0, sizeof(z));
		fo(i, 1, n) {
			reg x = read();
			fo(j, 1, plen) if(x % p[j] == 0){
				z[j] = 1, ans[i] = j; break;
			}
		} reg s = 0;
		fo(i, 1, plen) if(z[i]) z[i] = ++s;
		pr2(s);
		fo(i, 1, n) pr1(z[ans[i]]); puts("");
	}
	return 0;
}