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

void solve(){
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll a[n];
	forn(i,n) cin >> a[i];
	vv64 dp(n,v64(4,0));
	forn(i,n){
		if(i!=0) forn(p,4) dp[i][p]=dp[i-1][p];
		if(s[i]=='h'){
			dp[i][0]=((i!=0) ? dp[i-1][0] : 0) + a[i];
		}
		else if(s[i]=='a'){
			if(i!=0) dp[i][1]=min(dp[i-1][0],dp[i-1][1]+a[i]);
		}
		else if(s[i]=='r'){
			if(i!=0) dp[i][2]=min(dp[i-1][1],dp[i-1][2]+a[i]);
		}
		else if(s[i]=='d'){
			if(i!=0) dp[i][3]=min(dp[i-1][2],dp[i-1][3]+a[i]);
		}
	} 
    cout << dp[n-1][3] << ln;
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