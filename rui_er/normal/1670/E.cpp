//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1 << 17 | 5;

int T, n, V[N], E[N], tms;
vector<tuple<int, int> > e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs(int u, int f, int rnd) {
	for(auto i : e[u]) {
		int v = get<0>(i), id = get<1>(i);
		if(v == f) continue;
		++tms;
		if(rnd) V[v] = n + tms, E[id] = tms;
		else V[v] = tms, E[id] = n + tms;
		dfs(v, u, rnd^1);
	}
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		n = 1 << n;
		rep(i, 1, n-1) {
			int u, v;
			scanf("%d%d", &u, &v);
			e[u].push_back(make_tuple(v, i));
			e[v].push_back(make_tuple(u, i));
		}
		V[1] = n;
		dfs(1, 0, 0);
		puts("1");
		rep(i, 1, n) printf("%d%c", V[i], " \n"[i==n]);
		rep(i, 1, n-1) printf("%d%c", E[i], " \n"[i==n-1]);
		rep(i, 1, n) e[i].clear();
		tms = 0;
	}
	return 0;
}