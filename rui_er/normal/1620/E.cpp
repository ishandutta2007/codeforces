// Problem: CF1620E Replace the Numbers
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1620E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 5e5+5;

int n, pos[N], len, val[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Dsu {
	int fa[N];
	int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
	bool merge(int x, int y) {
		int u = find(x), v = find(y);
		if(u == v) return 0;
		fa[u] = v;
		return 1;
	}
}dsu;

int main() {
	for(scanf("%d", &n);n;n--) {
		int op, x, y;
		scanf("%d%d", &op, &x);
		if(op == 1) {
			++len;
			if(!pos[x]) pos[x] = len;
			dsu.fa[len] = pos[x];
		}
		else {
			scanf("%d", &y);
			if(x == y) continue;
			if(pos[x]) {
				if(pos[y]) dsu.merge(pos[x], pos[y]);
				else pos[y] = pos[x];
				pos[x] = 0;
			}
		}
	}
	rep(i, 1, N-5) if(pos[i]) val[pos[i]] = i;
	rep(i, 1, len) printf("%d%c", val[dsu.find(i)], " \n"[i==len]);
	return 0;
}