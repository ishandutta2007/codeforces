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

const ll maxn = 3e3 + 17 , md = 1e9 + 7 , inf = 2e16;

string s , t;
bitset<maxn> a;

void solve(){
	ll n , x , y;
	cin>>n>>x>>y>>s>>t;
	ll cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		a[i] = (s[i] != t[i]);
		cnt += a[i];
	}
	if(cnt & 1){
		cout<<"-1\n";
		return;
	}
	if(cnt != 2){
		cout<<(cnt >> 1) * y<<'\n';
		return;
	}
	bool f = false;
	for(ll i = 1 ; i < n ; i++){
		f |= (a[i] & a[i - 1]);
	}
	if(!f){
		cout<<y<<'\n';
	} else {
		cout<<min((y << 1) , x)<<'\n';
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