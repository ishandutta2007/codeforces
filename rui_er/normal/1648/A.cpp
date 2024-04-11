//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll n, m, ans;
vector<ll> a[N];
vector<ll> x[N], y[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n) a[i].resize(m+1);
	rep(i, 1, n) rep(j, 1, m) {
		scanf("%lld", &a[i][j]);
		x[a[i][j]].push_back(i);
		y[a[i][j]].push_back(j);
	}
	rep(i, 1, 100000) {
		sort(x[i].begin(), x[i].end());
		sort(y[i].begin(), y[i].end());
		ll now = 0, tot = 0, lst = -1;
		for(auto j : x[i]) {
			if(lst != -1) now += (j - lst) * tot;
			++tot; lst = j; ans += now;
		}
		now = 0; tot = 0; lst = -1;
		for(auto j : y[i]) {
			if(lst != -1) now += (j - lst) * tot;
			++tot; lst = j; ans += now;
		}
	}
	printf("%lld\n", ans);
	return 0;
}