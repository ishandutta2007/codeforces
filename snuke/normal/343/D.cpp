#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 500005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int n, q;
vector<int> to[MX];
vector<int> fl[MX], em[MX], qu[MX];
int l[MX], r[MX], ansi[MX], ansn;

int si[MX];
set<int> s[MX];

void dfs(int v, int p){
	rep(i,to[v].size()){
		int u = to[v][i];
		if(u == p) continue;
		dfs(u,v);
		if(s[si[u]].size() > s[si[v]].size()) swap(si[v],si[u]);
		each(it,s[si[u]]) s[si[v]].insert(*it);
		s[si[u]].clear();
	}
	rep(i,em[v].size()) s[si[v]].insert(em[v][i]);
	rep(i,qu[v].size()){
		int t = qu[v][i];
		set<int>::iterator it = s[si[v]].lower_bound(t);
		if(it == s[si[v]].begin()) r[t] = -1; else {
			--it;
			r[t] = (*it);
		}
	}
}

set<int> g;

void dfs2(int v, int p){
	rep(i,fl[v].size()) g.insert(fl[v][i]);
	rep(i,qu[v].size()){
		int t = qu[v][i];
		set<int>::iterator it = g.lower_bound(t);
		if(it == g.begin()) l[t] = -2; else {
			--it;
			l[t] = (*it);
		}
	}
	rep(i,to[v].size()){
		int u = to[v][i];
		if(u == p) continue;
		dfs2(u,v);
	}
	rep(i,fl[v].size()) g.erase(g.find(fl[v][i]));
}

int main(){
	int a, b;
	cin >> n;
	rep(i,n) si[i] = i;
	rep(i,n-1){
		cin >> a >> b;
		a--; b--;
		to[a].pb(b);
		to[b].pb(a);
	}
	
	cin >> q;
	ansn = 0;
	
	rep(i,q){
		cin >> a >> b;
		b--;
		if(a == 1){
			fl[b].pb(i);
		} else if(a == 2){
			em[b].pb(i);
		} else {
			qu[b].pb(i);
			ansi[ansn++] = i;
		}
	}
	
	dfs(0,-1);
	//rep(i,q) printf("%d : %d\n",i,r[i]);
	
	dfs2(0,-1);
	
	rep(i,ansn){
		int ans = 0;
		if(l[ansi[i]] > r[ansi[i]]) ans = 1;
		cout << ans << endl;
	}
	
	return 0;
}