//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 1e4+5;

ll n, k, a[N], p[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
ll askOr(ll x, ll y) {
	printf("or %lld %lld\n", x, y);
	fflush(stdout);
	scanf("%lld", &x);
	return x;
}
ll askAnd(ll x, ll y) {
	printf("and %lld %lld\n", x, y);
	fflush(stdout);
	scanf("%lld", &x);
	return x;
}
void give(ll x) {
	printf("finish %lld\n", x);
	fflush(stdout);
}

int main() {
	scanf("%lld%lld", &n, &k);
	rep(i, 2, n) p[i] = askOr(1, i) + askAnd(1, i);
	ll qwq = askOr(2, 3) + askAnd(2, 3);
	a[1] = (p[2] + p[3] - qwq) / 2;
	rep(i, 2, n) a[i] = p[i] - a[1];
	nth_element(a+1, a+k, a+1+n);
	give(a[k]);
	return 0;
}