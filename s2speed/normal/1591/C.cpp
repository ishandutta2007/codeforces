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

vector<ll> v;

void solve(){
	v.clear();
	ll n , k;
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		v.push_back(h);
	}
	sort(all(v));
	ll res = -max(abs(v[0]) , abs(v[n - 1]));
	for(ll i = 0 ; i < n ; i += k){
		if(v[i] >= 0) break;
		res += 2 * abs(v[i]);
	}
	for(ll i = n - 1 ; i >= 0 ; i -= k){
		if(v[i] <= 0) break;
		res += 2 * v[i];
	}
	cout<<res<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}