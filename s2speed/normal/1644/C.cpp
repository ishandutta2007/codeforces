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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll a[maxn] , ps[maxn] , c[maxn];

void solve(){
	ll n , x;
	cin>>n>>x;
	ps[0] = 0;
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
		ps[i] = ps[i - 1] + a[i];
		c[i] = -inf;
	}
	for(ll j = 0 ; j <= n ; j++){
		ll mn = inf , res = -inf;
		for(ll i = 0 ; i <= n ; i++){
			if(i >= j) mn = min(mn , ps[i - j]);
			res = max(res , ps[i] - mn);
		}
		res += j * x;
		for(ll i = 0 ; i <= n ; i++){
			res = max(res , c[i]);
		}
		cout<<res<<' ';
		for(ll i = j ; i <= n ; i++){
			c[i] = max(c[i] , ps[i] - ps[i - j] + j * x);
		}
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}