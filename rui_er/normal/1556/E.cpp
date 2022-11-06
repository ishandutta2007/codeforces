//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll n, q, a[N], b[N], s[N], sa[N], sb[N], lg[N], stMin[N][19], stMax[N][19];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
void initST(ll* p) {
//	puts("INIT BEGIN");
	rep(i, 1, n) stMin[i][0] = stMax[i][0] = p[i];
//	puts("INIT SELF");
	rep(j, 1, 18) rep(i, 1, n) {
		if(i + (1 << (j - 1)) > n) break;
		stMin[i][j] = min(stMin[i][j-1], stMin[i+(1<<(j-1))][j-1]);
		stMax[i][j] = max(stMax[i][j-1], stMax[i+(1<<(j-1))][j-1]);
	}
//	rep(i, 1, n) rep(j, 1, 18) printf("%lld%c", st[i][j], " \n"[j==18]);
//	puts("INIT END");
}
ll queryST(ll L, ll R, ll tp) {
	ll k = lg[R-L+1];
	if(tp) return max(stMax[L][k], stMax[R-(1<<k)+1][k]);
	return min(stMin[L][k], stMin[R-(1<<k)+1][k]); 
}
ll queryST_M(ll L, ll R, ll tp) {
	return queryST(L, R, tp) - s[L-1];
}
ll queryLR(ll L, ll R, ll* p) {
	return p[R] - p[L-1];
}

int main() {
	lg[0] = -1;
	rep(i, 1, 100000) lg[i] = lg[i>>1] + 1;
	scanf("%lld%lld", &n, &q);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, n) scanf("%lld", &b[i]);
	rep(i, 1, n) s[i] = s[i-1] + b[i] - a[i];
	rep(i, 1, n) sa[i] = sa[i-1] + a[i];
	rep(i, 1, n) sb[i] = sb[i-1] + b[i];
	initST(s);
	while(q--) {
		ll L, R;
		scanf("%lld%lld", &L, &R);
		if(queryLR(L, R, sa) != queryLR(L, R, sb)) {puts("-1"); continue;}
		if(queryST_M(L, R, 0) < 0) {puts("-1"); continue;}
		printf("%lld\n", queryST_M(L, R, 1));
	}
	return 0;
}