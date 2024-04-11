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
ll MOD = 1e9 + 7;
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

v64 par;
vv64 g,grev;
ll n,m;
v64 ans;
v64 order;

// vv64 g;
// v64 vis,edge,head;

// ll fedge(ll v){
// 	if(edge[v]==v) return v;
// 	else edge[v]=fedge(edge[v]);
// 	return edge[v]; 
// }

// ll fhead(ll v){
// 	if(head[v]==v) return v;
// 	else head[v]=fhead(head[v]);
// 	return head[v];
// }

// void dfs(ll v){
// 	cout << v+1 << " ";
// 	vis[v]=1;
// 	forn(i,g[v].size()){
// 		if(vis[g[v][i]]==0) dfs(g[v][i]);
// 	}
// }

void no(){
	cout << "No" << ln;
	exit(0);
}

ll fpar(ll v){
	if(par[v]==v) return v;
	par[v] = fpar(par[v]);
	return par[v];
}

void dfs(ll v, ll k, ll vis1[]){
	vis1[v]=1;
	ans[v]=k;
	cout <<  v << k << ln;
	forn(i,grev[v].size()){
		if(vis1[grev[v][i]]==0) dfs(grev[v][i],k+1,vis1);
	}
}

void top(ll v, ll vis2[]){
	vis2[v]=1;
	forn(i,g[v].size()){
		if(vis2[g[v][i]]==0) top(g[v][i],vis2);
	}
	order.pb(v);
}

void dfs2(ll v, ll vis[]){
	// cout << v << ln;
	vis[v]=1;
	forn(i,g[v].size()){
		if(vis[g[v][i]]==1) no();
		else if(vis[g[v][i]]==0) dfs2(g[v][i],vis);
	}
	vis[v]=2;
}

void cycle(){
	ll vis[n+m];
		forn(i,n+m){
			vis[i]=0;
		}
	forn(i,n+m){		
		dfs2(i,vis);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    vv64 v(n+m);
    g.resize(n+m);
    grev.resize(n+m);
    par.resize(n+m);
    ans.resize(n+m);
    forn(i,n+m) par[i]=i;
    char c;
    forn(i,n){
    	forn(j,m){
    		cin >> c;
    		if(c=='>') v[m+i].pb(j);
    		else if(c=='<') v[j].pb(m+i);
    		else par[fpar(j)]=fpar(m+i);
    	}
    }
    // forn(i,n+m){
    // 	cout << i << "   ";
    // 	forn(j,v[i].size()){
    // 		cout << v[i][j] << " "; 
    // 	}
    // 	cout << ln;
    // }
    // forn(i,n+m){
    // 	cout << fpar(i) << " ";
    // }
    // cout << ln; 
    forn(i,n+m){
    	ll t = fpar(i);
    	forn(j,v[i].size()){
    		ll k = fpar(v[i][j]);
    		if(k==t) no();
    		g[t].pb(k); 
    		grev[k].pb(t);
    	}
    }
    // forn(i,n+m){
    // 	cout << i << "   ";
    // 	forn(j,grev[i].size()){
    // 		cout << grev[i][j] << " "; 
    // 	}
    // 	cout << ln;
    // }
    cycle();
    // return 0;
    // cout << 1 << ln;
    ll vis1[n+m],vis2[n+m];
    forn(i,n+m) vis1[i]=0,vis2[i]=0;
    forn(i,n+m){
    	if(vis2[fpar(i)]==0) top(fpar(i),vis2);
    }
    // cout << 1 << ln;
    // forn(i,n+m){
    // 	cout << order[i] << " ";
    // }
    // cout << ln;
    forn(i,order.size()){
    	if(vis1[order[i]]==0) {
    		ans[order[i]]=1;
    		priority_queue <p64> pq;
    		pq.push(mp(1,order[i]));
    		while(!pq.empty()){
    			ll u = pq.top().se;
    			ll c = pq.top().fi;
    			vis1[u]=1;
    			// cout << u << " " << c << ln;
    			// cout << pq.size() << ln;
    			pq.pop();
    			forn(i,grev[u].size()){
    				if(ans[grev[u][i]]<ans[u]+1){
    					ans[grev[u][i]]=ans[u]+1;
    					pq.push(mp(ans[grev[u][i]],grev[u][i]));
    				}
    			}
    		}
    		// dfs(order[i],1,vis1);
    	}
    	// cout << "yo" << ln;
    }
    // forn(i,n+m){
    // 	cout << order[i] << " ";
    // }
    // cout << ln;
    cout << "Yes" << ln;
    forn(i,n){
    	cout << ans[fpar(i+m)] << " ";
    }
    cout << ln;
    forn(i,m){
    	cout << ans[fpar(i)] << " ";
    }
    cout << ln;
    return 0;
}