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

vector<ll> v , c[maxn];
ll a[maxn] , p[maxn];

void solve(){
	v.clear();
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		c[i].clear();
		cin>>a[i];
		v.push_back(a[i]);
	}
	sort(all(v));
	v.resize(distance(v.begin() , unique(all(v))));
	for(ll i = 0 ; i < n ; i++){
		a[i] = lower_bound(all(v) , a[i]) - v.begin();
		c[a[i]].push_back(i);
	}
	for(ll i = 0 ; i < n ; i++){
		if(c[i].empty()) continue;
		if(sze(c[i]) == 1){
			cout<<"-1\n";
			return;
		}
		ll cs = sze(c[i]);
		for(ll j = 0 ; j < cs ; j++){
			p[c[i][j]] = c[i][j + 1];
		}
		p[c[i].back()] = c[i][0];
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<p[i] + 1<<' ';
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