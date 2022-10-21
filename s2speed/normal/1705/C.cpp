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

vector<pll> v;
ll cur;
string s;

void solve(){
	v.clear();
	ll n , c , q;
	cin>>n>>c>>q>>s; cur = n;
	for(ll e = 0 ; e < c ; e++){
		ll l , r;
		cin>>l>>r; l--;
		v.push_back({cur , l});
		cur += r - l;
	}
	for(ll e = 0 ; e < q ; e++){
		ll i;
		cin>>i; i--;
		while(i >= n){
			ll j = lower_bound(all(v) , mp(i , inf)) - v.begin() - 1;
			i = (i - v[j].first) + v[j].second;
		}
		cout<<s[i]<<'\n';
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}