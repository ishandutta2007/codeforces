#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}


#define NN 1000100

vector<int> row[NN];
vector<int> adj[NN*2];
int deg[NN];
int num[NN];
int n, m;
int root[NN];

int calc(int u, int v) {
	return m * (u - 1) + v;
}

int id[NN];
queue<int> q;

int find_root(int u) {
	if(root[u] == u) return u;
	return root[u] = find_root(root[u]);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	gn(n, m);
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			int x;
			gn(x);
			row[i].push_back(x);
		}
	}
	
	for(int i=0; i<NN; i++) root[i] = i;
	
	for(int i=1; i<=n; i++) {
		for(int j=0; j<m; j++) id[j] = j;
		sort(id, id+m, [&] (int u, int v) {return row[i][u] < row[i][v];});
		for(int j=0; j<m-1; j++) if(row[i][id[j]] == row[i][id[j+1]]) {
			int u = calc(i, id[j]), v = calc(i, id[j+1]);
			if(find_root(u) == find_root(v)) continue;
			root[root[u]] = root[v];
		}
	}
	
	for(int j=0; j<m; j++) {
		for(int i=1; i<=n; i++) id[i] = i;
		sort(id+1, id+n+1, [&] (int u, int v) {return row[u][j] < row[v][j];});
		for(int i=1; i<n; i++) if(row[id[i]][j] == row[id[i+1]][j]){
			int u = calc(id[i], j), v = calc(id[i+1], j);
			if(find_root(u) == find_root(v)) continue;
			root[root[u]] = root[v];
		}
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=0; j<m; j++) id[j] = j;
		sort(id, id+m, [&] (int u, int v) {return row[i][u] < row[i][v];});
		for(int j=0; j<m-1; j++) {
			int u = calc(i, id[j]), v = calc(i, id[j+1]);
			if(find_root(u) == find_root(v)) continue;
			adj[root[u]].push_back(root[v]);
			deg[root[v]]++;
		}
	}
	
	for(int j=0; j<m; j++) {
		for(int i=1; i<=n; i++) id[i] = i;
		sort(id+1, id+n+1, [&] (int u, int v) {return row[u][j] < row[v][j];});
		for(int i=1; i<n; i++) {
			int u = calc(id[i], j), v = calc(id[i+1], j);
			if(find_root(u) == find_root(v)) continue;
			adj[root[u]].push_back(root[v]);
			deg[root[v]]++;
		}
	}
	
	for(int i=0; i<NN; i++) if(deg[i] == 0) q.push(i), num[i] = 1;
	
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(auto v : adj[u]) {
			num[v] = max(num[v], num[u] + 1);
			deg[v]--;
			if(!deg[v]) q.push(v);
		}
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=0; j<m; j++) printf("%d ", num[root[calc(i, j)]]);
		putchar('\n');
	}
}