/*
                     _ooOoo_
                    o8888888o
                    88" . "88
                    (| -_- |)
                    O\  =  /O
                 ____/`---'\____
               .'  \\|     |//  `.
              /  \\|||  :  |||//  \
             /  _||||| -:- |||||-  \
             |   | \\\  -  /// |   |
             | \_|  ''\---/''  |   |
             \  .-\__  `-`  ___/-. /
           ___`. .'  /--.--\  `. . __
        ."" '<  `.___\_<|>_/___.'  >'"".
       | | :  `- \`.;`\ _ /`;.`/ - ` : | |
       \  \ `-.   \_ __\ /__ _/   .-` /  /
  ======`-.____`-.___\_____/___.-`____.-'======
                     `=---='
  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                    BUG
*/
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
const int N = 2e5+5, M = 1e6+5;

int n, m, st, dfn[N], low[N], vis[N], now, pos[N], sz[N], indeg[N], tot, ans;
stack<int> s;
struct Edge {
	int v, nxt;
	Edge(int a=0, int b=0) : v(a), nxt(b) {}
	~Edge() {}
}e[M];
int ne = 1, h[N];
void add(int u, int v) {
	e[++ne] = Edge(v, h[u]);
	h[u] = ne;
}
void tarjan(int u) {
	low[u] = dfn[u] = ++now;
	vis[u] = 1;
	s.push(u);
	for(int i=h[u];i;i=e[i].nxt) {
		int v = e[i].v;
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(vis[v]) low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u]) {
		++tot;
		loop {
			int v = s.top();
			pos[v] = tot;
			++sz[tot];
			vis[v] = 0;
			s.pop();
			if(u == v) break;
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &st);
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	rep(u, 1, n) if(!dfn[u]) tarjan(u);
	rep(u, 1, n) for(int i=h[u];i;i=e[i].nxt) {
		int v = e[i].v;
		if(pos[u] != pos[v]) ++indeg[pos[v]];
	}
	rep(i, 1, tot) if(!indeg[i]) ++ans;
	if(!indeg[pos[st]]) --ans;
	printf("%d\n", ans);
    return 0;
}