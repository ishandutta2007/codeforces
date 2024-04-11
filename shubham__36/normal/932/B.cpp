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

const ll sz = 2e6;
ll f[sz];
ll g[sz];
ll dp[sz][10];

void solve(){
	ll l,r,k;
	cin >> l >> r >> k;
	cout << dp[r][k]-dp[l-1][k] << ln;
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin >> t;
    forn(i,sz){
    	if(i!=0){
    		ll ans = 1;
    		ll t1 = i;
    		while(t1!=0){
    			ll t2 = t1%10;
    			if(t2!=0) ans*=t2;
    			t1/=10;
    		}
    		f[i]=ans;
    	}
    }
    forn(i,sz){
    	if(i!=0){
    		if(i<10){
    			g[i]=i;
    		}
    		else{
    			g[i]=g[f[i]];
    		}
    	}
    }
    forn(i,sz){
    	if(i==0) {
    		forn(p,10) dp[i][p]=0;
    		continue;
    	}
    	forn(p,10){
    		if(g[i]==p){
    			dp[i][p]=dp[i-1][p]+1;
    		}
    		else{
    			dp[i][p]=dp[i-1][p];
    		}
    	}
    }
    // forn(i,40){
    // 	cout << f[i] << " ";
    // }
    // cout << ln;
    // forn(i,40){
    // 	cout << g[i] << " ";
    // }
    // cout << ln;
    // forn(i,40){
    // 	forn(p,10) cout << dp[i][p] << " ";
    // 	cout << ln;
    // }
    forn(i,t) solve();
    return 0;
}