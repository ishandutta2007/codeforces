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

ll a[maxn] , b[maxn];
vector<pll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , ans = 0;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h;
		b[--h] = i;
	}
	for(ll i = 0 ; i < n ; i++){
		a[i] = b[a[i] - 1];
		ans += abs(a[i] - i);
	}
	cout<<ans / 2<<'\n';
	for(ll i = n - 1 ; i >= 0 ; i--){
		ll k = -1;
		for(ll j = 0 ; j < n ; j++){
			if(a[j] == i){
				k = j;
				continue;
			}
			if(k == -1) continue;
			if(a[j] <= k){
				v.push_back({k , j});
				swap(a[k] , a[j]);
				k = j;
			}
		}
	}
	cout<<sze(v)<<'\n';
	for(auto p : v){
		cout<<p.first + 1<<' '<<p.second + 1<<'\n';
	}
	return 0;
}