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
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e13+7;
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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

ll modinverse(ll a, ll m){
	ll m0 = m; 
    ll y = 0, x = 1; 
    if (m == 1) return 0; 
    while (a > 1){
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    }
    if (x < 0) x += m0; 
    return x; 
}

void solve(){
	ll n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	ll dp[n+1][n][26];
	forn(i,n+1) forn(j,n) forn(k,26) dp[i][j][k]=0;
	forsn(i,1,n+1){
		forn(j,n){
			forn(k,26){
				if(s[i-1]-'a'==k && j!=0){
					forn(t,26){
						dp[i][j][k]+=dp[i-1][j-1][t];
						dp[i][j][k] = min(MOD,dp[i][j][k]);
					}
				}
				else if(s[i-1]-'a'==k) dp[i][j][k]=1;
				else dp[i][j][k]=dp[i-1][j][k];
			}
		}
	}
	// forn(i,n){
	// 	forn(j,26) cout << dp[n][i][j] << " ";
	// 	cout << ln;
	// }
	ll ans = 0;
	rforn(i,n){
		ll tot = 0;
		if(i==0) tot = 1;
		else forn(j,26){
			tot += dp[n][i-1][j];
		}
		ans += (n-i)*min(k,tot);
		k = max((ll)0,k-tot);
	}
	if(k!=0) cout << -1 << ln;
	else cout << ans << ln;
}


int main()
{
	fast_cin();
    ll t=1;
    // cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}