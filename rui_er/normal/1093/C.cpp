//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 2e5+5; 

ll n, a[N], b[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n/2) scanf("%lld", &b[i]);
	a[1] = 0; a[n] = b[1];
	rep(i, 2, n/2) {
		a[n-i+1] = min(min(a[n-i+2], b[i]), b[i]-a[i-1]);
		a[i] = b[i] - a[n-i+1];
	}
	rep(i, 1, n) printf("%lld%c", a[i], " \n"[i==n]);
	return 0;
}