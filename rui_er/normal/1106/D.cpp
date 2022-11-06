//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, m, vis[N];
priority_queue<int> q;
vector<int> e[N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	vis[1] = 1;
	q.push(-1);
	while(!q.empty()) {
		int u = -q.top(); q.pop();
		ans.push_back(u);
		for(auto v : e[u]) {
			if(!vis[v]) {
				vis[v] = 1;
				q.push(-v);
			}
		}
	}
	for(auto i : ans) printf("%d ", i);
	return 0;
}