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

const ll maxn = 5e3 + 17 , md = 1e9 + 7 , inf = 2e16;

string s , t;
bitset<maxn> a;
vector<ll> v;
ll dp[maxn][maxn];

void solve(){
	v.clear();
	ll n , x , y;
	cin>>n>>x>>y>>s>>t;
	for(ll i = 0 ; i < n ; i++){
		a[i] = (s[i] != t[i]);
		if(a[i]) v.push_back(i);
	}
	ll vs = sze(v);
	if(vs & 1){
		cout<<"-1\n";
		return;
	}
	if(vs == 0){
		cout<<"0\n";
		return;
	}
	for(ll i = 0 ; i <= n ; i++){
		for(ll j = 0 ; j <= n ; j++){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = dp[1][0] = 0; dp[1][1] = v[1] - v[0];
	for(ll i = 2 ; i < vs ; i++){
		dp[i][0] = 0;
		ll lm = (i + 1) >> 1;
		for(ll j = 1 ; j <= lm ; j++){
			dp[i][j] = min(dp[i - 1][j] , dp[i - 2][j - 1] + v[i] - v[i - 1]);
		}
	}
	bool f = true;
	for(ll i = 1 ; i < vs ; i++){
		f &= (v[i] == v[i - 1] + 1);
	}
	ll ans = inf , p = (vs >> 1);
	for(ll i = 0 ; i <= p ; i++){
		ll h = dp[vs - 1][i] * x + (p - i) * y + (f && (i == p - 1)) * y;
		ans = min(ans , h);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}