#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void gi(T &x){
	char ch; x = 0;
	int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}

const int N = 300005;
vector<int> G[N];

int fa[N][21], dep[N];
int lgn;

void dfs(int x){
	for(int i=1; i<=lgn; i++) fa[x][i] = fa[fa[x][i-1]][i-1];
	for(int v : G[x]){
		if(v == fa[x][0]) continue;
		fa[v][0] = x;
		dep[v] = dep[x] + 1;
		dfs(v);
	}
}
int lca(int x, int y){
	// printf("LCA %d %d\n", x, y);
	if(dep[x] < dep[y]) swap(x, y);
	int d = dep[x] - dep[y];
	for(int i=0; d; d>>=1, ++i) if(d & 1) x = fa[x][i];
	if(x == y) return x;
	for(int i=lgn; i>=0; i--)
		if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	// printf("LCA %d\n", fa[x][0]);
	return fa[x][0];
}
int dis(int x, int y){
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}

int main(){
	// File("e");
	int n;
	gi(n);
	lgn = log2(n);
	for(int i=1; i<n; i++){
		int u, v;
		gi(u); gi(v);
		G[u].push_back(v); G[v].push_back(u);
	}
	for(int i=0; i<=lgn; i++) fa[1][i] = 1;
	dfs(1);
	int Q;
	gi(Q);
	while(Q--){
		int x, y, a, b, d;
		gi(a); gi(b); gi(x); gi(y); gi(d);
		int D[3];
		D[0] = dis(x, y);
		D[1] = dis(x, a) + dis(y, b) + 1;
		D[2] = dis(x, b) + dis(y, a) + 1;
		bool flag = true;
		for(int i=0; i<3; i++)
			if(D[i] <= d && (d - D[i]) % 2 == 0){
				puts("YES");
				flag = false;
				break;
			}
		if(flag) puts("NO");
	}
	return 0;
}