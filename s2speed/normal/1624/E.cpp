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

const ll maxn = 1e3 + 16 , md = 2000000357 , P = 131 , inf = 2e16;

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

pll a[11][11] , b[11][11][11];
string s;
ll dp[maxn];
vector<ll> v;

void solve(){
	v.clear();
	for(ll i = 0 ; i < 10 ; i++){
		for(ll j = 0 ; j < 10 ; j++){
			a[i][j] = {-1 , -1};
			for(ll k = 0 ; k < 10 ; k++){
				b[i][j][k] = {-1 , -1};
			}
		}
	}
	ll n , m;
	cin>>n>>m;
	for(ll j = 0 ; j < m ; j++) dp[j] = -1;
	for(ll i = 0 ; i < n ; i++){
		cin>>s;
		for(ll j = 0 ; j < m - 1 ; j++){
			a[s[j] - '0'][s[j + 1] - '0'] = {j , i};
		}
		for(ll j = 0 ; j < m - 2 ; j++){
			b[s[j] - '0'][s[j + 1] - '0'][s[j + 2] - '0'] = {j , i};
		}
	}
	cin>>s;
	if(a[s[0] - '0'][s[1] - '0'].first != -1){
		dp[1] = 2;
	}
	if(b[s[0] - '0'][s[1] - '0'][s[2] - '0'].first != -1){
		dp[2] = 3;
	}
	for(ll i = 3 ; i < m ; i++){
		if(a[s[i - 1] - '0'][s[i] - '0'].first != -1 && dp[i - 2] != -1){
			dp[i] = 2;
		} else if(b[s[i - 2] - '0'][s[i - 1] - '0'][s[i] - '0'].first != -1 && dp[i - 3] != -1){
			dp[i] = 3;
		}
	}
	if(dp[m - 1] == -1){
		cout<<"-1\n";
		return;
	}
	ll h = m - 1;
	while(h >= 0){
		v.push_back(h);
		h -= dp[h];
	}
	reverse(all(v));
	cout<<sze(v)<<'\n';
	for(auto i : v){
		if(dp[i] == 2){
			ll l = a[s[i - 1] - '0'][s[i] - '0'].first + 1;
			cout<<l<<' '<<l + 1<<' '<<a[s[i - 1] - '0'][s[i] - '0'].second + 1<<'\n';
		} else {
			ll l = b[s[i - 2] - '0'][s[i - 1] - '0'][s[i] - '0'].first + 1;
			cout<<l<<' '<<l + 2<<' '<<b[s[i - 2] - '0'][s[i - 1] - '0'][s[i] - '0'].second + 1<<'\n';
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}