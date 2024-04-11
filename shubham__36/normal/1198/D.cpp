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
#define INF 1e11
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

ll mpow(ll a, ll b, ll p){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= p;
	if(b%2) t1 *= a;
	t1 %= p;
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

ll range(ll l, ll r){
	return l + rand()%(r-l+1);
}

vector<vector<char> > vec;
ll ans = 0;
ll n;
// map<p64,ll> rem;
vv64 rem;

p64 nx(ll x, ll y){
	if(y==n-1){
		return mp(x+1,0);
	}
	else{
		return mp(x,y+1);
	}
}

void solve(){
	cin >> n;
	vec.resize(n,vector<char>(n));
	rem.resize(n+1,v64(n+1,1));
	forn(i,n){
		forn(j,n){
			cin >> vec[i][j];
		}
	}
	ll dp[n][n][n][n];
	rforn(x1,n-1){
		rforn(y1,n-1){
			forsn(x2,x1,n){
				forsn(y2,y1,n){
					if(x1==x2 && y1==y2){
						if(vec[x1][y1]=='.') dp[x1][y1][x2][y2]=0;
						else dp[x1][y1][x2][y2]=1;
					}
					else{
						dp[x1][y1][x2][y2] = max(x2-x1+1,y2-y1+1);
						forsn(j,x1,x2){
							dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2],dp[x1][y1][j][y2]+dp[j+1][y1][x2][y2]);
						}
						forsn(j,y1,y2){
							dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2],dp[x1][y1][x2][j]+dp[x1][j+1][x2][y2]);
						}
					}
					// cout << x1 << " " << y1 << ln;
					// cout << x2 << " " << y2 << ln;
					// cout << dp[x1][y1][x2][y2] << ln;
					// cout << ln;
				}
			}
		}
	}
	cout << dp[0][0][n-1][n-1] << ln;
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