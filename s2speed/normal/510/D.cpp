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

const ll maxn = 1e6 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll n;
ll dp[maxn] , pd[maxn] , a[maxn] , b[maxn];
vector<ll> v;
map<ll , ll> t;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 63 , sizeof(dp));
	cin>>n;
	ll cur = 0;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
		ll sq = sqrt(a[i]);
		for(ll j = 1 ; j <= sq ; j++){
			if(a[i] % j == 0){
				if(!t.count(j)){
					t[j] = cur++;
					v.push_back(j);
				}
				ll r = a[i] / j;
				if(!t.count(r)){
					t[r] = cur++;
					v.push_back(r);
				}
			}
		}
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>b[i];
	}
	ll vs = sze(v);
	dp[t[a[0]]] = b[0];
	for(ll i = 1 ; i < n ; i++){
		memcpy(pd , dp , sizeof(pd));
		ll x = t[a[i]];
		dp[x] = min(dp[x] , b[i]);
		for(ll j = 0 ; j < vs ; j++){
			ll y = v[j] , k = gcd(y , a[i]) , z = t[k];
			dp[z] = min(dp[z] , pd[j] + b[i]);
		}
	}
	cout<<(dp[0] < 1e13 ? dp[0] : -1)<<'\n';
	return 0;
}