#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<INT, int> pii;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}
int power(int a, int b, int m, int ans=1){for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m; return ans;}

#define NN 300300
VI adj[NN];
int dep[NN];
typedef priority_queue <pii, vector <pii>, greater <pii> > pq;

pq q[NN];

void dfs(int u, int f=0){
	for(int &v : adj[u]){
		if(v==f){
			swap(v, adj[u].back());
			adj[u].pop_back();
			break;
		}
	}
	dep[u]=dep[f]+1;
	for(int v : adj[u]) dfs(v, u);
}

INT val[NN];

void merge(int u, int v){
	if(q[u].size()<q[v].size()) swap(q[u], q[v]), swap(val[u], val[v]);
	while(!q[v].empty()){
		pii p=q[v].top();
		if(q[u].top().x+val[u]>p.x+val[v] || q[u].top().y>p.y) q[u].push(pii(p.x+val[v]-val[u], p.y));
		q[v].pop();
	}
}

INT ans;
void calc(int u){
	for(int v : adj[u]){
		calc(v);
		merge(u, v);
	}
	while(!q[u].empty() && q[u].top().y>=dep[u]) q[u].pop();
	if(u>1){
		if(q[u].empty()){
			puts("-1");
			exit(0);
		}
		ans+=q[u].top().x+val[u];
		val[u]=-q[u].top().x;
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	
	for(int i=1; i<n; i++){
		int u, v;
		gn(u, v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs(1);
	
	for(int i=0; i<m; i++){
		int u, v, w;
		gn(u, v), gn(w);
		if(u==v) continue;
		q[u].push(pii(w, dep[v]));
	}
	
	calc(1);
	cout << ans << endl;
	
	return 0;
}