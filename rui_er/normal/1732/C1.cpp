// LUOGU_RID: 91301931
// Problem: C1. Sheikh (Easy version)
// Contest: Codeforces - Codeforces Round #830 (Div. 2)
// URL: https://codeforc.es/contest/1732/problem/C1
// Memory Limit: 256 MB
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
const ll N = 1e5+5;

ll T, n, m, a[N], b[N], nxt[N], pos[N], id, ssum[N], xsum[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll calc(ll l, ll r) {
	return (ssum[r] - ssum[l-1]) - (xsum[r] ^ xsum[l-1]);
}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &n, &m);
		rep(i, 1, n) scanf("%lld", &a[i]);
		ll u = n + 1;
		per(i, n, 1) {
			if(!a[i]) u = i;
			nxt[i] = u;
		}
		b[1] = 1;
		pos[1] = 0;
		id = 2;
		rep(i, 1, n) {
			if(a[i]) {
				++id;
				b[id] = a[i];
				pos[id] = i;
			}
		}
		++id;
		b[id] = 1;
		pos[id] = n + 1;
		rep(i, 1, id) ssum[i] = ssum[i-1] + b[i];
		rep(i, 1, id) xsum[i] = xsum[i-1] ^ b[i];
		while(m--) {
			ll _l, _r;
			scanf("%lld%lld", &_l, &_r);
			ll l = lower_bound(pos+1, pos+1+id, _l) - pos;
			ll r = upper_bound(pos+1, pos+1+id, _r) - pos - 1;
			if(l > r) printf("%lld %lld\n", _l, _l);
			else if(!calc(l, r) && nxt[_l] <= _r) printf("%lld %lld\n", nxt[_l], nxt[_l]);
			else{
				ll ansL = l, ansR = r;
				rep(L, l, min(r, l+50)) {
					rep(R, max(L, r-50), r) {
						if(calc(L, R) == calc(l, r)) {
							if(pos[R] - pos[L] + 1 < pos[ansR] - pos[ansL] + 1) {
								ansL = L;
								ansR = R;
							}
						}
					}
				}
				printf("%lld %lld\n", pos[ansL], pos[ansR]);
			}
		}
		rep(i, 1, n) a[i] = b[i] = nxt[i] = pos[i] = ssum[i] = xsum[i] = 0;
		id = 0;
	}
	return 0;
}