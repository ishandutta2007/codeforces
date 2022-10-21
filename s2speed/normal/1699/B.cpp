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

bitset<53> a[52];

void solve(){
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(ll i = 0 ; i < 52 ; i++){
		for(ll j = 0 ; j < 52 ; j++){
			ll o = (i % 4 == 1 || i % 4 == 2) , h = (j % 4 == 1 || j % 4 == 2);
			a[i][j] = !(o ^ h);
		}
	}
	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}