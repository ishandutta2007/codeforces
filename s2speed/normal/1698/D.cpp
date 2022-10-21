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
	ll n;
	cin>>n;
	ll l = 1 , r = n + 1;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		cout<<"? "<<l<<' '<<m - 1<<endl;
		ll cnt = 0;
		for(ll i = l ; i < m ; i++){
			ll h;
			cin>>h;
			if(h >= l && h < m){
				cnt ^= 1;
			}
		}
		if(cnt){
			r = m;
		} else {
			l = m;
		}
	}
	cout<<"! "<<l<<endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}