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

string s , t;
vector<pll> v , u;

void solve(){
	v.clear(); u.clear();
	ll n;
	cin>>n>>s>>t;
	if(s[0] != t[0] || s[n - 1] != t[n - 1]){
		cout<<"-1\n";
		return;
	}
	ll cul = -1;
	for(ll i = 0 ; i < n ; i++){
		if(s[i] == '1' && cul == -1){
			cul = i;
			continue;
		}
		if(s[i] == '0' && cul != -1){
			v.push_back({cul , i});
			cul = -1;
		}
	}
	if(cul != -1){
		v.push_back({cul , n});
	}
	cul = -1;
	for(ll i = 0 ; i < n ; i++){
		if(t[i] == '1' && cul == -1){
			cul = i;
			continue;
		}
		if(t[i] == '0' && cul != -1){
			u.push_back({cul , i});
			cul = -1;
		}
	}
	if(cul != -1){
		u.push_back({cul , n});
	}
	if(sze(v) != sze(u)){
		cout<<"-1\n";
		return;
	}
	ll ans = 0 , vs = sze(v);
	for(ll i = 0 ; i < vs ; i++){
		ans += abs(v[i].first - u[i].first) + abs(v[i].second - u[i].second);
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