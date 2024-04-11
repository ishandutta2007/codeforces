// Problem: B. Stone Age Problem
// Contest: Codeforces - Codeforces Round #791 (Div. 2)
// URL: https://codeforces.com/contest/1679/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll n, m, a[N], cg[N], all, allrnd = -1, ans;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n) scanf("%lld", &a[i]), ans += a[i];
	rep(_, 1, m) {
		ll op, x, y;
		scanf("%lld%lld", &op, &x);
		if(op == 1) {
			scanf("%lld", &y);
			ans += y - (cg[x] > allrnd ? a[x] : all);
			a[x] = y;
			cg[x] = _;
		}
		else {
			ans = n * x;
			all = x;
			allrnd = _;
		}
		printf("%lld\n", ans);
	}
	return 0;
}