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
ll MOD = 1000000007;
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
    ll n,m;
    cin >> n >> m;
    p64 a[m];
    forn(i,m){
    	cin >> a[i].fi >> a[i].se;
    }
    ll a1=a[0].fi,a2=a[0].se;
    ll b1=-1,b2=-1;
    forn(i,m){
    	if(!(a1==a[i].fi || a1==a[i].se || a2==a[i].fi || a2==a[i].se || b1==a[i].fi || b1==a[i].se || b2==a[i].fi || b2==a[i].se)){
    		if(b1==-1) b1 = a[i].fi,b2=a[i].se;
    		else{
    			cout << "NO" << ln;
    			return;
    		}
    	}
    }
    if(b1==-1) {
    	cout << "YES" << ln;
    	return;
    }
    bool bo=false;
    forn(i,m){
    	if(!(a1==a[i].fi || a1==a[i].se || b1==a[i].fi || b1==a[i].se)){
    		bo=true;
    		break;
    	}
    }
    if(!bo) {
    	cout << "YES" << ln;
    	return;
    }
    bo=false;
    forn(i,m){
    	if(!(a1==a[i].fi || a1==a[i].se || b2==a[i].fi || b2==a[i].se)){
    		bo=true;
    		break;
    	}
    }
    if(!bo) {
    	cout << "YES" << ln;
    	return;
    }
    bo=false;
    forn(i,m){
    	if(!(a2==a[i].fi || a2==a[i].se || b1==a[i].fi || b1==a[i].se)){
    		bo=true;
    		break;
    	}
    }
    if(!bo) {
    	cout << "YES" << ln;
    	return;
    }
    bo=false;
    forn(i,m){
    	if(!(a2==a[i].fi || a2==a[i].se || b2==a[i].fi || b2==a[i].se)){
    		bo=true;
    		break;
    	}
    }
    if(!bo) {
    	cout << "YES" << ln;
    	return;
    }
    cout << "NO" << ln;
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