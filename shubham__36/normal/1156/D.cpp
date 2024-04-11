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
ll MOD = 998244353;
ll NUM = 1000000007;
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

ll mmod(ll v,ll mod){
	ll temp = v/mod;
	return v-(temp*mod);
}

vector<vp64> g;
vector<ll> deg,del,a1,a2,a3,a4;
ll ans=0;

void dfs(ll v, ll p){
	if((ll)g[v].size()==1 && p!=0) return;
	forn(i,(ll)g[v].size()){
		if(g[v][i].fi!=p) dfs(g[v][i].fi,v);
	}
	ll c1=0,c2=0;
	forn(i,(ll)g[v].size()){
		if(g[v][i].fi!=p){
			if(g[v][i].se==1){
				c1++;
				// cout << "reached" << ln;
				a1[v]+=1+a1[g[v][i].fi];
				a4[v]+=a4[g[v][i].fi]+a2[g[v][i].fi];
			}
			else{
				c2++;
				a2[v]+=1+a2[g[v][i].fi];
				a3[v]+=a3[g[v][i].fi]+a1[g[v][i].fi];
			}
		}
	}
	ans += 2*(a1[v]+a2[v])+a3[v]+a4[v];
	forn(i,(ll)g[v].size()){
		ll k1 = a1[v],k2 = a2[v],k3 = a3[v],k4 = a4[v];
		if(g[v][i].fi!=p){
			if(g[v][i].se==1){
				k1-=1+a1[g[v][i].fi];
				k4-=a4[g[v][i].fi]+a2[g[v][i].fi];
			}
			else{
				k2-=1+a2[g[v][i].fi];
				k3-=a3[g[v][i].fi]+a1[g[v][i].fi];
			}
		}
		ans += (a1[v]-k1)*(k1+k2+k4);
		ans += (a3[v]-k3)*(k2);
		ans += (a2[v]-k2)*(k2);
		// ans += (a4[v]-k4)*(k1);
		// ll temp = 0;
		// if(p!=0){
		// 	temp = (ll)g[v].size()-1;
		// }
		// else{
		// 	temp = (ll)g[v].size();
		// }
		// ans -= (temp*(temp-1))/2;
		// 
		// if(v==2) cout << g[v][i].fi << " " << ans << ln; 
	}
	// ans -= c1*(c1-1)+c2*(c2-1);
	// cout << v << " " << ans << ln;
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    g.resize(n+5);
    deg.resize(n+5,0);
    del.resize(n+5,0);
    a1.resize(n+5,0);
    a2.resize(n+5,0);
    a3.resize(n+5,0);
    a4.resize(n+5,0);
    forn(i,n-1){
    	ll a,b,e;
    	cin >> a >> b >> e;
    	g[a].pb(mp(b,e));
    	g[b].pb(mp(a,e));
    	deg[a]++;
    	deg[b]++;
    }
    dfs(1,0);
    // cout << "asgfg" << ln;
    forn(i,n+1){
    	if(i==0) continue;
    	// cout << a1[i] << "  " << a2[i] << "  " << a3[i] << "  " << a4[i] << ln;
    }
    cout << ans << ln;
    return 0;
}