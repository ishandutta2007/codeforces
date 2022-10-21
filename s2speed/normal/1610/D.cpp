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

ll a[maxn];
vector<ll> v , u;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		if(a[i] & 1) continue;
		u.push_back(a[i]);
	}
	ll h = 0;
	while(!u.empty()){
		v = u; u.clear();
		ll vs = sze(v);
		ll cnt = 0;
		for(auto i : v){
			cnt += (bool)(i & 2);
		}
		if(cnt){
			ll o = tav(2 , vs - 1);
			h += o;
		}
		for(auto i : v){
			if(i & 2) continue;
			u.push_back(i >> 1);
		}
	}
	ll ans = tav(2 , n) - 1;
	h %= md;
	ans -= h;
	ans %= md; if(ans < 0) ans += md;
	cout<<ans<<'\n';
	return 0;
}