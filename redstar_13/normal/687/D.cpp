#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}

#define NN 1010
#define MM 500010

pii edge[MM];
int w[MM];
int n, m, Q;
int id[MM];
int col[NN];
int root[NN];
int rev[MM];

inline int find_root(int u) {
	if(root[u] == u) return u;
	int x = find_root(root[u]);
	col[u] ^= col[root[u]];
	return root[u] = x;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	gn(n, m); gn(Q);
	
	for(int i=1; i<=m; i++) {
		gn(edge[i].x, edge[i].y); gn(w[i]);
	}
	
	for(int i=1; i<=m; i++) id[i] = i;
	sort(id+1, id+m+1, [&] (int u, int v) {return w[u] > w[v];});
	
	while(Q--) {
		int L, R;
		gn(L, R);
		for(int i=1; i<=n; i++) {
			col[i] = 0;
			root[i] = i;
		}
		int ans = -1;
		for(int i=1; i<=m; i++) {
			if(id[i] > R || id[i] < L) continue;
			int u = edge[id[i]].x, v = edge[id[i]].y;
			if(find_root(u) == find_root(v)){
				if(col[u] == col[v]) {
					ans = w[id[i]]; break;
				}
				continue;
			}
			col[root[u]] = col[u] ^ col[v] ^ 1;
			root[root[u]] = root[v];
		}
		printf("%d\n", ans);
	}
}