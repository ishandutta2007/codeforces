//By: Luogu@rui_er(122461).
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 1e5+5; 

ll n, m, k, a[N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld%lld%lld", &n, &m, &k);
	rep(i, 1, n) {
		scanf("%lld", &a[i]);
		a[i] -= k;
		if(a[i-1] <= 0 && a[i] > 0) ++ans;
	}
	while(m --> 0) {
		ll op, x, y;
		scanf("%lld", &op);
		if(!op) printf("%lld\n", ans);
		else {
			scanf("%lld%lld", &x, &y);
			a[x] += y;
			if(a[x] > 0 && a[x] <= y) {
				++ans;
				if(a[x-1] > 0) --ans;
				if(a[x+1] > 0) --ans;
			}
		}
	}
	return 0;
}