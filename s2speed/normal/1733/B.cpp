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

void solve(){
	ll n , a , b;
	cin>>n>>a>>b;
	if((a == 0) ^ (b != 0)){
		cout<<"-1\n";
		return;
	}
	if(a == 0) a = b;
	if((n - 1) % a != 0){
		cout<<"-1\n";
		return;
	}
	ll t = 0;
	for(ll i = 0 ; i < n - 1 ; i++){
		if(i % a == 0) t = i + 2;
		cout<<t<<' ';
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