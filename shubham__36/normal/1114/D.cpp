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

const ll con = 5000;
ll dp[con][con];
vector<ll> a;

ll f(ll l, ll r){
	if(l == r){
		dp[l][r]=0;
	}
	if(l>r || l==r) return 0;
	if(a[l]==a[r]) {
		if(dp[l+1][r-1]==-1) dp[l][r]=1+f(l+1,r-1);
		else dp[l][r]=1+dp[l+1][r-1];
	}
	else {
		if(dp[l+1][r]==-1) f(l+1,r);
		if(dp[l][r-1]==-1) f(l,r-1);
		dp[l][r]=1+min(dp[l+1][r],dp[l][r-1]);
	}
	return dp[l][r];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll k;
    ll fans=0;
    forn(i,n){
    	cin >> k;
    	if(a.size()==0 || a[a.size()-1]!=k) a.pb(k);
    } 
    ll size = a.size();
    forn(i,size) forn(j,size) dp[i][j]=-1;
    f(0,size-1);
    cout << dp[0][size-1];
    return 0;
}