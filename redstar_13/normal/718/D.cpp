#include<bits/stdc++.h>

#define pb push_back

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> pii;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}
int power(int a, int b, int m, int ans=1){for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m; return ans;}

#define NN 100100

typedef unsigned long long uint;

struct INT {
	uint x, y;
	INT(uint x=0, uint y=0) : x(x), y(y) {}
	bool operator < (const INT &O) const {
		return make_pair(x, y)<make_pair(O.x, O.y);
	}
};

INT seed=INT(100102021, 987654361);
INT operator * (INT a, INT b){
	return INT(a.x*b.x, a.y*b.y);
}
INT operator + (INT a, INT b){
	return INT(a.x+b.x, a.y+b.y);
}

INT dp[NN];
VI adj[NN];
int sz[NN];

void dfs(int u, int f=0){
	sz[u]=1;
	for(int &v : adj[u]){
		if(v==f){
			swap(v, adj[u].back());
			adj[u].pop_back();
			break;
		}
	}
	vector <INT> vec;
	for(int v : adj[u]){
		dfs(v, u);
		vec.pb(dp[v]);
		sz[u]+=sz[v];
	}
	sort(vec.begin(), vec.end());
	
	vec.pb(sz[u]);
	vec.pb(adj[u].size());
	
	dp[u]=0;
	for(INT x : vec) dp[u]=dp[u]*seed+x;
}

set <INT> s;

void redfs(int u, INT pre=0, int psz=0){
	vector <INT> vec;
	vec.pb(pre);
	for(int v : adj[u]) vec.pb(dp[v]);
	
	sort(vec.begin(), vec.end());
	vec.pb(sz[u]+psz);
	vec.pb(adj[u].size()+(psz>0));
	INT ans=0;
	for(INT x : vec) ans=ans*seed+x;
	
	if(adj[u].size()+(psz>0)<4) s.insert(ans);
	for(int v : adj[u]){
		vec.clear();
		vec.pb(pre);
		int ppsz=psz+1;
		for(int w : adj[u]) if(v!=w) vec.pb(dp[w]), ppsz+=sz[w];
		sort(vec.begin(), vec.end());
		vec.pb(ppsz);
		vec.pb(adj[u].size()-(!psz));
		INT ppre=0;
		for(INT x : vec) ppre=ppre*seed+x;
		redfs(v, ppre, ppsz);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n;
	cin >> n;
	for(int i=1; i<n; i++){
		int u, v; gn(u, v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
	redfs(1);
	cout << s.size() << endl;
	
	return 0;
}