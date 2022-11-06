//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	ll ans = 0;
	rep(i, 1, n) ans += 1LL * a[i] * (n - a[i] + 1);
	rep(i, 2, n) {
		int mn = min(a[i-1], a[i]), mx = a[i-1] ^ a[i] ^ mn;
		ans -= 1LL * mn * (n - mx + 1);
	}
	printf("%lld\n", ans);
	return 0;
}