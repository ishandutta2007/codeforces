#include <bits/stdc++.h>
#include <set>
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
string s;
v64 v,visited,ans;
vv64 graph;
ll k = 0;
ll result;

void dfs1(int i)
{
	visited[i]=0;
	ans[i] = v[i];
	bool b=true;
	if(ans[i]==result && b){
			k++;
			ans[i]=0;
			b=false;
	}
	forn(j,graph[i].size()){
		if(visited[graph[i][j]] == 1){
			dfs1(graph[i][j]);
			if(b){
				ll t = ans[graph[i][j]];
				if(t>0) ans[i]+=t;
			}
			if(ans[i]==result && b){
				k++;
				ans[i]=0;
				b = false;
			}
			// cout << ans[i] << ln;
		}	
	}
}

void dfs(int i)
{
	visited[i]=1;
	ans[i] = v[i];
	forn(j,graph[i].size()){
		if(visited[graph[i][j]] == 0){
			dfs(graph[i][j]);
			ll t = ans[graph[i][j]];
			if(t>0) ans[i]+=t;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll n;
	cin >> n;
	v.resize(n);
	forn(i,n) cin >> v[i];
	graph.resize(n);
	ans.resize(n,0);
	visited.resize(n,0);
	ll a,b;
	forn(i,n-1){
		cin >> a >> b;
		a--;b--;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	dfs(0);
	result = *max_element(ans.begin(),ans.end());
	dfs1(0);
	result *= k;
	cout << result << " " << k << ln;
}