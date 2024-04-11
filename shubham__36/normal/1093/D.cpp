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
string s,p;
ll t,n,m,ans,a,b1,c,c1;
vv64 g;
v32 vis;
bool b;

ll pow(ll k){
	if(k==0) return 1;
	ll ans = pow(k/2);
	ans *= ans;
	if(k%2 == 1) ans *= 2;
	ans %= MOD;
	return ans;
}

void dfs(ll i,ll v){
	vis[i]=v;
	if(v==1) c1++;
	c++;
	forn(j,g[i].size()){
		if(vis[g[i][j]]==0) dfs(g[i][j],3-v);
		else if(vis[g[i][j]] == v) b=true;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> t;
	forn(z,t){
		ans =1;
		b = false;
		cin >> n >> m;
		g.resize(n);
		vis.resize(n,0);
		forn(i,m){
			cin >> a >> b1;--a,--b1;
			// cout << a << b1<<ln;
			// cout << g.size() << vis.size()<<ln;
			g[a].pb(b1),g[b1].pb(a);
		}
		forn(i,n){
			c = 0;
			c1=0;
			if(vis[i]==0) {dfs(i,1);  ans *= pow(c1) + pow(c-c1); ans %= MOD;}
		}
		if(b) cout << 0 << ln;
		else cout << ans << ln;
		g.clear();
		vis.clear();
	}
}