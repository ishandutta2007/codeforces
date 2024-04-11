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
const int N = 1001;

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
int du[N];
bool v[N];

I void ins(cr x, cr y) {e[++len] = edge{x, y, last[x]}, last[x] = len;}

int main() {
	reg n = read();
	fo(i, 1, n - 1) {
		reg x = read(), y = read();
		ins(x, y), ins(y, x), du[x]++, du[y]++;
	} fo(p, 1, n / 2) {
		reg p1, p2;
		fo(i, 1, n) if(du[i] == 1 && !v[i]) {p1 = i; break;}
		fo(i, p1 + 1, n) if(du[i] == 1 && !v[i]) p2 = i;
		printf("? %d %d\n", p1, p2);
		fflush(stdout);
		reg x = read();
		if(x == p1 || x == p2) {printf("! %d\n", x); fflush(stdout); return 0;}
		v[p1] = v[p2] = 1;
		for(reg k = last[p1]; k; k = e[k].next) if(!v[e[k].y]) du[e[k].y]--;
		for(reg k = last[p2]; k; k = e[k].next) if(!v[e[k].y]) du[e[k].y]--;
	} fo(i, 1, n) if(!v[i]) printf("! %d\n", i);
	fflush(stdout);
	return 0;
}