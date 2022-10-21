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

const ll maxn = 5e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll a[maxn] , pf[maxn] , sf[maxn];

void solve(){
	ll n;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
	}
	pf[0] = 0;
	for(ll i = 1 ; i <= n ; i++){
		pf[i] = pf[i - 1] + a[i];
	}
	sf[n + 1] = 0;
	for(ll i = n ; i > 0 ; i--){
		sf[i] = sf[i + 1] + (1 ^ a[i]);
	}
	ll ans = inf;
	for(ll i = 0 ; i <= n ; i++){
		ans = min(ans , max(pf[i] , sf[i + 1]));
	}
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