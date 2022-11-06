//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

ll T, n;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll ask(ll L, ll R) {
	if(L >= R || R > n) return 0;
	printf("? %lld %lld\n", L, R);
	fflush(stdout);
	scanf("%lld", &L);
	return L;
}
void give(ll i, ll j, ll k) {
	printf("! %lld %lld %lld\n", i, j, k);
	fflush(stdout);
}
void solve() {
	scanf("%lld", &n);
	ll L = 1, R = n, I = n + 1, J = 0, K = 0;
	if(ask(1, 2) == 1) I = 1;
	else {
		while(R - L >= 2) {
			ll M = (L + R) >> 1;
			ll res = ask(L, M+1);
			if(!res) L = M;
			else {
				if(res == 1) chkmin(I, M);
				R = M;
			}
		}
		if(I == n + 1) rep(i, L, R) if(ask(L, i+1) == 1) {chkmin(I, i); break;}
	}
	ll p = 0, q = 0, len = 0;
	p = ask(I, n);
	q = ask(I+1, n);
	len = p - q + 1;
	J = I + len;
	p = ask(J, n);
	q = ask(J+1, n);
	len = p - q + 1;
	K = J + len - 1;
	give(I, J, K);
}

int main() {
	for(scanf("%lld", &T);T;T--) solve();
    return 0;
}