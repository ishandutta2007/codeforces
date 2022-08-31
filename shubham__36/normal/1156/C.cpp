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
ll MOD = 998244353;
ll NUM = 1000000007;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

ll mmod(ll v,ll mod){
	ll temp = v/mod;
	return v-(temp*mod);
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin >> n >> k;
    ll a[n];
    forn(i,n) cin >> a[i];
    sort(a,a+n);
    vector<ll> v1,v2;
    ll ans=0;
    forn(i,n/2){
    	v1.pb(a[i]);
    }
    forsn(i,(n+1)/2,n){
    	v2.pb(a[i]);
    }
    ll in1=0;
    forn(i,n/2){
    	// cout << v2[i]-v1[in1] << ln;
    	if(v2[i]-v1[in1]>=k){
    		ans++;
    		in1++;
    	}
    }
    cout << ans << ln;
    return 0;
}