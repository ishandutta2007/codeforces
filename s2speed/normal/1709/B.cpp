#include<bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

ll a[maxn] , b[maxn] , c[maxn] , pb[maxn] , pc[maxn];

void solve(){
	ll n , q;
	cin>>n>>q;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	pb[0] = pc[0] = 0;
	for(ll i = 1 ; i < n ; i++){
		b[i] = max(0ll , a[i - 1] - a[i]);
		c[i] = max(0ll , a[i] - a[i - 1]);
		pb[i] = pb[i - 1] + b[i];
		pc[i] = pc[i - 1] + c[i];
	}
	for(ll e = 0 ; e < q ; e++){
		ll l , r;
		cin>>l>>r; l--; r--;
		if(l < r){
			cout<<pb[r] - pb[l]<<'\n';
		} else {
			cout<<pc[l] - pc[r]<<'\n';
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	solve();
//	ll T;
//	cin>>T;
//	while(T--) solve();
	return 0;
}