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

ll a[maxn] , l[maxn] , r[maxn];

void solve(){
	ll n , q;
	cin>>n>>q;
	fill(l , l + n , inf);
	fill(r , r + n , inf);
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	ll k = 0;
	l[k] = 1;
	if(a[0] != n){
		for(ll i = 1 ; i < n ; i++){
			if(a[i] == n){
				r[k] = i;
				l[i] = i;
				break;
			}
			if(a[i] > a[k]){
				r[k] = i;
				l[i] = i;
				k = i;
			}
		}
	}
	for(ll e = 0 ; e < q ; e++){
		ll i , t;
		cin>>i>>t; i--;
		if(a[i] == n){
			cout<<max(0ll , t - l[i] + 1)<<'\n';
			continue;
		}
		if(t < l[i]){
			cout<<"0\n";
			continue;
		}
		cout<<min(r[i] - l[i] , t - l[i] + 1)<<'\n';
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