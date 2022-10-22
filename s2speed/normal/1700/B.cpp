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

string s , t;

void solve(){
	t.clear();
	ll n;
	cin>>n>>s;
	if(s[0] != '9'){
		for(ll i = 0 ; i < n ; i++){
			cout<<(char)('9' - s[i] + '0');
		}
		cout<<'\n';
		return;
	}
	ll pr = 0;
	for(ll i = n - 1 ; ~i ; i--){
		ll h = (s[i] - '0') + pr;
		if(h > 1){
			ll c = 11 - h;
			t += (c + '0');
			pr = 1;
		} else {
			ll c = 1 - h;
			t += (c + '0');
			pr = 0;
		}
	}
	reverse(all(t));
	cout<<t<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}