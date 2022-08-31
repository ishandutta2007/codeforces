#pragma GCC optimize ("-O3")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
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
#include <fstream>
 
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
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
ll mpow(ll a, ll b){
	if(b >= (MOD-1)) b %= (MOD-1);
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}
 
ll mpow(ll a, ll b, ll p){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2,p);
	t1 *= t1;
	t1 %= p;
	if(b%2) t1 *= a;
	t1 %= p;
	return t1;
}
 
ll modinverse(ll a, ll m){
	ll m0 = m; 
    ll y = 0, x = 1; 
    if (m == 1) return 0; 
    while (a > 1){
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    }
    if (x < 0) x += m0; 
    return x; 
}
 
ll range(ll l, ll r){
	return l + rand()%(r-l+1);
}

vv64 gr;
v64 deg;
vv64 col; 
v64 ord,ans;

void dfs(ll v, ll p){
	ord.pb(v);
	forn(i,sz(gr[v])){
		if(gr[v][i]!=p){
			dfs(gr[v][i],v);
		}
	}
}

void solve(){
	ll n;
	cin >> n;
	gr.resize(n);
	col.resize(n,v64(3));
	deg.resize(n,0);
	ans.resize(n,0);
	forn(i,3){
		forn(j,n){
			cin >> col[j][i];
		}
	}
	forn(i,n-1){
		ll t1,t2;
		cin >> t1 >> t2;
		t1--,t2--;
		deg[t1]++,deg[t2]++;
		gr[t1].pb(t2);
		gr[t2].pb(t1);
	}
	ll root;
	forn(i,n){
		if(deg[i] > 2){
			cout << -1 << ln;
			return;
		}
		if(deg[i]==1) root = i;
	}
	// cout << root << ln;
	dfs(root,-1);
	ll dp[3][3];
	forn(i,3){
		forn(j,3){
			dp[i][j]=0;
			for(ll pos = j; pos<n; pos+=3){
				dp[i][j] += col[ord[pos]][i];
			}
		}
	}
	ll ind[3];
	ll ans1 = INF;
	forsn(i,1,4){
		forn(j,i+1){
			if(j<3 && (i-j)<3 && i!=2*j){
				ll t1 = dp[i-j][0] + dp[j][1] + dp[3-i][2];
				if(t1 < ans1){
					ind[0] = i-j;
					ind[1] = j;
					ind[2] = 3-i;
					ans1 = t1;
				}
			}
		}
	}
	cout << ans1 << ln;
	forn(i,3){
		for(ll j = i; j<n; j+=3){
			ans[ord[j]] = ind[i];
		}
	}
	forn(i,n) cout << ans[i]+1 << " ";
	cout << ln;
}
 
int main()
{
	fast_cin();
    ll t=1;
    // cin>>t;
    forn(i,t) {
    	// cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}