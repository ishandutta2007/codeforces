#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
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

ll a[maxn];

void solve(){
	ll n , cnt = 0;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		a[i] &= 1;
		cnt += a[i];
	}
	ll lm = (n + 1) / 2;
	if(cnt > lm || n - cnt > lm){
		cout<<"-1\n";
		return;
	}
	if(n & 1){
		if(cnt != lm){
			for(ll i = 0 ; i < n ; i++){
				a[i] ^= 1;
			}
		}
		ll x = 0 , ans = 0;
		for(ll i = 0 ; i < n ; i++){
			if(a[i]){
				ans += abs(i - x);
				x += 2;
			}
		}
		cout<<ans<<'\n';
		return;
	}
	ll x = 0 , cur = 0 , ans = 0;
	for(ll i = 0 ; i < n ; i++){
		if(a[i]){
			ans += abs(i - x);
			x += 2;
		}
	}
	x = 0;
	for(ll i = 0 ; i < n ; i++){
		a[i] ^= 1;
		if(a[i]){
			cur += abs(i - x);
			x += 2;
		}
	}
	ans = min(ans , cur);
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}