//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll T, n, a[N], sum;
map<ll, ll> buc;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool check(ll x) {
	if(buc[x]) {--buc[x]; return 1;}
	if(x == 1) return 0;
	return check(x>>1) && check((x+1)>>1);
}

int main() {
	for(scanf("%lld", &T);T;T--) {
		sum = 0;
		buc.clear();
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld", &a[i]);
		rep(i, 1, n) sum += a[i];
		rep(i, 1, n) ++buc[a[i]];
		puts(check(sum)?"YES":"NO");
	}
	return 0;
}