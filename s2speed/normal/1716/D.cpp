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

const ll maxn = 2e5 + 17 , md = 998244353 , inf = 2e16;

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

int dp[2][maxn];
ll res[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n , k , sum;
	cin>>n>>k; sum = k;
	bool a = false , b = true;
	dp[0][0] = 1;
	for(int i = k ; sum <= n ; i++){
		a ^= 1; b ^= 1;
		fill(dp[a] , dp[a] + sum , 0);
		for(int j = sum ; j <= n ; j++){
			int h = dp[a][j - i] + dp[b][j - i];
			h -= (h >= md) * md;
			dp[a][j] = h;
			res[j] += h;
		}
		sum += i + 1;
	}
	for(int i = 1 ; i <= n ; i++){
		res[i] %= md;
		cout<<res[i]<<' ';
	}
	cout<<'\n';
	return 0;
}