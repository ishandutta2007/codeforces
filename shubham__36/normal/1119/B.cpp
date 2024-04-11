#include <bits/stdc++.h>
#include <iomanip>
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
#define INF 1e10
#define EL printf("\n")
#define OK printf("OK")
#define pb push_back
#define mp make_pair

ll f(ll k, ll a[]){
	ll tl=0;
	forn(i,k){
    	if(i%2==0) tl+=a[k-1-i];
    }
    return tl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    // cin >> t;
    t=1;
    forn(i,t){
    	ll n,h;
    	cin >> n >> h;
    	ll a[n];
    	forn(i,n) a[i]=INF;
    	ll s;
    	forn(i,n){
    		cin >> a[i];
    		sort(a,a+i+1);
    		// cout << f(i+1,a) << ln;
    		if(f(i+1,a)>h){
    			cout << i << ln;
    			return 0;
    		}
    	}
    	cout << n << ln;
    }
    return 0;
}