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

const ll maxn = 2e5 + 17 , md = 998244353 , inf = 2e16;

ll n , n2;
ll a[2][maxn];

bool check(ll x){
	ll cur = 0;
	bool c = false;
	for(ll i = 0 ; i < n ; i++){
		if(a[c][i] + n2 - cur > x){
			return false;
		}
		cur++;
		c ^= 1;
		if(a[c][i] + n2 - cur > x){
			c ^= 1;
			for(ll j = i + 1 ; j < n ; j++){
				if(a[c][j] + n2 - cur > x) return false;
				cur++;
			}
			c ^= 1;
			for(ll j = n - 1 ; j >= i ; j--){
				if(a[c][j] + n2 - cur > x) return false;
				cur++;
			}
			return true;
		}
		if(i < n - 1){
			if(a[c][i + 1] + n2 - cur - 1 > x){
				c ^= 1;
				for(ll j = i + 1 ; j < n ; j++){
					if(a[c][j] + n2 - cur > x) return false;
					cur++;
				}
				c ^= 1;
				for(ll j = n - 1 ; j >= i ; j--){
					if(a[c][j] + n2 - cur > x) return false;
					cur++;
				}
				return true;
			}
		}
		cur++;
	}
	return true;
}

/*
1
5
0 4 8 12 16
2 6 10 14 18
*/

void solve(){
	cin>>n; n2 = n << 1;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[0][i];
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>a[1][i];
	}
	a[0][0] = -1;
//	cout<<check(18)<<'\n';
	ll l = 0 , r = 2e9;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(check(m)){
			r = m;
		} else {
			l = m;
		}
	}
	cout<<r<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}