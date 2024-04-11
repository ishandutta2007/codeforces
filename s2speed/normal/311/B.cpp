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
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e5 + 16 , md = 1e9 + 7 , inf = 2e16;

ll gcd(ll a , ll b){
	if(a < b) swap(a , b);
	if(b == 0) return a;
	return gcd(b , a % b);
}

inline ll tav(ll n , ll k){
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

ll dp[maxn][102] , ps[maxn] , ph[maxn] , f[maxn];
vector<ll> v;
vector<plll> c;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , m , p;
	cin>>n>>m>>p;
	ps[0] = 0;
	for(ll i = 1 ; i < n ; i++){
		ll h;
		cin>>h;
		ps[i] = ps[i - 1] + h;
	}
	v.push_back(-inf);
	for(ll i = 0 ; i < m ; i++){
		ll j , t;
		cin>>j>>t; j--;
		t -= ps[j]; t = -t;
		v.push_back(t);
	}
	sort(all(v)); v.push_back(inf);
	ll cur = 0;
	for(ll i = 1 ; i <= m ; i++){
		cur += v[i];
		dp[i][1] = cur - (1ll * i * v[1]);
		if(i < m) f[i] = 1ll * i * v[i + 1] - cur;
		ph[i] = cur;
	}
	dp[0][1] = 0;
	for(ll k = 2 ; k <= p ; k++){
		c.clear();
		dp[0][k] = 0;
		c.push_back({0 , {-v[1] , 0}});
		for(ll i = 1 ; i <= m ; i++){
			if(v[i] == v[i + 1]) continue;
			ll j = lower_bound(all(c) , mp(i , mp(inf , inf))) - c.begin() - 1;
			dp[i][k] = 1ll * i * c[j].second.first + c[j].second.second + ph[i];
			ll a = -v[i + 1] , b = dp[i][k - 1] + f[i];
			ll t = 0;
			while(!c.empty()){
				ll x = c.back().first , d = c.back().second.first , e = c.back().second.second;
				ll h = 1ll * x * a + b , o = 1ll * x * d + e;
				if(h > o){
					ll q = d - a , w = b - e;
					t = (w + q - 1) / q;
					break;
				}
				c.pop_back();
			}
			if(t <= m) c.push_back({t , {a , b}});
		}
	}
	cout<<dp[m][p]<<'\n';
	return 0;
}