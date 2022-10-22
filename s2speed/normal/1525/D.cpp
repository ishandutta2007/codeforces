#include<bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (int)x.size()
#define mp make_pair
#define wall cout<<"--------------------------------------\n"
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2.5e3 + 16 , md = 1e9 + 7 , inf = 2e17;

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

bitset<maxn> a;
ll dp[maxn] , pd[maxn];
vector<ll> v;

void solve(){
	ll n , cnt;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		bool h;
		cin>>h; a[i] = h;
		if(a[i]) v.push_back(i);
	}
	cnt = sze(v);
	memset(pd , 63 , sizeof(pd));
	pd[0] = dp[0] = 0;
	for(ll i = 0 ; i < n ; i++){
		if(a[i]) continue;
		for(ll j = 1 ; j <= cnt ; j++){
			dp[j] = min(pd[j] , pd[j - 1] + abs(v[j - 1] - i));
		}
		memcpy(pd , dp , sizeof(pd));
	}
	cout<<dp[cnt]<<'\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
//	ll T;
//	cin>>T;
//	while(T--){
		solve();
//	}
	return 0;
}