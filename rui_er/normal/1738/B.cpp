//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll T, n, k, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &n, &k);
		rep(i, n-k+1, n) scanf("%lld", &a[i]);
		per(i, n, n-k+2) a[i] -= a[i-1];
		if(!is_sorted(a+n-k+2, a+1+n)) puts("No");
		else if(n - k + 2 <= n && a[n-k+1] > a[n-k+2] * (n - k + 1)) puts("No");
		else puts("Yes");
	}
	return 0;
}