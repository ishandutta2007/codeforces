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
typedef pair<db , pair<db , db>> pddd;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 2e3 + 16 , md = 1e9 + 7 , inf = 2e17;

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

db v[maxn] , u[maxn] , w[maxn] , dp[maxn][maxn];
ll cnt[maxn][maxn];
ll n , a , b;

bool check(db x){
	memset(cnt , 0 , sizeof(cnt));
	memset(dp , 0 , sizeof(dp));
	if(u[0] - x > 0){
		dp[0][0] = u[0] - x; cnt[0][0] = 1;
	}
	dp[0][1] = v[0];
	if(w[0] - x > v[0]){
		dp[0][1] = w[0] - x; cnt[0][1] = 1;
	}
	for(ll i = 1 ; i < n ; i++){
		dp[i][0] = dp[i - 1][0]; cnt[i][0] = cnt[i - 1][0];
		if(u[i] - x > 0){
			dp[i][0] += u[i] - x; cnt[i][0]++;
		}
		ll lm = min(a , i + 1);
		for(ll j = 1 ; j <= lm ; j++){
			db h , o;
			dp[i][j] = dp[i - 1][j]; cnt[i][j] = cnt[i - 1][j];
			if(dp[i - 1][j - 1] + v[i] == dp[i][j]){
				cnt[i][j] = min(cnt[i - 1][j - 1] , cnt[i][j]);
			}
			if(dp[i - 1][j - 1] + v[i] > dp[i][j]){
				dp[i][j] = dp[i - 1][j - 1] + v[i]; cnt[i][j] = cnt[i - 1][j - 1];
			}
			if(dp[i - 1][j] + u[i] - x == dp[i][j]){
				cnt[i][j] = min(cnt[i - 1][j] + 1 , cnt[i][j]);
			}
			if(dp[i - 1][j] + u[i] - x > dp[i][j]){
				dp[i][j] = dp[i - 1][j] + u[i] - x; cnt[i][j] = cnt[i - 1][j] + 1;
			}
			if(dp[i - 1][j - 1] + w[i] - x == dp[i][j]){
				cnt[i][j] = min(cnt[i - 1][j - 1] + 1 , cnt[i][j]);
			}
			if(dp[i - 1][j - 1] + w[i] - x > dp[i][j]){
				dp[i][j] = dp[i - 1][j - 1] + w[i] - x; cnt[i][j] = cnt[i - 1][j - 1] + 1;
			}
		}
	}
	return (cnt[n - 1][a] >= b);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	cout<<fixed<<setprecision(15);
	cin>>n>>a>>b;
	for(ll i = 0 ; i < n ; i++){
		cin>>v[i];
	}
	for(ll i = 0 ; i < n ; i++){
		cin>>u[i];
		w[i] = 1.0 - (1.0 - v[i]) * (1.0 - u[i]);
	}
	db l = -1 , r = 2 , m;
	for(ll e = 0 ; e < 100 ; e++){
		m = (l + r) / 2;
		if(check(m)){
			if(cnt[n - 1][a] == b) break;
			l = m;
		} else {
			r = m;
		}
	}
	m = (l + r) / 2;
	check(m);
	cout<<dp[n - 1][a] + 1.0 * b * m<<'\n';
	return 0;
}