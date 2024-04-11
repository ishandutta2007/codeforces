// Problem: E. Two Arrays
// Contest: Codeforces - Codeforces Round #810 (Div. 1)
// URL: https://codeforces.com/contest/1710/problem/E
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

ll n, m, a[N], b[N], idx, idy, mxx[N], mxy[N], prex[N], prey[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool chk(ll x, ll y, bool type) {
	if(!type && (idx > x && idy > y || idx <= x && idy <= min(y, mxx[idx]))) return 1;
	if(type && (idx <= x && idy <= y || idx > x && idy > max(y, mxx[idx]))) return 1;
	return 0;
}
ll match(ll x, ll y, bool cut) {
	if(mxx[x] < y) return mxy[y] * y + prex[x] - prex[mxy[y]] + (n - x) * (m - y) - (cut && chk(x, y, 0));
	else return x * y + ((mxy[y] - x) * m - prex[mxy[y]] + prex[x]) + (n - mxy[y]) * (m - y) - (cut && chk(x, y, 1));
}
bool check(ll M) {
	mxx[0] = m;
	rep(i, 1, n) {
		mxx[i] = mxx[i-1];
		while(mxx[i] && a[i] + b[mxx[i]] > M) --mxx[i];
		prex[i] = prex[i-1] + mxx[i];
	}
	mxy[0] = n;
	rep(i, 1, m) {
		mxy[i] = mxy[i-1];
		while(mxy[i] && a[mxy[i]] + b[i] > M) --mxy[i];
		prey[i] = prey[i-1] + mxy[i];
	}
	ll cnt1 = max(prex[n], n*m-prex[n]);
	{
		ll p = 1;
		rep(i, 1, n) {
			while(p < m && match(i, p, 0) <= match(i, p+1, 0)) ++p;
			chkmax(cnt1, match(i, p, 0));
		}
	}
	ll cnt2 = max(prex[n]-(idy<=mxx[idx]), n*m-prex[n]-(idy>mxx[idx]));
	{
		ll p = 1;
		rep(i, 1, n) {
			while(p < m && match(i, p, 1) <= match(i, p+1, 1)) ++p;
			chkmax(cnt2, match(i, p, 1));
		}
	}
	return cnt1 != cnt2 + 1;
}

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, m) scanf("%lld", &b[i]);
	idx = a[1]; sort(a+1, a+1+n); idx = lower_bound(a+1, a+1+n, idx) - a;
	idy = b[1]; sort(b+1, b+1+m); idy = lower_bound(b+1, b+1+m, idy) - b;
	ll L = a[1] + b[1], R = a[idx] + b[idy];
	ll ans = R;
	while(L <= R) {
		ll M = (L + R) >> 1;
		if(check(M)) R = M - 1, ans = M;
		else L = M + 1;
	}
	printf("%lld\n", ans);
	return 0;
}