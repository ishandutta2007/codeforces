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

const ll maxn = 1e3 + 17 , md = 1e9 + 7 , inf = 2e16;

char a[maxn][maxn];
ll dp[maxn][maxn][2][2];

void solve(){
	ll n , m;
	cin>>n>>m;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			cin>>a[i][j];
			dp[i][j][0][0] = dp[i][j][1][0] = dp[i][j][0][1] = dp[i][j][1][1] = -inf;
		}
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			if(i){
				dp[i][j][0][0] = max(dp[i][j][0][0] , dp[i - 1][j][0][0] + 1);
			}
			if(j){
				dp[i][j][0][0] = max(dp[i][j][0][0] , dp[i][j - 1][0][0] + 1);
			}
			if(a[i][j] == 'B'){
				dp[i][j][0][0] = max(dp[i][j][0][0] , 0ll);
			}
		}
	}
	for(ll i = n - 1 ; ~i ; i--){
		for(ll j = 0 ; j < m ; j++){
			if(i != n - 1){
				dp[i][j][1][0] = max(dp[i][j][1][0] , dp[i + 1][j][1][0] + 1);
			}
			if(j){
				dp[i][j][1][0] = max(dp[i][j][1][0] , dp[i][j - 1][1][0] + 1);
			}
			if(a[i][j] == 'B'){
				dp[i][j][1][0] = max(dp[i][j][1][0] , 0ll);
			}
		}
	}
	for(ll i = n - 1 ; ~i ; i--){
		for(ll j = m - 1 ; ~j ; j--){
			if(i != n - 1){
				dp[i][j][1][1] = max(dp[i][j][1][1] , dp[i + 1][j][1][1] + 1);
			}
			if(j != m - 1){
				dp[i][j][1][1] = max(dp[i][j][1][1] , dp[i][j + 1][1][1] + 1);
			}
			if(a[i][j] == 'B'){
				dp[i][j][1][1] = max(dp[i][j][1][1] , 0ll);
			}
		}
	}
	for(ll i = 0 ; i < n ; i++){
		for(ll j = m - 1 ; ~j ; j--){
			if(i){
				dp[i][j][0][1] = max(dp[i][j][0][1] , dp[i - 1][j][0][1] + 1);
			}
			if(j != m - 1){
				dp[i][j][0][1] = max(dp[i][j][0][1] , dp[i][j + 1][0][1] + 1);
			}
			if(a[i][j] == 'B'){
				dp[i][j][0][1] = max(dp[i][j][0][1] , 0ll);
			}
		}
	}
	ll mn = inf , ia , ja;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j < m ; j++){
			ll h = max(max(dp[i][j][0][0] , dp[i][j][0][1]) , max(dp[i][j][1][0] , dp[i][j][1][1]));
//			cout<<h<<' ';
			if(h < mn){
				mn = h;
				ia = i; ja = j;
			}
		}
//		cout<<'\n';
	}
	cout<<ia + 1<<' '<<ja + 1<<'\n';
	return;
}

/*
1
3 2
BW
WW
WB
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll T;
	cin>>T;
	while(T--) solve();
	return 0;
}