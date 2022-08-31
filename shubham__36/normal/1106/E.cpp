#include <bits/stdc++.h>
#include <iomanip> 
#include <set>
#include <queue>
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
#define MAX 300000 

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,k;
    cin >> n >> m >> k;
    vector<vector<p64 > > s(n+5),t(n+5);
    multiset <p64 > mset;
    ll a,b,d,w;
    ll ans[n+5][m+5];
    forn(i,n+5){
    	forn(j,m+5) ans[i][j]=0;
    }
    forn(i,k){
    	cin >> a >> b >> d >> w;
    	s[a].pb(mp(-1*w,-1*d));
    	t[b].pb(mp(-1*w,-1*d));
    }
    rforn(i,n){
    	for(auto el:t[i]) mset.insert(el);
    	p64 pre;
    	if(mset.size()) pre = *(mset.begin()); 
    	forn(j,m+1){
    		if(mset.size()){
    			ans[i][j]=ans[-1*pre.se+1][j]-pre.fi; 
    		} 
    		else ans[i][j]=ans[i+1][j];
    		if(j) ans[i][j]=min(ans[i][j],ans[i+1][j-1]);
    	}
    	for(auto el:s[i]) mset.erase(mset.find(el));
    }
    cout << ans[1][m] << ln;
    return 0;
}