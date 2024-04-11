#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e5 + 16 , inf = 2e16;
ll md;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

inline ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

ll f[maxn] , a[maxn] , pf[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(a , 0 , sizeof(a));
	ll n , q;
	cin>>n>>q>>md;
	f[0] = f[1] = 1;
	for(ll i = 2 ; i <= n + 3 ; i++){
		f[i] = f[i - 2] + f[i - 1];
		f[i] %= md;
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		a[i] -= h; a[i] += md * (a[i] < 0);
	}
	n += 2;
	pf[0] = a[0];
	pf[1] = a[1] - a[0];
	for(ll i = 2 ; i < n ; i++){
		pf[i] = a[i] - (a[i - 2] + a[i - 1]);
		pf[i] %= md; pf[i] += (pf[i] < 0) * md;
	}
	ll cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		cnt += (pf[i] % md != 0);
	}
	for(ll e = 0 ; e < q ; e++){
		char c;
		ll l , r;
		cin>>c>>l>>r; l--;
		if(c == 'A'){
			cnt -= (pf[l] % md != 0);
			pf[l]++;
			cnt += (pf[l] % md != 0);
			cnt -= (pf[r] % md != 0);
			pf[r] += md - f[r - l];
			cnt += (pf[r] % md != 0);
			cnt -= (pf[r + 1] % md != 0);
			pf[r + 1] += md - f[r - l - 1];
			cnt += (pf[r + 1] % md != 0);
		} else {
			cnt -= (pf[l] % md != 0);
			pf[l] += md - 1;
			cnt += (pf[l] % md != 0);
			cnt -= (pf[r] % md != 0);
			pf[r] += f[r - l];
			cnt += (pf[r] % md != 0);
			cnt -= (pf[r + 1] % md != 0);
			pf[r + 1] += f[r - l - 1];
			cnt += (pf[r + 1] % md != 0);
		}
		cout<<(cnt ? "NO\n" : "YES\n");
	}
	return 0;
}