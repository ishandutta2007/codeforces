// Problem: CF1494E A-Z Graph
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1494E
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
const int N = 2e5+5;

int n, m, same, bidir; // u<->v(c) | u->v(c1) v->u(c2)
map<tuple<int, int>, char> e;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &m);
	while(m --> 0) {
		char op[2];
		scanf("%s", op);
		if(op[0] == '+') {
			int u, v; char c[2];
			scanf("%d%d%s", &u, &v, c);
			e[make_tuple(u, v)] = c[0];
			if(e[make_tuple(v, u)]) ++bidir;
			if(e[make_tuple(v, u)] == e[make_tuple(u, v)]) ++same;
		}
		else if(op[0] == '-') {
			int u, v;
			scanf("%d%d", &u, &v);
			if(e[make_tuple(v, u)]) --bidir;
			if(e[make_tuple(v, u)] == e[make_tuple(u, v)]) --same;
			e[make_tuple(u, v)] = 0;
		}
		else {
			int k;
			scanf("%d", &k);
			if(k & 1) puts(bidir?"YES":"NO");
			else puts(same?"YES":"NO");
		}
	}
	return 0;
}