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

void solve(){
	ll l = 0 , r = 0 , u = 0 , d = 0 , n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll x , y;
		cin>>x>>y;
		if(x == 0){
			if(y >= 0){
				u = max(u , y);
			} else {
				d = max(d , -y);
			}
		} else {
			if(x >= 0){
				r = max(r , x);
			} else {
				l = max(l , -x);
			}
		}
	}
	cout<<2 * (l + r + d + u)<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}