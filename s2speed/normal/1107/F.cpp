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

const ll maxn = 5e2 + 17 , md = 1e9 + 7 , inf = 2e16;

ll dp[maxn];
ll a[maxn] , b[maxn] , k[maxn];
vector<pll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i]>>b[i]>>k[i]; a[i] += b[i]; k[i]++;
		v.push_back({b[i] , i});
	}
	sort(all(v) , greater<pll>());
	for(ll e = 0 ; e < n ; e++){
		ll i = v[e].second;
		ll h = max(0ll , a[i] - b[i] * k[i]);
		for(ll j = e + 1 ; j ; j--){
			dp[j] = max(dp[j - 1] + a[i] - b[i] * j , dp[j] + h);
		}
		dp[0] += h;
	}
	ll ans = 0;
	for(ll j = 0 ; j <= n ; j++){
		ans = max(ans , dp[j]);
	}
	cout<<ans<<'\n';
	return 0;
}