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


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin >> n >> m;
    ll a[n];
    forn(i,n) cin >> a[i];
    ll ans = -1;
    forn(i,n-1){
    	if(ans == -1) ans = a[i+1]-a[i];
    	else ans = __gcd(ans,a[i+1]-a[i]);
    }
    // cout << ans <<ln;
    ll in = -1;
    forn(i,m){
    	ll b;
    	cin >> b;
    	// cout << b << ln;
    	if(ans % b == 0) {
    		in=i+1;
    		// cout << b << ln;
    	}
    }
    if(n==1) in=1;
    if(in==-1){
    	cout << "NO" << ln;
    	return 0;
    }
    cout << "YES" <<ln;
    cout << a[0] << " " << in << ln;
    return 0;
}