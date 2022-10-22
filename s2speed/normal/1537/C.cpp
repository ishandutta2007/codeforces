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

vector<ll> v , a;

void solve(){
	v.clear(); a.clear();
	ll n;
	cin>>n; v.resize(n);
	for(ll i = 0 ; i < n ; i++){
		cin>>v[i];
	}
	sort(all(v));
	ll m = inf , ind = -1;
	for(ll i = 1 ; i < n ; i++){
		if(abs(v[i] - v[i - 1]) < m){
			m = abs(v[i] - v[i - 1]);
			ind = i - 1;
		}
	}
	a.push_back(v[ind]);
	for(ll i = (ind + 2) % n ; i != ind ; i++ , i %= n){
		a.push_back(v[i]);
	}
	a.push_back(v[ind + 1]);
	for(auto i : a){
		cout<<i<<' ';
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