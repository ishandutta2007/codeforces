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
    ll n;
    cin >> n;
    ll a[n];
    ll b,ans=0;
    ll fans=0;
    set <p64> s1,s2;
    s1.insert(mp(0,1));
    forn(i,n){
    	cin >> b;
    	ans ^= b;
    	if(i%2 == 0){
    		auto it = s2.lower_bound(mp(ans,-1*INF));
	    	if(it!= s2.end() && (*it).fi == ans){
	    		ll temp = (*it).se;
	    		fans += temp;
	    		s2.erase(it);
	    		s2.insert(mp(ans,temp+1));
	    	}
	    	else{
	    		s2.insert(mp(ans,1));
	    	} 
    	}
    	else{
    		auto it = s1.lower_bound(mp(ans,-1*INF));
	    	if(it!= s1.end() && (*it).fi == ans){
	    		ll temp = (*it).se;
	    		fans += temp;
	    		s1.erase(it);
	    		s1.insert(mp(ans,temp+1));
	    	}
	    	else{
	    		s1.insert(mp(ans,1));
	    	} 
    	}
    	
    }
    cout << fans << ln;
    return 0;
}