#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

#define all(x) x.begin() , x.end()
//#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 4e3 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

int dp[MAXN][100][100] , a[MAXN] , ps[MAXN] , sp[MAXN];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp , -63 , sizeof(dp));
	ll n , sq;
	cin>>n>>a[0]; ps[0] = a[0];
	sq = ceil(sqrt(2 * n));
	for(int i = 1 ; i < n ; i++){
		cin>>a[i];
		ps[i] = ps[i - 1] + a[i];
	}
	sp[n - 1] = a[n - 1];
	for(int i = n - 2 ; i >= 0 ; i--){
		sp[i] = sp[i + 1] + a[i];
	}
	if(n == 1){
		cout<<a[0]<<'\n';
		return 0;
	}
	if(n == 2){
		cout<<a[0] + abs(a[1])<<'\n';
		return 0;
	}
	if(n == 3){
		int h = a[0] + a[1] , q;
		q = -a[2] - abs(a[1]);
		cout<<max(h , q + a[0])<<'\n';
		return 0;
	}
	for(int i = n / 2 - 1 ; i >= 0 ; i--){
		for(int k = 1 ; k <= sq ; k++){
			for(int j = 0 ; j <= k ; j++){
				int l = i , r = n - l - j - 1 , h1 , h2;
				if(r <= l) break;
				l += k;
				r -= k;
				if(r <= l){
					r += k;
					if(l < r){
						h1 = ps[l] - sp[r];
					} else {
						l -= k;
						dp[i][k][j] = ps[l] - sp[r];
						continue;
					}
				} else {
					h1 = dp[l][k][j];
					r--;
					if(l < r){
						h1 = min(h1 , dp[l][k + 1][j + 1]);
					}
				}
				l = i;
				r = n - l - j - 1;
				l += k + 1;
				r -= k + 1;
				if(r <= l){
					r += k + 1;
					if(l < r){
						h2 = ps[l] - sp[r];
					} else {
						dp[i][k][j] = h1;
						continue;
					}
				} else {
					h2 = dp[l][k + 1][j];
					r--;
					if(l < r){
						h2 = min(h2 , dp[l][k + 2][j + 1]);
					}
				}
				dp[i][k][j] = max(h1 , h2);
			}
		}
	}
	int h1 = min(dp[1][2][0] , (dp[1][3][1] < -1e6 ? 500000000 : dp[1][3][1])) , h2 = min(dp[0][1][0] , dp[0][2][1]);	
	cout<<max(h1 , h2)<<'\n';
	return 0;
}

/*

*/