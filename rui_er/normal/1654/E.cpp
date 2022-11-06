//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1e5+5, LIM = 317, DELTA = N * LIM;

ll n, a[N], ans, mp[N*10+DELTA*2];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	ans = n;
	rep(d, -LIM, LIM) { // for |d| <= sqrt(w) : enumerate d and calculate the minimum elements that must be changed
		rep(i, 1, n) chkmin(ans, n-(++mp[a[i]-i*d+DELTA]));
		rep(i, 1, n) --mp[a[i]-i*d+DELTA];
	}
	rep(i, 1, n) { // for |d| > sqrt(w) : enumerate i, j (not changing) and calculate the value of d
		ll L = i + 1, R = min(i+LIM, n);
		rep(j, L, R) {
			if(i == j) continue;
			if(abs(a[i] - a[j]) % abs(i - j)) continue;
			ll d = (a[i] - a[j]) / (i - j);
			chkmin(ans, n-((++mp[d+DELTA])+1));
		}
		rep(j, L, R) {
			if(i == j) continue;
			if(abs(a[i] - a[j]) % abs(i - j)) continue;
			ll d = (a[i] - a[j]) / (i - j);
			--mp[d+DELTA];
		}
	}
	printf("%lld\n", ans);
	return 0;
}