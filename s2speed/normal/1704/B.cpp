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
	ll n , x , res = 0 , l = -inf , r = inf;
	cin>>n>>x;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h; h--;
		if(h - x > r || h + x < l){
			res++;
			r = h + x;
			l = h - x;
			continue;
		}
		l = max(l , h - x); r = min(r , h + x);
	}
	cout<<res<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}