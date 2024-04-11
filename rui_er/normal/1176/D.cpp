//mo ni sai
//By: OIer rui_er
#include <bits/stdc++.h>
#include <set>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 3e6+5;

ll n, a[N], b[N], tab[N], del[N], p[N], pcnt, id[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void sieve(ll lim) {
	rep(i, 2, lim) {
		if(!tab[i]) {
			p[++pcnt] = i;
			id[i] = pcnt;
		}
		for(ll j=1;j<=pcnt&&i*p[j]<=lim;j++) {
			tab[i*p[j]] = 1;
			id[i*p[j]] = i;
			if(!(i % p[j])) break;
		}
	}
}

int main() {
//	fileIO("btoa");
	sieve(3000000);
	scanf("%lld", &n);
	rep(i, 1, 2*n) scanf("%lld", &b[i]);
	sort(b+1, b+1+2*n, greater<ll>());
	ll cnt = 0;
	rep(i, 1, 2*n) {
		if(del[b[i]]) {
			--del[b[i]];
			continue;
		}
		if(tab[b[i]]) {
			a[++cnt] = b[i];
			++del[id[b[i]]];
		}
		else {
			a[++cnt] = id[b[i]];
			++del[id[b[i]]];
		}
	}
	rep(i, 1, n) printf("%lld%c", a[i], " \n"[i==n]);
	return 0;
}