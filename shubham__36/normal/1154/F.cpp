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
ll MOD = 1e9 + 7;
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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,k;
    cin >> n >> m >> k;
    ll a[n];
    forn(i,n) cin >> a[i];
    sort(a,a+n);
    ll s[k][k];
    forn(i,k){
    	ll sum = 0;
    	forn(j,i+1){
    		sum += a[i-j];
    		s[i][j]=sum;
    	}
    }
    // forn(i,k){
    // 	forn(j,k) cout << s[i][j] << " ";
    // 	cout << ln;
    // }
    ll t[m],p[m];
    forn(i,m) cin >> t[i] >> p[i];
    ll dp[k+1];
    dp[0]=0;
    forsn(i,1,k+1){
    	dp[i]=a[i-1]+dp[i-1];
    	forn(j,m){
    		if(t[j]<=i){
    			if(t[j]==p[j]) dp[i]=min(dp[i],dp[i-t[j]]);
    			else dp[i]=min(dp[i],s[i-1][t[j]-p[j]-1]+dp[i-t[j]]);
    		}
    	}
    }
    // forn(i,k+1) cout << dp[i] << " ";
    cout << dp[k] << ln;
    return 0;
}