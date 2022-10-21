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
//typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll tav(ll n , ll k){
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

ll a[maxn] , b[maxn] , c[maxn] , da[maxn] , db[maxn] , ant[maxn] , bnt[maxn];

/*
1
4
2 4
3 4
2 1
1 3
*/

void solve(){
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ant[i] = bnt[i] = da[i] = db[i] = 0;
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]; a[i]--;
		ant[a[i]]++;
		cin>>b[i]; b[i]--;
		bnt[b[i]]++;
	}
	ll sum = 0;
	for(ll i = 0 ; i < n ; i++){
		ll h = n + 1 - ant[a[i]] - bnt[b[i]];
		sum += h;
		da[a[i]] += h;
		db[b[i]] += h;
		c[i] = h;
	}
	sum /= 2;
	ll ans = 0;
	for(ll i = 0 ; i < n ; i++){
		ll h = sum - da[a[i]] - db[b[i]] + 1ll * (ant[a[i]] - 1) * (bnt[b[i]] - 1) + c[i];
		ans += h;
	}
	ans /= 3;
	ans = -ans;
	ll o = 1ll * n * (n - 1) * (n - 2) / 6;
	for(ll i = 0 ; i < n ; i++){
		ll h = 1ll * ant[i] * (ant[i] - 1) * (ant[i] - 2) / 6;
		h += 1ll * ant[i] * (ant[i] - 1) / 2 * (n - ant[i]);
		o -= h;
	}
	ans += o;
	o = 1ll * n * (n - 1) * (n - 2) / 6;
	for(ll i = 0 ; i < n ; i++){
		ll h = 1ll * bnt[i] * (bnt[i] - 1) * (bnt[i] - 2) / 6;
		h += 1ll * bnt[i] * (bnt[i] - 1) / 2 * (n - bnt[i]);
		o -= h;
	}
	ans += o;
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}