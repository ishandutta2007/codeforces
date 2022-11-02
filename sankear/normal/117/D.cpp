#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

int mod;

inline void norm(int &a){
	while(a >= mod){
		a -= mod;
	}
}

int calc(ll cl, ll cr, ll start, ll step, ll l, ll r, ll u, ll v){
	if(cl > cr || cl > r || cr < l){
 		return 0;
	}
	ll sz = cr - cl + 1;
	if(cl >= l && cr <= r){
		ll k1 = (start >= u ? 0 : ((u - start + step - 1) / step));
		ll k2 = (start > v ? -1 : (min((v - start) / step, sz - 1)));
		if(k1 > k2){
			return 0;
		}
		sz = k2 - k1 + 1;
		start += k1 * step;
		if(sz % 2 == 0){
			int res = ((start % mod) * (sz % mod)) % mod;
			res += ((((step % mod) * ((sz / 2) % mod)) % mod) * ((sz - 1) % mod)) % mod;
			norm(res);
			return res;
		}
		int res = ((start % mod) * (sz % mod)) % mod;
		res += ((((step % mod) * (sz % mod)) % mod) * (((sz - 1) / 2) % mod)) % mod;
		norm(res);
		return res;
	}
	ll mid = cl + ((sz + 1) / 2) - 1;
	int res = calc(cl, mid, start, 2 * step, l, r, u, v) + calc(mid + 1, cr, start + step, 2 * step, l, r, u, v);
	norm(res);
	return res;
}

int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  ll n;
	int m;
	scanf("%I64d %d %d", &n, &m, &mod);
	for(int i = 0; i < m; i++){
		ll l, r, u, v;
		scanf("%I64d %I64d %I64d %I64d", &l, &r, &u, &v);
		printf("%d\n", calc(1, n, 1, 1, l, r, u, v));
	}
  return 0;
}