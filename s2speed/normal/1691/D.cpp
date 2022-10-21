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

ll n;
ll a[maxn] , ps[maxn];
vector<pll> v;

bool check(){
	ps[0] = a[0];
	ll mx = max(0ll , a[0]);
	v.clear();
	v.push_back({inf , 0});
	v.push_back({a[0] , ps[0]});
	for(ll i = 1 ; i < n ; i++){
		ll f = inf;
		while(v.back().first <= a[i]){
			f = min(f , v.back().second);
			v.pop_back();
		}
		v.back().second = min(v.back().second , f);
		if(v.back().second < ps[i - 1]) return false;
		ps[i] = ps[i - 1] + a[i];
		v.push_back({a[i] , ps[i]});
	}
	return true;
}

void solve(){
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	if(!check()){
		cout<<"NO\n";
		return;
	}
	reverse(a , a + n);
	if(!check()){
		cout<<"NO\n";
	} else {
		cout<<"YES\n";
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