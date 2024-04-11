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

ll a[maxn];
vector<pll> ans;

void solve(){
	ans.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ll h = a[0] & 1 , ls = 0;
	for(ll i = n - 1 ; i > 0 ; i--){
		if((a[i] & 1) == h){
			ls = i;
			break;
		}
	}
	for(ll i = 0 ; i < ls ; i++){
		if((a[i] & 1) == h){
			ans.push_back({i , ls});
		}
	}
	for(ll i = 1 ; i < n ; i++){
		if((a[i] & 1) != h){
			ans.push_back({0 , i});
		}
	}
	cout<<n - 1<<'\n';
	for(auto p : ans){
		cout<<p.first + 1<<' '<<p.second + 1<<'\n';
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