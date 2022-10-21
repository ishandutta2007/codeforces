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

ll sq(ll h){
	ll l = 1 , r = 1e9 + 1;
	while(l < r - 1){
		ll m = (l + r) >> 1;
		if(m * m <= h){
			l = m;
		} else {
			r = m;
		}
	}
	return l;
}

ll ps(ll x){
	if(x == 0) return 0;
	ll h = sq(x) , res = 3 * h - 2;
	if(h * h + h <= x) res++;
	if(h * (h + 2) <= x) res++;
	return res;
}

void solve(){
	ll l , r;
	cin>>l>>r;
	cout<<ps(r) - ps(l - 1)<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}