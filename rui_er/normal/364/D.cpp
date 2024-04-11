//ZR NOIP 0911 C
//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1e6+5;

ll n, nd, a[N], buc[N], ans;
vector<ll> d;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll randint(mt19937& rnd, ll L, ll R) {
	uniform_int_distribution<ll> dist(L, R);
	return dist(rnd);
}

int main() {
	mt19937 rnd(time(0));
	scanf("%lld", &n);
	nd = (n + 1) / 2;
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(T, 1, 9) {
		d.clear();
		ll id = randint(rnd, 1, n);
		for(ll i=1;i*i<=a[id];i++) {
			if(!(a[id] % i)) {
				d.push_back(i);
				if(i * i < a[id]) d.push_back(a[id]/i);
			}
		}
		sort(d.begin(), d.end());
		ll sz = d.size();
		rep(i, 0, sz-1) buc[i] = 0;
		rep(i, 1, n) ++buc[lower_bound(d.begin(), d.end(), __gcd(a[id], a[i])) - d.begin()];
		rep(i, 0, sz-1) rep(j, i+1, sz-1) if(!(d[j] % d[i])) buc[i] += buc[j];
		rep(i, 0, sz-1) if(buc[i] >= nd) chkmax(ans, d[i]);
	}
	printf("%lld\n", ans);
	return 0;
}