#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
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
typedef set<p32> ms;
typedef unordered_map<int,int> m32;
typedef unordered_map<ll,ll> m64;
typedef unordered_map<ll,set<ll> > m648;
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
#define pi 3.141592653589793238462643383279502884L
#define L 1e9
ll n,m,k;
vv32 g;
v32 dep,vis,rev,leaf;

void dfs(int v, int d){
	vis[v]=1;
	dep[v]=d;
	leaf[v]=1;
	forn(i,g[v].size()){
		if(!vis[g[v][i]]) {leaf[v]=0;rev[g[v][i]]=v; dfs(g[v][i],d+1);}
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    // cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    g.resize(n+5);
    leaf.resize(n+5,0);
    vis.resize(n+5,0);
    dep.resize(n+5,0);
    rev.resize(n+5,0);
    int a,b;
    forn(i,m){
    	cin >> a >> b;
    	g[a].pb(b);
    	g[b].pb(a);
    }
    dfs(1,1);
    forn(i,n+1){
    	if(i==0) continue;
    	if(dep[i]>n/k){
    		cout << "PATH" << ln;
    		cout << dep[i] << ln;
    		for(int u=i;u!=1;u=rev[u]){
    			cout << u << " ";
    		}
    		cout << 1 << ln;
    		return 0;
    	}
    }
    cout << "CYCLES" << ln;
    forn(i,n+1){
    	if(i==0) continue;
    	if(leaf[i]){
    		k--;
    		vector<int> v;
    		forn(j,g[i].size()){
    			if(g[i][j]!=rev[i]) v.pb(g[i][j]);
    			if(v.size()==2) break;
    		}
    		if((dep[i]-dep[v[0]]+1)%3 != 0){
    			cout << dep[i]-dep[v[0]]+1 << ln;
    			for(int k=i;k!=v[0];k=rev[k]) cout << k << " ";
    			cout << v[0] << ln;
    		}
    		else if((dep[i]-dep[v[1]]+1)%3 != 0){
    			cout << dep[i]-dep[v[1]]+1 << ln;
    			for(int k=i;k!=v[1];k=rev[k]) cout << k << " ";
    			cout << v[1] << ln;
    		}
    		else{
    			if(dep[v[0]]<dep[v[1]]) swap(v[0],v[1]);
    			cout << dep[v[0]]-dep[v[1]]+2 << ln;
    			for(int k=v[0];k!=v[1];k=rev[k]) cout << k << " ";
    			cout << v[1] << " " << i << ln;
    		}
    	}
    	if(!k) return 0;
    }
    return 0;
}