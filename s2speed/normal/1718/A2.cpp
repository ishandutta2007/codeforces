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

ll a[maxn] , dp[maxn] , ps[maxn];
map<ll , ll> ls;

void solve(){
	ls.clear();
	ll n;
	cin>>n;
	for(ll i = 1 ; i <= n ; i++){
		cin>>a[i];
	}
	ps[0] = ls[0] = dp[0] = 0;
	for(ll i = 1 ; i <= n ; i++){
		ps[i] = ps[i - 1] ^ a[i];
		dp[i] = dp[i - 1];
		if(!ls.count(ps[i])){
			ls[ps[i]] = i;
			continue;
		}
		dp[i] = max(dp[i - 1] , dp[ls[ps[i]]] + 1);
		ls[ps[i]] = i;
	}
	cout<<n - dp[n]<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}