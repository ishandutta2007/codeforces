//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 505; 

int n, m, deg[N], d[N];
vector<int> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool toposort() {
	queue<int> q;
	int tot = 0;
	rep(i, 1, n) {
		if(!deg[i]) {
			q.push(i);
			++tot;
		}
	}
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(auto v : e[u]) {
			--deg[v];
			if(!deg[v]) {
				q.push(v);
				++tot;
			}
		}
	}
	return tot == n;
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		++deg[v];
	}
	memcpy(d+1, deg+1, n*sizeof(int));
	rep(i, 1, n) {
		--deg[i];
		if(toposort()) return puts("YES")&0;
		memcpy(deg+1, d+1, n*sizeof(int));
	}
	puts("NO");
	return 0;
}