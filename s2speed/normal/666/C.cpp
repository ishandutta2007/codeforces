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
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e5 + 16 , md = 1e9 + 7 , inf = 2e17;

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

int dp[maxn][500];
ll tv[maxn] , fact[maxn] , _fact[maxn];
map<int , int> t;

void fact_build(){
	fact[0] = _fact[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		fact[i] = 1ll * fact[i - 1] * i % md; _fact[i] = tav(fact[i] , md - 2);
	}
	return;
}

ll chs(ll n , ll k){
	if(k > n || k < 0) return 0;
	return 1ll * fact[n] * _fact[k] % md * _fact[n - k] % md;
}

void dp_build(ll n , ll j){
	dp[n][j] = 1;
	for(ll i = n + 1 ; i < maxn ; i++){
		ll h = (26ll * dp[i - 1][j] + 1ll * tv[i - n] * chs(i - 1 , n - 1)) % md;
		dp[i][j] = h;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact_build();
	memset(dp , 0 , sizeof(dp));
	tv[0] = 1;
	for(ll i = 1 ; i < maxn ; i++){
		tv[i] = 25ll * tv[i - 1] % md;
	}
	int q , n , k , cur = 0;
	string s;
	cin>>q>>s; n = sze(s); t[n] = cur;
	dp_build(n , cur++);
	for(int i = 0 ; i < q ; i++){
		ll o;
		cin>>o; o--;
		if(o){
			cin>>k;
			cout<<dp[k][t[n]]<<'\n';
			continue;
		}
		cin>>s; n = sze(s);
		if(t.count(n)) continue;
		t[n] = cur;
		dp_build(n , cur++);
	}
	return 0;
}