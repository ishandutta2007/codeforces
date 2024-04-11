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

vector<ll> v[maxn];
ll w[maxn];

void solve(){
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		v[i].resize(m);
		ll h = 0;
		for(ll j = 0 ; j < m ; j++){
			cin>>v[i][j];
			h += v[i][j] * j;
		}
		w[i] = h;
	}
	ll c = w[0];
	if(w[0] > w[1]){
		cout<<"1 "<<w[0] - w[1]<<'\n';
		return;
	}
	if(w[1] > w[0]){
		cout<<"2 "<<w[1] - w[0]<<'\n';
		return;
	}
	for(ll i = 2 ; i < n ; i++){
		if(w[i] != c){
			cout<<i + 1<<' '<<w[i] - c<<'\n';
			return;
		}
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