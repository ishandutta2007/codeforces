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

const ll maxn = 1e5 + 17 , maxk = 600 + 17 , md = 1e9 + 7 , inf = 2e16;

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

db dp[maxk] , pd[maxk] , p0[maxk] , p1[maxk];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , k;
	cin>>n>>k;
	db kk = db(k - 1) / k , k1 = (db)1 / k;
	p0[1] = 1;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 1 ; j <= 600 ; j++){
			dp[j] += k1 * (db)1 * j / (j + 1) * (pd[j] + p0[j] * (j + 1) / (db)2);
			dp[j] += kk * pd[j];
			dp[j + 1] += k1 * (db)1 / (j + 1) * (pd[j] + p0[j] * j);
			p1[j] += k1 * (db)1 * j / (j + 1) * p0[j];
			p1[j] += kk * p0[j];
			p1[j + 1] += k1 * (db)1 / (j + 1) * p0[j];
		}
		memcpy(pd , dp , sizeof(pd));
		memset(dp , 0 , sizeof(dp));
		memcpy(p0 , p1 , sizeof(p0));
		memset(p1 , 0 , sizeof(p1));
	}
	db ans = 0;
	for(ll j = 1 ; j <= 600 ; j++) ans += pd[j];
	ans *= k;
	cout<<fixed<<setprecision(10)<<ans<<'\n';
	return 0;
}