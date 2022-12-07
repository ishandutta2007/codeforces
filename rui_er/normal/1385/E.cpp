// LUOGU_RID: 93679118
//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T, n, m, id[N], deg[N];
vector<int> e[N];
vector<tuple<int, int> > G;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool toposort() {
	queue<int> q;
	int cnt = 0;
	rep(i, 1, n) if(!deg[i]) q.push(i);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		id[u] = ++cnt;
		for(int v : e[u]) if(!--deg[v]) q.push(v);
	}
	return cnt == n;
}

int main() {
	for(scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, m) {
			int op, x, y;
			scanf("%d%d%d", &op, &x, &y);
			G.emplace_back(x, y);
			if(op) {
				e[x].push_back(y);
				++deg[y];
			}
		}
		if(!toposort()) puts("NO");
		else {
			puts("YES");
			for(auto i : G) {
				int u = get<0>(i), v = get<1>(i);
				if(id[u] < id[v]) printf("%d %d\n", u, v);
				else printf("%d %d\n", v, u);
			}
		}
		rep(i, 1, n) {
			id[i] = deg[i] = 0;
			e[i].clear();
		}
		G.clear();
	}
	return 0;
}