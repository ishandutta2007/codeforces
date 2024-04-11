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

string s;

void solve(){
	ll n , k;
	cin>>n>>k>>s;
	ll lf = -1 , rt = -1 , def = 0 , cnt = 0;
	for(ll i = 0 ; i < n ; i++){
		cnt += (s[i] ^ '0');
	}
	def = cnt * 11;
	for(ll i = 0 ; i < n ; i++){
		if(s[i] == '1'){
			lf = i;
			break;
		}
	}
	if(lf == -1){
		cout<<"0\n";
		return;
	}
	for(ll i = n - 1 ; ~i ; i--){
		if(s[i] == '1'){
			rt = i;
			break;
		}
	}
	if(lf == rt){
		if(k >= n - 1 - rt){
			cout<<def - 10<<'\n';
			return;
		}
		if(k >= lf){
			cout<<def - 1<<'\n';
			return;
		}
		cout<<def<<'\n';
		return;
	}
	if(k >= n - 1 - rt){
		k -= n - 1 - rt;
		if(k >= lf){
			cout<<def - 11<<'\n';
		} else {
			cout<<def - 10<<'\n';
		}
		return;
	}
	cout<<def - (k >= lf)<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}