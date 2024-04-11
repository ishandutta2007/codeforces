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

const ll maxn = 1e6 + 17 , md = 2000000357 , mdp = 998244353 , inf = 2e16;

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

bitset<maxn> a;
ll tv[maxn] , hs[maxn] , dp[maxn];

void DFS(ll r , ll k){
	if(k == 1){
		hs[r] = a[r];
		dp[r] = 1;
		return;
	}
	ll ln = (r << 1) + 1 , rn = ln + 1;
	DFS(ln , k >> 1); DFS(rn , k >> 1);
	ll h;
	h = a[r] + (hs[ln] << 1) + tv[(k >> 1) + 1] * hs[rn];
	hs[r] = h % md;
	h = a[r] + (hs[rn] << 1) + tv[(k >> 1) + 1] * hs[ln];
	hs[r] = min(hs[r] , h % md);
	dp[r] = (2 - (hs[ln] == hs[rn])) * dp[ln] * dp[rn] % mdp;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	ll T;
//	cin>>T;
//	while(T--) solve();
	tv[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		tv[i] = tv[i - 1] << 1; tv[i] -= (tv[i] >= md) * md;
	}
	ll n;
	cin>>n;
	ll lm = (1 << n) - 1;
	for(ll i = 0 ; i < lm ; i++){
		char c;
		cin>>c;
		a[i] = (c == 'B');
	}
	DFS(0 , lm);
	cout<<dp[0]<<'\n';
	return 0;
}