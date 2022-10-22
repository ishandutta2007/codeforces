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

const ll maxn = 5e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll n;
vector<ll> v;

bool check(ll p){
	ll x = n - 1;
	for(ll i = 0 ; i < p ; i++){
		while(v[x] > p - i) x--;
		if(x < i) return false;
		x--;
	}
	return true;
}

void solve(){
	v.clear();
	cin>>n; v.resize(n);
	for(ll i = 0 ; i < n ; i++){
		cin>>v[i];
	}
	sort(all(v));
	if(v[0] > 1){
		cout<<"0\n";
		return;
	}
	ll l = 0 , r = n + 1;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(check(m)){
			l = m;
		} else {
			r = m;
		}
	}
	cout<<l<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}