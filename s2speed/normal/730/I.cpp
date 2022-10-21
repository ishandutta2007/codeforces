#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
//#define mp(x , y) make_pair(x , y)
#define wall cerr<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e3 + 16 , md = 1e9 + 7 , inf = 2e16;

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

ll dp[maxn][maxn] , a[maxn] , b[maxn];
bitset<maxn> pd[maxn];
vector<pll> v;
vector<ll> ans[2];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , 0 , sizeof(dp));
	ll n , p , s;
	cin>>n>>p>>s;
	for(ll i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>b[i];
		v.push_back({a[i] - b[i] , i});
	}
	sort(all(v));
	dp[0][1] = b[v[0].second]; pd[0][1] = true;
	for(ll i = 1 ; i < n ; i++){
		ll k = v[i].second;
		for(ll j = 1 ; j <= i + 1 ; j++){
			dp[i][j] = max(dp[i - 1][j] , dp[i - 1][j - 1] + (j > s ? a[k] : b[k]));
			pd[i][j] = (dp[i][j] > dp[i - 1][j]);
		}
	}
	ll cur = p + s;
	for(ll i = n - 1 ; i >= 0 ; i--){
		if(pd[i][cur]){
			ans[(cur <= s)].push_back(v[i].second);
			cur--;
		}
	} 
	cout<<dp[n - 1][p + s]<<'\n';
	for(auto i : ans[0]){
		cout<<i + 1<<' ';
	}
	cout<<'\n';
	for(auto i : ans[1]){
		cout<<i + 1<<' ';
	}
	cout<<'\n';
	return 0;
}