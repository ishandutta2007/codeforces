// Problem: B. Rain
// Contest: Codeforces - Codeforces Round #810 (Div. 1)
// URL: https://codeforces.com/contest/1710/problem/B
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5, inf = 0x3f3f3f3f3f3f3f3fll;

ll T, n, m, diff1[N], diff2[N], ans[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Rain {
	ll x, p, id;
	Rain(ll a=0, ll b=0, ll c=0) : x(a), p(b), id(c) {}
	friend bool operator < (const Rain& a, const Rain& b) {
		if(a.x != b.x) return a.x < b.x;
		return a.p < b.p;
	}
}a[N];

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &n, &m);
		rep(i, 1, n) diff1[i] = diff2[i] = ans[i] = 0;
		rep(i, 1, n) scanf("%lld%lld", &a[i].x, &a[i].p), a[i].id = i;
		sort(a+1, a+1+n);
		rep(i, 1, n) {
			{
				ll id = lower_bound(a+1, a+1+n, Rain(a[i].x-a[i].p)) - a;
				++diff1[id]; diff2[id] += a[i].p - a[i].x;
				--diff1[i+1]; diff2[i+1] -= a[i].p - a[i].x;
			}
			{
				ll id = upper_bound(a+1, a+1+n, Rain(a[i].x+a[i].p, inf)) - a;
				--diff1[i+1]; diff2[i+1] += a[i].x + a[i].p;
				++diff1[id]; diff2[id] -= a[i].x + a[i].p;
			}
		}
		ll mxa = -inf, mxb = -inf;
		rep(i, 1, n) {
			diff1[i] += diff1[i-1];
			diff2[i] += diff2[i-1];
			ll now = diff2[i] + diff1[i] * a[i].x;
			if(now > m) {
				chkmax(mxa, now - m + a[i].x);
				chkmax(mxb, now - m - a[i].x);
			}
		}
		rep(i, 1, n) ans[a[i].id] = (a[i].x + a[i].p >= mxa) && (a[i].p - a[i].x >= mxb);
		rep(i, 1, n) putchar(ans[i] ^ 48);
		puts("");
	}
	return 0;
}