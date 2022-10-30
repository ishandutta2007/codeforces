#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}


#define NN 200010

int E;

int to[NN], head[NN], nxt[NN];
char col[NN];

int init() {
	E = 0;
	memset(head, -1, sizeof head);
}

int add_edge(int u, int v, char st) {
	nxt[E] = head[u], to[E] = v, col[E] = st, head[u] = E++;
}

int g[NN];
int flag[NN];
vector<int> res;
vector<int> all[2];
int n, m;

int dfs(int u, char s) {
	all[g[u]].push_back(u);
	for(int e=head[u]; e!=-1; e=nxt[e]) {
		int v = to[e];
		if(flag[v]) {
			if(s != col[e] and g[u] == g[v]) return 0;
			if(s == col[e] and g[u] != g[v]) return 0;
			continue;
		}
		flag[v] = 1;
		g[v] = g[u];
		if(s != col[e]) g[v] ^= 1;
		if(!dfs(v, s)) return 0;
	}
	return 1;
}

int S = 0;

int solve(char s) {
	memset(g, -1, sizeof g);
	memset(flag, 0, sizeof flag);
	vector<int> vec;
	vec.clear();
	for(int i=1; i<=n; i++) if(!flag[i]) {
		for(int j=0; j<2; j++) all[j].clear();
		g[i] = 0;
		flag[i] = 1;
		if(!dfs(i, s)) return S--, 0;
		if(all[0].size() < all[1].size()) for(auto x : all[0]) vec.push_back(x);
		else for(auto x : all[1]) vec.push_back(x);
	}
	if(s == 'R') res = vec;
	if(s == 'B' and S == -1) res = vec;
	if(s == 'B' and res.size() > vec.size()) res = vec;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	gn(n, m);
	init();
	
	for(int i=1; i<=m; i++) {
		int u, v; char s;
		gn(u, v); scanf(" %c", &s);
		add_edge(u, v, s);
		add_edge(v, u, s);
	}
	
	solve('R');
	solve('B');
	if(S == -2) return puts("-1"), 0;
	
	printf("%d\n", res.size());
	for(auto u : res) printf("%d ", u);
}