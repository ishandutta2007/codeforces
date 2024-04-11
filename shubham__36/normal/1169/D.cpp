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
    string s;
    cin >> s;
    ll a[(ll)s.size()];
    forn(i,(ll)s.size()) a[i]=INF;
    forn(i,(ll)s.size()){
    	forsn(j,1,6){
    		if(i+2*j<(ll)s.size() && s[i]==s[i+j] && s[i]==s[i+2*j]){
    			a[i]=min(a[i],i+2*j);
    		}
    	}
    }
    ll t1 = INF;
    rforn(i,(ll)s.size()-1){
    	t1 = min(t1,a[i]);
    	a[i]=t1;
    }
    ll ans=0;
    forn(i,(ll)s.size()){
    	if(a[i]!=INF) ans += (ll)s.size()-a[i];
    }
    cout << ans << ln;
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