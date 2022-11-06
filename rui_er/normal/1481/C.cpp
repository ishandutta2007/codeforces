//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, m, a[N], b[N], c[N], need[N], ok[N], ans[N];
struct Edge {
	int v, nxt;
	Edge(int a=0, int b=0) : v(a), nxt(b) {}
	~Edge() {}
}e[N<<1];
int ne, h[N];
void add(int u, int v) {
	e[++ne] = Edge(v, h[u]);
	h[u] = ne;
}

int main() {
	mulT0 {
		fil(h, 0); fil(e, 0); fil(need, 0); fil(ok, 0); fil(ans, 0);
		ne = 0;
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) scanf("%d", &b[i]);
		rep(i, 1, m) scanf("%d", &c[i]);
		rep(i, 1, n) if(a[i] == b[i]) add(b[i], i);
		rep(i, 1, n) {
			if(a[i] != b[i]) {
				need[i] = b[i];
				add(b[i], i);
			}
			else ok[i] = 1;
		}
		per(i, m, 1) {
			if(!h[c[i]]) continue;
			int j = h[c[i]];
			int v = e[j].v;
			ok[v] = 1;
			ans[i] = v;
			h[c[i]] = e[j].nxt;
		}
		int _ = 1;
		rep(i, 1, n) if(!ok[i]) {_ = 0; break;}
		if(!_) puts("NO");
		else {
			int goal = ans[m];
			if(!goal) {puts("NO"); continue;}
			puts("YES");
			rep(i, 1, m) {
				if(ans[i]) printf("%d", ans[i]);
				else printf("%d", goal);
				printf("%c", " \n"[i==m]);
			}
		}
	}
	return 0;
}