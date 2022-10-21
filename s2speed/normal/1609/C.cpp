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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

bitset<maxn> gh;

void prime(){
	gh.set(); gh[0] = gh[1] = false;
	for(ll i = 2 ; i < maxn ; i++){
		if(!gh[i]) continue;
		for(ll j = 1ll * i * i ; j < maxn ; j += i){
			gh[j] = false;
		}
	}
	return;
}

vector<ll> v;
ll a[maxn] , p[maxn] , q[maxn];

void solve(){
	ll n , e;
	cin>>n>>e;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ll ans = 0;
	for(ll j = 0 ; j < e ; j++){
		v.clear();
		for(ll i = j ; i < n ; i += e){
			v.push_back(a[i]);
		}
		p[0] = 0;
		ll vs = sze(v);
		for(ll i = 1 ; i < vs ; i++){
			p[i] = (v[i - 1] == 1) * (p[i - 1] + 1);
		}
		q[vs - 1] = 0;
		for(ll i = vs - 2 ; i >= 0 ; i--){
			q[i] = (v[i + 1] == 1) * (q[i + 1] + 1);
		}
		for(ll i = 0 ; i < vs ; i++){
			if(gh[v[i]]){
				ans += 1ll * (p[i] + 1) * (q[i] + 1) - 1;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}

/*
1
7 3
10 2 1 3 1 19 3
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	prime();
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}