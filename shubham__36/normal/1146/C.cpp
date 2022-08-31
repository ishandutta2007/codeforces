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

ll n;
vv64 v1,v2;

void f(ll t, ll count, ll si){
	// cout << t << " " << count << " " << si << ln;
	if(count < 2) return;
	forsn(i,si,si+count/2){
		v1[t].pb(i+1);
	}
	forsn(i,si+count/2,si+count){
		v2[t].pb(i+1);
	}
	f(t+1,count/2,si);
	f(t+1,(count+1)/2,si+count/2);
}

int main(){
	// ios_base::sync_with_stdio(0);
 //    cin.tie(0);
 //    cout.tie(0);
    ll t;
    cin >> t;
    forn(i,t){
    	cin >> n;
    	v1.resize(10);
    	v2.resize(10);
    	// cout << 4 << endl;
    	f(0,n,0);
    	ll ans = 0;
    	// cout << 34 << endl;
    	forn(k,10){
    		if((ll)v1[k].size()==0 || (ll)v2[k].size()==0) break;
    		cout << (ll)v1[k].size() << " " << (ll)v2[k].size() << " ";
    		forn(j,(ll)v1[k].size()) cout << v1[k][j] << " ";
    		forn(j,(ll)v2[k].size()) cout << v2[k][j] << " ";
    		cout << endl;
    		ll temp;
    		cin >> temp;
    		ans = max(ans,temp);
    	}
    	cout << -1 << " " << ans << endl;
    	v1.clear();
    	v2.clear();
    }
    return 0;
}