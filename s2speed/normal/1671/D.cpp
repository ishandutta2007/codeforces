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

const ll maxn = 2e5 + 17 , md = 1e9 + 7 , inf = 2e16;

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
	ll n , k , sum = 0 , mn = inf , mx = -inf;
	cin>>n>>k;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		v.push_back(h);
		mn = min(mn , h);
		mx = max(mx , h);
	}
	for(ll i = 1 ; i < n ; i++){
		sum += abs(v[i] - v[i - 1]);
	}
	if(mn > 1){
		ll h = min(min(v[0] - 1 , v[n - 1] - 1) , 2 * (mn - 1));
		sum += h;
	}
	if(mx < k){
		ll h = min(min(k - v[0] , k - v[n - 1]) , 2 * (k - mx));
		sum += h;
	}
	cout<<sum<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}