#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
struct piii {
	int first , second , third;
};

const ll MAX_N = 5e5 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
			res %= md;
		}
		n *= n;
		n %= md;
		k /= 2;
	}
	return res;
}

ll h[MAX_N] , q[MAX_N] , cnt[60] , a[MAX_N];

void solve(){
	ll n , ans = 0 , sum = 0;
	cin>>n;
	for(int j = 0 ; j < 60 ; j++){
		cnt[j] = 0;
	}
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(int i = 0 ; i < n ; i++){
		ll o = 1;
		for(int j = 0 ; j < 60 ; j++){
			if(a[i] & o){
				cnt[j]++;
			}
			o *= 2;
		}
	}
	for(int i = 0 ; i < n ; i++){
		h[i] = 1ll * a[i] % md * (n - 1) % md;
		ll p , u , o = 1;
		for(int j = 0 ; j < 60 ; j++){
			if(a[i] & o){
				o *= 2;
				continue;
			}
			p = cnt[j];
			u = o; u %= md;
			p *= u; p %= md;
			h[i] += p; h[i] %= md;
			o *= 2;
		}
	}
	for(int i = 0 ; i < n ; i++){
		q[i] = 0;
		ll o = 1 , p , u;
		for(int j = 0 ; j < 60 ; j++){
			if(a[i] & o){
				p = cnt[j] - 1;
				u = o; u %= md;
				p *= u; p %= md;
				q[i] += p; q[i] %= md;
			}
			o *= 2;
		}
	}
	for(int i = 0 ; i < n ; i++){
		ll o;
		o = h[i];
		o *= q[i];
		o %= md;
		ans += o;
		o = a[i];
		o %= md;
		o *= q[i];
		o %= md;
		ans += o;
		o = a[i];
		o %= md;
		o *= h[i];
		o %= md;
		ans += o;
		o = 1ll * (a[i] % md) * (a[i] % md) % md;
		ans += o;
		ans %= md;
	}
	cout<<ans<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}