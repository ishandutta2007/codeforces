#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}
int power(int a, int b, int m, int ans=1){for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m; return ans;}

#define NN 100100
int root[NN];
int find(int u){
	return root[u]==u ? u : root[u]=find(root[u]);
}
vector <pii> vec[NN];
int vst[NN];
set <int> adj[NN];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int u, v, c;
		gn(u, v); gn(c);
		vec[c].pb(pii(u, v));
	}
	
	for(int i=1; i<=n; i++) root[i]=i;
	
	int cnt=n;
	for(int i=1; i<=m; i++){
		for(pii e : vec[i]) root[find(e.x)]=find(e.y);
		int pre=cnt;
		for(pii e : vec[i]){
			if(vst[e.x]<=pre && root[e.x]==e.x) vst[e.x]=++cnt;
			if(vst[e.y]<=pre && root[e.y]==e.y) vst[e.y]=++cnt;
		}
		for(pii e : vec[i]){
			adj[e.x].insert(vst[find(e.x)]);
			adj[e.y].insert(vst[find(e.y)]);
		}
		for(pii e : vec[i]) root[e.x]=e.x, root[e.y]=e.y;
	}
	
	map <pii, int> ans;
	cin >> m;
	
	while(m--){
		int u, v; gn(u, v);
		if(ans.count(pii(u, v))){
			printf("%d\n", ans[pii(u, v)]);
			continue;
		}
		
		if(adj[u].size()>adj[v].size()) swap(u, v);
		
		cnt=0;
		for(auto x : adj[u]) if(adj[v].count(x)) cnt++;
		
		printf("%d\n", ans[pii(u, v)]=ans[pii(v, u)]=cnt);
	}
	
	return 0;
}