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

ll a[maxn] , w[maxn] , dp[maxn];

void solve(){
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 1 ; i < n - 1 ; i++){
		w[i] = max(0ll , max(a[i - 1] , a[i + 1]) + 1 - a[i]);
	}
	ll res = 0;
	if(n & 1){
		for(ll i = 1 ; i < n ; i += 2){
			res += w[i];
		}
		cout<<res<<'\n';
		return;
	}
	dp[1] = w[1]; dp[2] = w[2];
	for(ll i = 3 ; i < n - 1 ; i++){
		if(i & 1){
			dp[i] = dp[i - 2] + w[i];
		} else {
			dp[i] = min(dp[i - 2] , dp[i - 3]) + w[i];
		}
	}
	cout<<min(dp[n - 2] , dp[n - 3])<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}