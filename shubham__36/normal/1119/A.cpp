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
#define INF LLONG_MAX
#define EL printf("\n")
#define OK printf("OK")
#define pb push_back
#define mp make_pair

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    // cin >> t;
    t=1;
    forn(i,t){
    	ll n;
    	cin >> n;
    	ll c[n];
    	ll a,b;
    	forn(i,n) cin >> c[i];
    	ll temp=c[0];
    	forn(i,n){
    		if(temp != c[i]){
    			a = i;
    			break;
    		}
    	}
    	temp = c[n-1];
    	rforn(i,n-1){
    		if(temp != c[i]){
    			b = i;
    			break;
    		}
    	}
    	if(c[0]!=c[n-1]) cout << n-1 << ln;
    	else cout << max(b,n-1-a) << ln;
    }
    return 0;
}