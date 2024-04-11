#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;

const ll MAXN = 50 + 2 , md = 1e9 + 7 , inf = 1e16;
// check problem statement

ll dp[MAXN][MAXN][MAXN][MAXN];
string s[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(dp , 63 , sizeof(dp));
	ll n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>s[i];
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			for(int q = i ; q >= 0 ; q--){
				for(int e = j ; e >= 0 ; e--){
					if(q == i && e == j){
						dp[i][j][q][e] = (s[i][j] == '#');
						continue;
					}
					if(i - q >= j - e){
						for(int k = i ; k > q ; k--){
							dp[i][j][q][e] = min(dp[i][j][q][e] , dp[i][j][k][e] + dp[k - 1][j][q][e]);
						}
						dp[i][j][q][e] = min(dp[i][j][q][e] , i - q + 1ll);
					} else {
						for(int k = j ; k > e ; k--){
							dp[i][j][q][e] = min(dp[i][j][q][e] , dp[i][j][q][k] + dp[i][k - 1][q][e]);
						}
						dp[i][j][q][e] = min(dp[i][j][q][e] , j - e + 1ll);
					}
				}
			}
		}
	}
	cout<<dp[n - 1][n - 1][0][0]<<'\n';
	return 0;
}

/*

*/