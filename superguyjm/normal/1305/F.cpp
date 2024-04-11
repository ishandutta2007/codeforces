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

LL a[N];
set<LL> q;

int main() {
	reg n = read(), ans = 0;
	fo(i, 1, n) a[i] = read(), ans += a[i] & 1;
    shuffle(a+1,a+1+n,default_random_engine (time(0)));
	fo(j, 1, _min(n, 100)) {
		if(a[j] == 1) continue;
		LL x = a[j];
		for(LL i = 2; i * i <= x; i++) if(x % i == 0){
			q.insert(i);
			while(x % i == 0) x /= i;
		} if(x > 1) q.insert(x);
		x = a[j] - 1;
		for(LL i = 2; i * i <= x; i++) if(x % i == 0){
			q.insert(i);
			while(x % i == 0) x /= i;
		} if(x > 1) q.insert(x);
		x = a[j] + 1;
		for(LL i = 2; i * i <= x; i++) if(x % i == 0){
			q.insert(i);
			while(x % i == 0) x /= i;
		} if(x > 1) q.insert(x);
	} for(LL p : q) {
		LL z = 0;
		fo(i, 1, n) {
			if(a[i] % p == 0) continue;
			if(a[i] < p) z += p - a[i];
			else z += min(a[i] % p, p - a[i] % p);
			if(z > ans) break;
		} if(z < ans) ans = z;
	} pr2(ans);
	return 0;
}