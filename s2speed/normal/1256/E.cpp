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

const ll maxn = 2e5 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

ll tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n; res %= md;
		}
		n *= n; n %= md;
		k >>= 1;
	}
	return res;
}

ll a[maxn] , dp[maxn] , par[maxn] , c[maxn];
vector<pll> v;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(par , -1 , sizeof(par));
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		v.push_back({a[i] , i});
	}
	sort(all(v));
	dp[0] = dp[1] = dp[2] = 0;
	for(ll i = 3 ; i < n  ; i++){
		dp[i] = dp[i - 1];
		par[i] = par[i - 1];
		if(v[i].first - v[i - 1].first + dp[i - 3] > dp[i] && i + 3 <= n){
			dp[i] = v[i].first - v[i - 1].first + dp[i - 3];
			par[i] = i;
		}
	}
	ll k = 1 , h = n - 1;
	while(h > -1){
		ll u = par[h];
		while(h > u){
			c[v[h].second] = k;
			h--;
		}
		if(h == -1) break;
		c[v[h].second] = k++;
		c[v[--h].second] = c[v[--h].second] = k;
		h--;
	}
	cout<<v[n - 1].first - v[0].first - dp[n - 1]<<' '<<k<<'\n';
	for(ll i = 0 ; i < n ; i++){
		cout<<c[i]<<' ';
	}
	cout<<'\n';
	return 0;
}