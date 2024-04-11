// LUOGU_RID: 95055106
// Problem: F. Interesting Sections
// Contest: Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const ll N = 1e6+5, K = 64, inf = 0x3f3f3f3f3f3f3f3fll;

ll n, a[N], cntmnp[K], cntmxp[K], cntmnq[K], cntmxq[K], cnt[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll popcnt(ll x) {return __builtin_popcountll(x);}
ll solve(ll L, ll R) {
	if(L == R) return 1;
	ll M = (L + R) >> 1;
	ll ans = solve(L, M) + solve(M+1, R);
	ll mnpre = inf, mxpre = -inf;
	cnt[M] = 0;
	rep(i, M+1, R) {
		chkmin(mnpre, a[i]);
		chkmax(mxpre, a[i]);
		cnt[i] = cnt[i-1] + (popcnt(mnpre) == popcnt(mxpre));
	}
	ll mn = inf, mx = -inf;
	ll p = M, q = M, mnp = inf, mxp = -inf, mnq = inf, mxq = -inf;
	per(i, M, L) {
		chkmin(mn, a[i]);
		chkmax(mx, a[i]);
		while(p < R && mn <= min(mnp, a[p+1]) && mx >= max(mxp, a[p+1])) {
			++p;
			chkmin(mnp, a[p]);
			chkmax(mxp, a[p]);
			++cntmnp[popcnt(mnp)];
			++cntmxp[popcnt(mxp)];
		}
		while(q < R && !(mn > min(mnq, a[q+1]) && mx < max(mxq, a[q+1]))) {
			++q;
			chkmin(mnq, a[q]);
			chkmax(mxq, a[q]);
			++cntmnq[popcnt(mnq)];
			++cntmxq[popcnt(mxq)];
		}
		if(popcnt(mn) == popcnt(mx)) ans += p - M;
		ans += cnt[R] - cnt[q];
		if(mn <= mnq) ans += cntmxq[popcnt(mn)] - cntmxp[popcnt(mn)];
		else ans += cntmnq[popcnt(mx)] - cntmnp[popcnt(mx)];
		// printf("[%lld, %lld][%lld, %lld] i = %lld, p = %lld, q = %lld, ans = %lld\n", L, M, M+1, R, i, p, q, ans);
	}
	memset(cntmnp, 0, sizeof(cntmnp));
	memset(cntmxp, 0, sizeof(cntmxp));
	memset(cntmnq, 0, sizeof(cntmnq));
	memset(cntmxq, 0, sizeof(cntmxq));
	// printf("DIVIDE AND CONQUER [%lld, %lld] : %lld\n", L, R, ans);
	return ans;
}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	printf("%lld\n", solve(1, n));
	return 0;
}