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
	ll n , m;
	cin>>n>>m>>s>>t;
	bool f = true;
	ll k = n - m + 1;
	for(ll i = n - m + 1 ; i < n ; i++){
		f &= (s[i] == t[i - k + 1]);
	}
	if(!f){
		cout<<"NO\n";
		return;
	}
	bool c = false;
	for(ll i = 0 ; i < k ; i++){
		c |= (s[i] == t[0]);
	}
	cout<<(c ? "YES\n" : "NO\n");
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}