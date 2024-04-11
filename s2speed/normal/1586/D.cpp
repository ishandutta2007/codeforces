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

ll ans[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	ans[n] = n;
	for(ll i = 2 ; i <= n ; i++){
		cout<<"? ";
		for(ll j = 1 ; j < n ; j++){
			cout<<i<<' ';
		}
		cout<<"1"<<endl;
		ll h;
		cin>>h;
		if(h == 0){
			ans[n] = i - 1;
			break;
		}
	}
	for(ll i = ans[n] ; i > 1 ; i--){
		cout<<"? ";
		for(ll j = 1 ; j < n ; j++){
			cout<<i<<' ';
		}
		cout<<"1"<<endl;
		ll h;
		cin>>h;
		ans[h] = ans[n] - i + 1;
	}
	for(ll i = 2 ; ans[n] + i <= n + 1 ; i++){
		cout<<"? ";
		for(ll j = 1 ; j < n ; j++){
			cout<<"1 ";
		}
		cout<<i<<endl;
		ll h;
		cin>>h;
		ans[h] = ans[n] + i - 1;
	}
	cout<<"! ";
	for(ll i = 1 ; i <= n ; i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}