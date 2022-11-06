//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T, n, k, b[N], c[N], deg[N], id[N];
vector<int> e[N], tp;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void toposort() {
	priority_queue<tuple<int, int> > q;
	rep(i, 1, n) if(!deg[i]) q.emplace(id[i], i);
	while(!q.empty()) {
		int u = get<1>(q.top()); q.pop();
		tp.push_back(u);
		for(int v : e[u]) if(!--deg[v]) q.emplace(id[v], v);
	}
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &b[i]);
		rep(i, 1, n) c[i] = (b[i] < i);
		k = lower_bound(c+1, c+1+n, 1) - c - 1;
		printf("%d\n", k);
		rep(i, 1, n) {
			if(1 <= b[i] && b[i] <= n) {
				e[b[i]].push_back(i);
				++deg[i];
				--id[b[i]];
			}
		}
		toposort();
		for(int i : tp) printf("%d ", i); puts("");
		rep(i, 1, n) e[i].clear(), id[i] = 0;
		tp.clear();
	}
	return 0;
}