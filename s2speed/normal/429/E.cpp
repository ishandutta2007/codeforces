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

ll ans[maxn];
pll l[maxn];
ll r[maxn];
multiset<plll> s;
vector<pll> adj[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , o;
	cin>>n; o = n;
	for(ll i = 0 ; i < n ; i++){
		ll h;
		cin>>h>>r[i];
		l[i] = {h , 0};
		s.insert({l[i] , i});
	}
	while(sze(s) > 1){
		ll i = (*s.begin()).second , j;
		s.erase(s.begin());
		j = (*s.begin()).second;
		if(l[j].first > r[i]){
			continue;
		}
		if(l[j].first == r[i] && l[j].second){
			continue;
		}
		s.erase(s.begin());
		if(r[i] == r[j]){
			ans[i] = true;
			continue;
		}
		l[o] = {min(r[i] , r[j]) , 1};
		r[o] = max(r[i] , r[j]);
		s.insert({l[o] , o});
		adj[o].push_back({i , r[i] != max(r[i] , r[j])}); adj[o].push_back({j , r[j] != max(r[i] , r[j])});
		o++;
	}
	for(ll i = o - 1 ; i >= n ; i--){
		for(auto p : adj[i]){
			ll j = p.first;
			ans[j] = ans[i] ^ p.second;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}