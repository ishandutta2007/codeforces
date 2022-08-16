#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9+7;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF LLONG_MAX

ll dp[2][21][3];
ll n;

// ll mmod(ll &a){
// 	a -= (a/MOD)*MOD;
// 	if(a<0) a+= MOD;
// 	return a;
// }

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

// ll f(ll i, ll j){
// 	if(i<0 || j<0 || i>19 || j>1) return 0;
// 	return n/(((ll)1<<i) * ((j==0) ? 1 : 3));
// }


void solve(){
	cin >> n;
	ll k;
	rforn(i,19){
		if((((ll)1)<<i & n)){
			k=i;
			break;
		}
	}
	ll bo = 0;
	if(3*(1<<(k-1))<=n) bo=1;
	dp[0][k][0]=1;
	if(bo) dp[0][k-1][1]=1;
	forsn(i,1,n){
		forn(j,20){
			forn(k,2){
				ll f1 = n/(((ll)1<<j) * ((k==0) ? 1 : 3));
				ll f2 = n/(((ll)1<<(j+1)) * ((k==0) ? 1 : 3));
				ll f3 = (k+1 == 2) ? 0 : n/(((ll)1<<j) * 3);
				ll t1 = f1-i;
				if(t1>0){
					dp[1][j][k] += dp[0][j][k]*t1;
					dp[1][j][k] %= MOD;
				}
				ll t2 = f1-f2;
				if(t2>0){
					dp[1][j][k] += dp[0][j+1][k]*t2;
					dp[1][j][k] %= MOD;
				}
				ll t3 = f1-f3;
				if(t3>0){
					dp[1][j][k] += dp[0][j][k+1]*t3;
					dp[1][j][k] %= MOD;
				}
				// cout << i << " " << j << " " << k << " " << dp[i][j][k] << ln;
			}
		}
		forn(j,20){
			forn(k,2){
				dp[0][j][k] = dp[1][j][k];
				dp[1][j][k] = 0; 
			}
		}
	}
	// cout << f(0,1) << ln;
	cout << dp[0][0][0] << ln;
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) solve();
    return 0;
}