#include <bits/stdc++.h>
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
typedef unordered_map<int,int> m32;
typedef map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
typedef pair<ll,p64 > pp64;
ll MOD = 998244353;
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

ll n;
vv64 dp;
vv64 g;

void dfs(ll v){
	// cout << v << ln;
	if((ll)g[v].size()==0){
		dp[v].pb(0);
		dp[v].pb(0);
		dp[v].pb(1);
	}
	else{
		dfs(g[v][0]);
		ll a0,a1,a2;
		a0 = dp[g[v][0]][0]+dp[g[v][0]][2];
		a0 %= MOD;
		a1 = dp[g[v][0]][1]+dp[g[v][0]][2];
		a1%=MOD;
		a2 = 0;
		forsn(j,1,(ll)g[v].size()){
			dfs(g[v][j]);
			// cout << j << ln;
			ll n1,n2,n0;
			n0 = a0 * ((dp[g[v][j]][0] + dp[g[v][j]][2])%MOD);
			n0 %= MOD;
			n1 = (a1 * ((dp[g[v][j]][0]+dp[g[v][j]][2]) % MOD))%MOD + (a0 * ((dp[g[v][j]][1]+dp[g[v][j]][2]) % MOD))%MOD;
			n1 %= MOD;
			n2 = (a1 * ((dp[g[v][j]][1]+dp[g[v][j]][2]) % MOD))%MOD + (a2 * ((dp[g[v][j]][0]+dp[g[v][j]][1]+2*dp[g[v][j]][2])%MOD))%MOD;
			n2 %= MOD;
			a0 = n0;
			a1 = n1;
			a2 = n2;
		} 
		dp[v].pb(a0);
		dp[v].pb(a1);
		dp[v].pb(a2);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    g.resize(n);
    dp.resize(n);
    forn(i,n-1){
    	ll a;
    	cin >> a;
    	g[a-1].pb(i+1);
    }
    dfs(0);
    // forn(i,n){
    // 	cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << ln;
    // }
    cout << (dp[0][0]+dp[0][2])%MOD << ln;
    return 0;
}