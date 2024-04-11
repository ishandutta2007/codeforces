#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")
 
#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e15;

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

vector<pll> ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll f = 0 , o;
	for(ll i = 1 ;  ; i++){
		f += 1ll * i * i;
		if(f > 1e18){
			o = i;
			break;
		}
	}
	ll x;
	cin>>x;
	for(ll i = 1 ; i < o ; i++){
		ll h = 1ll * i * (i + 1) * ((i << 1) + 1) / 6 , t = 1ll * i * (i + 1) / 2 , y;
		if(h > x) break;
		if(x % t != h % t) continue;
		y = i + (x - h) / t;
		ans.push_back({i , y});
		if(i != y){
			ans.push_back({y , i});
		}
	}
	sort(all(ans));
	ll as = sze(ans);
	cout<<as<<'\n';
	for(ll i = 0 ; i < as ; i++){
		cout<<ans[i].first<<' '<<ans[i].second<<'\n';
	}
	return 0;
}