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
int deg[NN], vst[NN];
set <int> adj[NN];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=0; i<k; i++){
		int u; gn(u); vst[u]=1;
	}
	
	for(int i=0; i<m; i++){
		int u, v; gn(u, v);
		deg[u]++;
		deg[v]++;
		if(!vst[u] && !vst[v]) adj[u].insert(v), adj[v].insert(u);
	}
	
	typedef double DO;
	set <pair <DO, int> > s;
	for(int i=1; i<=n; i++) if(!vst[i]) s.insert(make_pair((DO)adj[i].size()/deg[i], i));
	
	DO ans=-1;
	int pos;
	VI vec;
	
	while(!s.empty()){
		auto p=*s.begin();
		s.erase(s.begin());
		int u=p.y;
		if(ans<p.x){
			ans=p.x;
			pos=vec.size();
		}
		vec.pb(u);
		for(int v : adj[u]){
			s.erase(make_pair((DO)adj[v].size()/deg[v], v));
			adj[v].erase(u);
			s.insert(make_pair((DO)adj[v].size()/deg[v], v));
		}
	}
	
	printf("%d\n", (int)vec.size()-pos);
	for(int i=pos; i<vec.size(); i++) printf("%d ", vec[i]);
	
	return 0;
}