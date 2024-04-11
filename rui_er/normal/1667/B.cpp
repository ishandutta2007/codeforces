// Problem: CF1667B Optimal Partition
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1667B
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 5e5+5, inf = 0x3f3f3f3f3f3f3f3fll;

ll T, n, m, a[N], b[N], dp[N], buc2[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct BIT {
	ll c[N];
	ll lowbit(ll x) {return x & (-x);}
	void ins(ll x, ll k) {for(;x<=m;x+=lowbit(x)) chkmax(c[x], k);}
	ll ask(ll x) {ll k = -inf; for(;x;x-=lowbit(x)) chkmax(k, c[x]); return k;}
}buc1, buc3;

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &n);
		b[0] = 0;
		rep(i, 1, n) {
			scanf("%lld", &a[i]);
			a[i] += a[i-1];
			b[i] = a[i];
		}
		sort(b, b+1+n);
		m = unique(b, b+1+n) - b;
		rep(i, 1, n) a[i] = lower_bound(b, b+m, a[i]) - b + 1;
		
		rep(i, 1, m) buc1.c[i] = buc2[i] = buc3.c[i] = -inf;
		rep(i, 1, n) dp[i] = -inf;
		ll zero = lower_bound(b, b+m, 0) - b + 1;
		buc1.ins(zero, 0);
		buc2[zero] = 0;
		buc3.ins(m + 1 - zero, 0);
		
		rep(i, 1, n) {
			if(a[i] > 1) chkmax(dp[i], buc1.ask(a[i] - 1) + i);
			chkmax(dp[i], buc2[a[i]]);
			if(a[i] < m) chkmax(dp[i], buc3.ask(m - a[i]) - i);
			buc1.ins(a[i], dp[i] - i);
			chkmax(buc2[a[i]], dp[i]);
			buc3.ins(m + 1 - a[i], dp[i] + i);
			// debug("DP[%lld] = %lld; A[%lld] = %lld\n", i, dp[i], i, a[i]);
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}