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

ll a[maxn];
set<pll , greater<pll>> s;
vector<ll> v;

void solve(){
	s.clear(); v.clear();
	ll n;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
	}
	for(ll i = 2 ; i <= n ; i++){
		if(a[i] < a[i - 1]){
			s.insert({a[i - 1] - a[i] , i});
		}
	}
	v.assign(n , 1);
	ll t = n - 1;
	while(!s.empty()){
		pll p = *s.begin();
		v[t--] = p.second;
		s.erase(s.begin());
	}
	for(ll i = 0 ; i < n ; i++){
		cout<<v[i]<<' ';
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