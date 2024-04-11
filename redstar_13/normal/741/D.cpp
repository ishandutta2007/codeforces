#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}

#define NN 500010

vector<int> adj[NN];
int dp[NN], sz[NN], deep[NN];
int fa[NN], col[NN];
int n;
int flag[1<<22], max_deep[1<<22], runs = 1;
int L[NN], R[NN], rev[NN], nn = 0;

int pre_dfs(int u) {
	L[u] = ++nn;
	rev[nn] = u;
	for(auto v : adj[u]) pre_dfs(v);
	R[u] = nn;
}

int ans[NN];

pii dfs(int u) {
	if(adj[u].size() == 0) {
		flag[0] = runs;
		max_deep[0] = 0;
		return pii(0, 0);
	}
	int id = adj[u][0];
	for(auto v : adj[u]) if(sz[id] < sz[v]) id = v;
	for(auto v : adj[u]) if(id != v) dfs(v), runs++, ans[u] = max(ans[u], ans[v]);
	pii p = dfs(id); ans[u] = max(ans[u], ans[id]);
	int val = p.x ^ (1<<col[id]);
	p.x = val; p.y++;
	if(flag[val] == runs) ans[u] = max(ans[u], max_deep[val] + p.y);
	else flag[val] = runs, max_deep[val] = -p.y;
	for(int i=0; i<22; i++) if(flag[(1<<i) ^ val] == runs) {
		ans[u] = max(ans[u], max_deep[(1<<i) ^ val] + p.y);
	}
	for(auto v : adj[u]) if(id != v) {
		for(int i=L[v]; i<=R[v]; i++) {
			int x = rev[i];
			int st = dp[x] ^ dp[u] ^ val;
			if(flag[st] == runs) ans[u] = max(ans[u], deep[x] - deep[u] + max_deep[st] + p.y);
			if(__builtin_popcount(dp[x] ^ dp[u]) <= 1) ans[u] = max(ans[u], deep[x] - deep[u]);
			for(int i=0; i<22; i++) if(flag[st ^ (1<<i)] == runs) {
				ans[u] = max(ans[u], deep[x] - deep[u] + max_deep[st ^ (1<<i)] + p.y);
			}
		}
		for(int i=L[v]; i<=R[v]; i++) {
			int x = rev[i];
			int st = dp[x] ^ dp[u] ^ val;
			if(flag[st] == runs) {
				max_deep[st] = max(max_deep[st], deep[x] - deep[u] - p.y);
			} else {
				max_deep[st] = deep[x] - deep[u] - p.y;
				flag[st] = runs;
			}
		}
	}
	return p;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	gn(n);
	deep[1] = 1;
	for(int i=2; i<=n; i++) {
		gn(fa[i]); char s;
		scanf(" %c", &s);
		adj[fa[i]].push_back(i);
		deep[i] = deep[fa[i]] + 1;
		col[i] = s - 'a';
		dp[i] ^= (1<<s-'a');
		dp[i] ^= dp[fa[i]];
	}
	for(int i=n; i; i--) {
		sz[i]++;
		sz[fa[i]] += sz[i];
	}
	
	pre_dfs(1);
	for(int i=0; i<(1<<22); i++) max_deep[i] = -n-10;
	dfs(1);
	
	for(int i=1; i<=n; i++) printf("%d\n", ans[i]);
}