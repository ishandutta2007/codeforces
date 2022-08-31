#include <bits/stdc++.h>
#include <set>
#include <list>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

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
typedef unordered_map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
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
// string s,p;
// ll t,n,m,ans,a,b1,c,c1;
// vv64 g;
// v32 vis;
// bool b;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin >> n >> k;
    v64 v;
    ll p=-1,t=-1;
    ll b=sqrt(n)+2;
    if(b*b>n) b--;
    if(b*b>n) b--;
    if(b*b>n) b--;
    forn(i,b+1){
    	if(i==0) continue;
    	if(n%i == 0 && n/i < k){
    		p = n/i;
    		t = i;
    		break;
    	}
    	if(n%i==0) v.pb(n/i); 
    }
    if(p==-1){
	    	forn(j,v.size()){
		    	ll i = v[v.size()-1-j];
		    	if(n%i == 0 && n/i < k){
		    		p = n/i;
		    		t = i;
		    		break;
		    	}
	    	}
    }
    ll ans = t*k+p;
    cout << ans;
}