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

vv64 g;
v64 vis,edge,head;

ll fedge(ll v){
	if(edge[v]==v) return v;
	else edge[v]=fedge(edge[v]);
	return edge[v]; 
}

ll fhead(ll v){
	if(head[v]==v) return v;
	else head[v]=fhead(head[v]);
	return head[v];
}

void dfs(ll v){
	cout << v+1 << " ";
	vis[v]=1;
	forn(i,g[v].size()){
		if(vis[g[v][i]]==0) dfs(g[v][i]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll a[n];
    g.resize(n);
    vis.resize(n,0);
    edge.resize(n);
    head.resize(n);
    forn(i,n) a[i]=0,edge[i]=i,head[i]=i;
    ll b,c;
    forn(i,n-1){
    	cin >> b >> c;
    	fhead(c-1);
    	fedge(b-1);
    	g[edge[b-1]].pb(head[c-1]);
    	a[head[c-1]]++;
    	edge[edge[b-1]]=edge[c-1];
    	head[head[c-1]]=head[b-1];
    	// head[c-1]=head[b-1];
    	// edge[b-1]=edge[c-1];
    }
    forn(i,n){
    	if(a[i]==0) dfs(i);
    }
    return 0;
}