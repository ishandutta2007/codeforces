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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , q;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ll mx = 0 , ps = 0;
	for(ll i = 0 ; i < n ; i++){
		ps += a[i];
		ll h = (ps + i) / (i + 1);
		mx = max(mx , h);
	}
	cin>>q;
	for(ll i = 0 ; i < q ; i++){
		ll t;
		cin>>t;
		if(t < mx){
			cout<<"-1\n";
			continue;
		}
		ll h = (ps + t - 1) / t;
		cout<<h<<'\n';
	}
	return 0;
}