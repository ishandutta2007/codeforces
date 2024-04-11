#include <bits/stdc++.h>
 
using namespace std;
 
typedef int64_t		ll;
const int N = int(1e6) + 10;
int pos1[N], pos2[N];
ll ans[N];
 
ll gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
 
// Return (X, Y) where Y = lcm(n, m) and X = a mod n and X = b mod m and 0 <= X < Y
// X = -1 if there is not solution
pair<ll, ll> crt(ll a, ll n, ll b, ll m){
	if(a < 0) a += n;
	if(a >= n) a %= n;
	if(b < 0) b += m;
	if(b >= m) b %= m;
 
	ll x1, x2;
	ll d = gcd(n, m, x1, x2);
	ll lcm = n * m / d;
	if((a - b) % d != 0) 
		return {-1, lcm};
 
	ll x = (a + (n*x1) * (__int128)((b - a)/d)) % lcm;
	if(x < 0) x += lcm;
	return {x, lcm};
}
 
ll mylcm(ll n, ll m){
	return n * (m / __gcd(n, m));
}
 
ll get(ll mid, ll l){
	ll r = mid;
 
	for(int i = 1 ; i < N ; i++){
		if(ans[i] != -1 && ans[i] <= mid){
			r -= ((mid - ans[i] + l - 1) / l);
		}
	}
 
	return r;
}
 
int main(){	
	memset(pos1, -1, sizeof pos1);
	memset(pos2, -1, sizeof pos2);
	memset(ans, -1, sizeof ans);
	
	int n, m;
	ll k;
 
	scanf("%d %d %lld", &n, &m, &k);
	
	ll l = mylcm(n, m);
 
	for(int i = 0 ; i < n ; i++){
		int ai;
 
		scanf("%d", &ai);
 
		pos1[ai] = i;
	}
 
	for(int i = 0 ; i < m ; i++){
		int bi;
	
		scanf("%d", &bi);
 
		pos2[bi] = i;
	}
 
	for(int i = 1 ; i < N ; i++){
		if(pos1[i] != -1 && pos2[i] != -1){
			auto r = crt(pos1[i], n, pos2[i], m);
 
			if(r.first != -1){		
				assert(r.first != -1);
				ans[i] = r.first;
			}
		}
	}
 
	ll lo = 1LL, hi = ll(1e18);
	ll res = -1LL;
 
	while(lo <= hi){
		ll mid = (lo + hi) >> 1LL;
		ll r = get(mid, l);
 
		if(r >= k){
			res = mid;
			hi = mid - 1;
		}else{
			lo = mid + 1;
		}
	}
 
	assert(res != -1LL);
 
	printf("%lld\n", res);
 
	return 0;
}