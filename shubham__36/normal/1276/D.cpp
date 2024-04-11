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
ll MOD = 998244353;
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
    if(b >= (MOD-1)) b %= (MOD-1);
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
    ll t1 = mpow(a,b/2,p);
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

ll n;
vv64 gr,dp;

void dfs(ll v, ll p){
	bool bo = 0;
	forn(i,sz(gr[v])){
		if(gr[v][i]==p){
			bo=1;
		}
		else{
			dfs(gr[v][i],v);
			v64 temp = dp[v];
			temp[0] = dp[v][0]*(dp[gr[v][i]][1]+dp[gr[v][i]][3]);
			if(!bo) {
				temp[1] = dp[v][1]*(dp[gr[v][i]][0]+dp[gr[v][i]][1]+dp[gr[v][i]][2]) + dp[v][0]*(dp[gr[v][i]][0]+dp[gr[v][i]][2]);
			}
			else{
				temp[1] = dp[v][1]*(dp[gr[v][i]][0]+dp[gr[v][i]][1]+dp[gr[v][i]][2]);
			}
			if(bo){
				temp[2] = dp[v][2]*(dp[gr[v][i]][0]+dp[gr[v][i]][1]+dp[gr[v][i]][2]) + dp[v][0]*(dp[gr[v][i]][0]+dp[gr[v][i]][2]);
			}
			if(!bo){
				temp[3] = dp[v][3]*(dp[gr[v][i]][1] + dp[gr[v][i]][3]);
			}
			else{
				temp[3] = dp[v][3]*(dp[gr[v][i]][0] + dp[gr[v][i]][1] + dp[gr[v][i]][2]);
			}
			dp[v] = temp;
			dp[v][0] %= MOD;
			dp[v][1] %= MOD;
			dp[v][2] %= MOD;
			dp[v][3] %= MOD;
		}
	}
}

void solve(){
	cin >> n;
	gr.resize(n);
	dp.resize(n,v64(4,0));
	forn(i,n) dp[i][0]=dp[i][3]=1;
	forn(i,n-1){
		ll t1,t2;
		cin >> t1 >> t2;
		t1--,t2--;
		gr[t1].pb(t2);
		gr[t2].pb(t1);
	}
	dfs(0,-1);
	ll ans = 0;
	// forn(i,n){
	// 	forn(j,4){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << ln;
	// }
	forn(i,2) ans += dp[0][i];
	cout << ans%MOD << ln;
}
 
int main()
{
    fast_cin();
    ll t=1;
    // cin>>t;
    forn(i,t) {
        // cout << "Case #" << i+1 << ": " << ln;
        solve();
    }
    return 0;
}