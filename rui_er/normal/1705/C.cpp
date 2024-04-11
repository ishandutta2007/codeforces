// Problem: C. Mark and His Unfinished Essay
// Contest: Codeforces - Codeforces Round #807 (Div. 2)
// URL: https://codeforces.com/contest/1705/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll T, n, c, q, sum[N];
char s[N];
vector<tuple<ll, ll> > append;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
char find(ll x) {
	// printf("FIND %lld\n", x);
	if(x <= n) return s[x];
	ll l = 0, r = c + 1;
	while(l < r) {
		ll mid = (l + r) >> 1;
		if(sum[mid] < x) l = mid + 1;
		else r = mid;
	}
	ll qwq = x - sum[l-1];
	// printf("FIND %lld -> %lld %lld\n", x, l, qwq);
	return find(get<0>(append[l])+qwq-1);
}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld%lld%s", &n, &c, &q, s+1);
		append.clear();
		append.emplace_back(1, n);
		sum[0] = n;
		rep(i, 1, c) {
			ll l, r;
			scanf("%lld%lld", &l, &r);
			append.emplace_back(l, r);
			sum[i] = sum[i-1] + (r - l + 1);
		}
		rep(i, 1, q) {
			ll x;
			scanf("%lld", &x);
			printf("%c\n", find(x));
		}
	}
	return 0;
}