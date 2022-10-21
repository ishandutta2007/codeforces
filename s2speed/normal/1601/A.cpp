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

vector<ll> f[maxn];
ll cnt[30];

void solve(){
	memset(cnt , 0 , sizeof(cnt));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		for(ll j = 0 ; j < 30 ; j++){
			if(h & (1 << j)) cnt[j]++;
		}
	}
	ll k = 0;
	for(ll j = 0 ; j < 30 ; j++){
		k = gcd(k , cnt[j]);
	}
	if(!k){
		for(ll i = 1 ; i <= n ; i++){
			cout<<i<<' ';
		}
		cout<<'\n';
		return;
	}
	for(auto i : f[k]){
		cout<<i<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(f , 0 , sizeof(f));
	for(ll i = 1 ; i < maxn ; i++){
		for(ll j = i ; j < maxn ; j += i){
			f[j].push_back(i);
		}
	}
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}