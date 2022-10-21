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

ll pd[maxn];
vector<ll> v;
set<ll> b;
map<ll , ll> a , dp[6];
ll dep = 0;

void cal(ll i , ll j){
	ll ln = 2 * i , rn = ln + 1;
	if(!b.count(ln)){
		dp[0][ln] = dp[1][ln] = dp[2][ln] = dp[3][ln] = dp[4][ln] = dp[5][ln] = pd[dep - 1];
	}
	if(!b.count(rn)){
		dp[0][rn] = dp[1][rn] = dp[2][rn] = dp[3][rn] = dp[4][rn] = dp[5][rn] = pd[dep - 1];
	}
	ll res = 0;
	for(ll q = 0 ; q < 6 ; q++){
		if(q / 2 == j / 2) continue;
		for(ll w = 0 ; w < 6 ; w++){
			if(w / 2 == j / 2) continue;
			ll h = 1ll * dp[q][ln] * dp[w][rn] % md;
			res += h;
		}
	}
	dp[j][i] = res % md;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	pd[0] = 1;
	ll k;
	cin>>k;
	for(ll i = 1 ; i < k ; i++){
		ll h = 1ll * pd[i - 1] * pd[i - 1] % md;
		pd[i] = 16ll * h % md;
	}
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n ; i++){
		ll r;
		string s;
		cin>>r>>s;
		if(s == "white"){
			a[r] = 0;
		}
		if(s == "yellow"){
			a[r] = 1;
		}
		if(s[0] == 'r'){
			a[r] = 2;
		}
		if(s[0] == 'o'){
			a[r] = 3;
		}
		if(s[0] == 'g'){
			a[r] = 4;
		}
		if(s[0] == 'b'){
			a[r] = 5;
		}
		ll h = r;
		while(h){
			v.push_back(h);
			b.insert(h);
			h >>= 1;
		}
	}
	sort(all(v) , greater<ll>());
	v.resize(distance(v.begin() , unique(all(v))));
	for(auto i : v){
		while(i < (1ll << (k - dep - 1))) dep++;
		if(dep == 0){
			dp[a[i]][i] = 1;
			continue;
		}
		ll h = 1;
		if(a.count(i)){
			cal(i , a[i]);
			continue;
		}
		for(ll j = 0 ; j < 6 ; j++) cal(i , j);
	}
	ll ans = 0;
	for(ll j = 0 ; j < 6 ; j++){
		ans += dp[j][1];
	}
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}

/*
2
1
2 b
*/