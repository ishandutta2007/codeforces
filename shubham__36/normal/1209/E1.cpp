#pragma GCC optimize ("-O3")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
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
#include <fstream>
 
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
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 1e18
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

void solve(){
	ll n,m;
	cin >> n >> m;
	ll a[n][m];
	forn(i,n){
		forn(j,m){
			cin >> a[i][j];
		}
	}
	v64 dp[1<<n][2];
	ll dp1[1<<n][2];
	forn(i,1<<n){
			dp[i][0]=v64(n,0);
			dp1[i][0]=0;
	}
	forn(j,m){
		forn(i,1<<n){
				dp[i][1]=v64(n,0);
				dp1[i][1]=0;
		}
		forn(i,n){
			// cout << i << ln;
			forn(j1,1<<n){
				v64 nv(n);
				forn(i1,n){
					nv[i1]=max(dp[j1][0][i1],a[(i+i1)%n][j]);
					// cout << nv[i1] << " ";
				}
				// cout << ln;
				forn(k,1<<n){
					ll sum1 = 0;
					forn(k1,n){
						if((1<<k1)&k){
							sum1 += nv[k1];
						}
					}
					if(dp1[k][1] < sum1){
						dp1[k][1] = sum1;
						dp[k][1] = nv;
						// cout << j << " " << i << " " << sum1 << ln;
					}
				}
			}
		}
		forn(i,1<<n){
				dp[i][0]=dp[i][1];
				dp1[i][0]=dp1[i][1];
		}
	}
	cout << dp1[(1<<n)-1][0] << ln;
}
 
int main()
{
	fast_cin();
    ll t=1;
	cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}