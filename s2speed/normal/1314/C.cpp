#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------"<<endl
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 1e3 + 16 , md = 1e9 + 7 , inf = 2e18;

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

string s;
ll lp[maxn][maxn];

bool cmp(pll a , pll b){
	ll v = a.first , u = b.first;
	ll la = a.second - v , lb = b.second - u;
	if(lp[v][u] >= lb && lp[v][u] >= la) return (la >= lb);
	if(lp[v][u] >= lb) return true;
	if(lp[v][u] >= la) return false;
	return (s[v + lp[v][u]] >= s[u + lp[v][u]]);
}

vector<pll> v;
ll dp[maxn][maxn];
ll n , m , k;

bool check(pll x){
	memset(dp , 0 , sizeof(dp));
	ll l = x.first , r = x.second - l;
	dp[0][0] = 1;
	for(ll i = 0 ; i < n ; i++){
		if(i){
			for(ll j = 1 ; j <= m ; j++){
				dp[i][j] += dp[i - 1][j];
				if(dp[i][j] > inf) dp[i][j] = inf;
			}
		}
		ll h = lp[i][l] , o = n + 1;
		if(h >= r){
			o = i + r;
		} else if(i + h == n){
			o = n + 1;
		} else {
			if(s[l + h] < s[i + h]){
				o = i + h + 1;
			}
		}
		for(ll j = 0 ; j < m ; j++){
			dp[o][j + 1] += dp[i][j];
			if(dp[o][j + 1] > inf) dp[o][j + 1] = inf;
		}
	}
	dp[n][m] += dp[n - 1][m];
	return (dp[n][m] >= k);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(lp , 0 , sizeof(lp));
	cin>>n>>m>>k>>s;
	for(ll i = n - 1 ; i >= 0 ; i--){
		for(ll j = n - 1 ; j >= 0 ; j--){
			if(s[i] == s[j]) lp[i][j] = lp[i + 1][j + 1] + 1;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = i + 1 ; j <= n ; j++){
			v.push_back({i , j});
		}
	}
	sort(all(v) , cmp);
	ll l = -1 , r = n * (n + 1) / 2;
	while(l < r - 1){
		ll m = (r + l) >> 1;
		if(check(v[m])){
			r = m;
		} else {
			l = m;
		}
	}
	l++;
	string ans;
	for(ll i = v[l].first ; i < v[l].second ; i++) ans += s[i];
	cout<<ans<<'\n';
	return 0;
}