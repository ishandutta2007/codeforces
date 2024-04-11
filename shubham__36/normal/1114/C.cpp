#include <bits/stdc++.h>
#include <queue>
#include <set>
#include <list>
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
typedef unordered_map<ll,ll> m64;
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
    ll n,b;
    cin >> n >> b;
    vector<p64> fact;
    ll in=0;
    forn(i,INF){
    	if(i==0) continue;
    	if((i+1)*(i+1)>b) break;
    	if(b%(i+1)==0){
    		fact.pb(mp(i+1,1));
    		b/=(i+1);
    		in++;
    	}
    	while(b%(i+1)==0){
    		fact[in-1].se++;
    		b/=(i+1);
    	}
    }
    if(b!=1) fact.pb(mp(b,1));
    ll ans=INF;
    // ll k = sqrt(n);
    // if((k+1)*(k+1) <= n) k++;
    // else if(k*k>n) k--;
    forn(i,fact.size()){
    	ll jh = fact[i].fi;
    	// cout << fact[i].fi << ln;
    	ll tans=n/jh;
    	ll k=n/fact[i].fi;
    	while(jh<=k){
    		jh*=fact[i].fi;
    		// cout << "jh = " << jh << ln;
    		tans+=n/jh;
    	}
    	tans /= fact[i].se;
    	ans = min(ans,tans);
    }
    cout << ans << ln;
    return 0;
}