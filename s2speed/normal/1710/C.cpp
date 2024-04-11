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

ll f[maxn][8] , dp[maxn][8] , bt[8] , res[8];
string s;
vector<ll> v[8][2];

void add(ll i , bool c){
	memset(res , 0 , sizeof(res));
	for(ll mask = 0 ; mask < 8 ; mask++){
		ll h = dp[i - 1][mask] * (bt[mask] + 1);
		res[mask] += h;
		for(auto j : v[mask][c]){
			res[j] += dp[i - 1][mask];
		}
	}
	for(ll mask = 0 ; mask < 8 ; mask++) res[mask] %= md;
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	bt[0] = 0;
	bt[1] = bt[2] = bt[4] = 1;
	bt[3] = bt[5] = bt[6] = 2;
	bt[7] = 3;
	v[0][1].push_back(1); v[0][1].push_back(4);
	v[1][0].push_back(3);
	v[1][1].push_back(5);
	v[3][0].push_back(7);
	v[3][1].push_back(7);
	v[4][1].push_back(5); v[4][1].push_back(6);
	v[5][0].push_back(7);
	v[5][1].push_back(7);
	v[6][0].push_back(7);
	v[6][1].push_back(7);
	ll n;
	cin>>s; n = sze(s);
	f[0][7] = 1;
	for(ll i = 1 ; i <= n ; i++){
		for(ll mask = 0 ; mask < 8 ; mask++){
			ll h = f[i - 1][mask] * (bt[mask] + 1) * 2;
			f[i][mask] += h;
			for(auto j : v[mask][0]){
				f[i][mask] += f[i - 1][j];
			}
			for(auto j : v[mask][1]){
				f[i][mask] += f[i - 1][j];
			}
			f[i][mask] %= md;
//			cout<<f[i][mask]<<' ';
		}
//		cout<<'\n';
	}
	ll ans = 0;
	dp[0][0] = 1;
	for(ll i = 1 ; i <= n ; i++){
		add(i , 0);
//		for(ll j = 0 ; j < 8 ; j++){
//			cout<<res[j]<<' ';
//		}
//		cout<<'\n';
		if(s[i - 1] == '0'){
			memcpy(dp[i] , res , sizeof(res));
			continue;
		}
		for(ll mask = 0 ; mask < 8 ; mask++){
			ll h = res[mask] * f[n - i][mask] % md;
			ans += h;
		}
		add(i , 1);
		memcpy(dp[i] , res , sizeof(res));
	}
//	for(ll i = 1 ; i <= n ; i++){
//		for(ll j = 0 ; j < 8 ; j++){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	ans += dp[n][7];
	ans *= 6;
	ans %= md;
	cout<<ans<<'\n';
	return 0;
}