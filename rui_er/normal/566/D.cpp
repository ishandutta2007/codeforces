//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, m, nxt[N]; 
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Dsu {
	int fa[N];
	void init(int x) {rep(i, 1, x) fa[i] = i;}
	int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
	bool merge(int x, int y) {
		int u = find(x), v = find(y);
		if(u == v) return 0;
		fa[v] = u;
		return 1;
	}
}dsu;

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) nxt[i] = i + 1; 
	dsu.init(n);
	rep(i, 1, m) {
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1) dsu.merge(x, y);
		else if(op == 2) {
			int lst = 0;
			for(int i=x+1;i<=y;i=nxt[i]) {
				dsu.merge(i-1, i);
				if(lst) nxt[lst] = nxt[y];
				lst = i;
			}
			nxt[lst] = nxt[y];
		}
		else puts(dsu.find(x)==dsu.find(y)?"YES":"NO");
	}
	return 0;
}