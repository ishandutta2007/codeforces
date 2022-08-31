#include <bits/stdc++.h>
#include <complex>
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
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9+7;
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
#define INF LLONG_MAX/2e5

ll n,m;
vvp64 gr;
v64 col1,col2,v1,v2;

bool dfs1(ll v, ll c){
	if(col1[v]!=-1 && col1[v]!=c) return false;
	if(col1[v]!=-1) return true;
	col1[v]=c;
	if(c==0) v1.pb(v);
	else v2.pb(v);
	forn(i,(ll)gr[v].size()){
		if(gr[v][i].se==0){
			bool temp = dfs1(gr[v][i].fi,c);
			if(!temp) return temp;
		}
		else{
			bool temp = dfs1(gr[v][i].fi,c^1);
			if(!temp) return temp;
		}
	}
	return true;
}

bool dfs2(ll v, ll c){
	if(col2[v]!=-1 && col2[v]!=c) return false;
	if(col2[v]!=-1) return true;
	col2[v]=c;
	if(c==0) v1.pb(v);
	else v2.pb(v);
	forn(i,(ll)gr[v].size()){
		if(gr[v][i].se==0){
			bool temp = dfs2(gr[v][i].fi,c^1);
			if(!temp) return temp;
		}
		else{
			bool temp = dfs2(gr[v][i].fi,c);
			if(!temp) return temp;
		}
	}
	return true;
}

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll t1 = mpow(a,b/2);
	t1 *= t1;
	t1 %= MOD;
	if(b%2) t1 *= a;
	t1 %= MOD;
	return t1;
}

void solve(){
	cin >> n >> m;
	gr.resize(n+5);
	col1.resize(n+5,-1);
	col2.resize(n+5,-1);
	forn(i,m){
		ll t1,t2;
		char c;
		cin >> t1 >> t2 >> c;
		gr[t1].pb(mp(t2,(c=='B' ? 0 : 1)));
		gr[t2].pb(mp(t1,(c=='B' ? 0 : 1)));
	}
	ll ans = -1;
	vv64 vec(2);
	bool b1=0,b2=0;
	forsn(i,1,n+1){
		if(col1[i]==-1){
			if(!dfs1(i,0)){
				b1 = 1;
				v1.clear();
				v2.clear();
				break;
			}
			else{
				if((ll)v1.size()>(ll)v2.size()){
					swap(v1,v2);
				}
				forn(i,(ll)v1.size()){
					vec[0].pb(v1[i]);
				}
				v1.clear();
				v2.clear();
			}
		} 
	}
	forsn(i,1,n+1){
		if(col2[i]==-1){
			if(!dfs2(i,0)){
				b2 = 1;
				v1.clear();
				v2.clear();
				break;
			}
			else{
				if((ll)v1.size()>(ll)v2.size()){
					swap(v1,v2);
				}
				forn(i,(ll)v1.size()){
					vec[1].pb(v1[i]);
				}
				v1.clear();
				v2.clear();
			}
		} 
	}
	// forn(i,2){
	// 	forn(j,(ll)vec[i].size()){
	// 		cout << vec[i][j] << " ";
	// 	}
	// 	cout << ln;
	// }
	if(!b1){
		if(ans==-1) ans = (ll)vec[0].size();
		else ans = min(ans,(ll)vec[0].size());
	}
	if(!b2){
		if(ans==-1) ans = (ll)vec[1].size();
		else ans = min(ans,(ll)vec[1].size());
	}
	cout << ans << ln;
	forn(i,2){
		if((ll)vec[i].size()==ans){
			forn(j,ans){
				cout << vec[i][j] << " ";
			}
			cout << ln;
			break;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin >> t;
    forn(i,t) {
    	solve();
    }
    return 0;
}