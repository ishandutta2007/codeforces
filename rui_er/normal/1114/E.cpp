//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e6+5; 

int n, a[N], p[N], now;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int ask_gt(int x) {
	++now;
	printf("> %d\n", x);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}
int ask_va(int x) {
	++now;
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}
void give(int x, int d) {
	printf("! %d %d\n", x, d);
	fflush(stdout);
}

int main() {
	scanf("%d", &n);
	mt19937 rnd(time(0));
	uniform_int_distribution<int> dist(1, n);
	int L = 0, R = 1000000000, mx = 0;
	while(L <= R) {
		int M = (L + R) >> 1;
		if(ask_gt(M)) L = M + 1;
		else R = M - 1, mx = M;
	}
	rep(i, 1, n) p[i] = i;
	shuffle(p+1, p+1+n, rnd);
	int m = 0, d = 0;
	for(int i=1;i<=n&&now<60;i++) a[m=i] = ask_va(p[i]);
	sort(a+1, a+1+m);
	rep(i, 2, m) d = __gcd(d, a[i]-a[i-1]);
	give(mx-d*(n-1), d);
	return 0;
}