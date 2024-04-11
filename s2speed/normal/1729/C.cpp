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

string s;
vector<pair<char , ll>> v;

void solve(){
	v.clear();
	ll n;
	cin>>s; n = sze(s);
	bool f = (s[0] > s.back());
	if(f) reverse(all(s));
	for(ll i = 0 ; i < n ; i++){
		if(s[i] >= s[0] && s[i] <= s.back()){
			v.push_back({s[i] , i});
		}
	}
	cout<<s.back() - s[0]<<' '<<sze(v)<<'\n';
	sort(all(v));
	if(!f){
		for(auto p : v){
			cout<<p.second + 1<<' ';
		}
	} else {
		reverse(all(v));
		for(auto p : v){
			cout<<n - p.second<<' ';
		}
	}
	cout<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}