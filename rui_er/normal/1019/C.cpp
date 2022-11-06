//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n, m, vis[N], select[N];
vector<int> e[N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
	}
	rep(u, 1, n) {
		if(!vis[u]) {
			vis[u] = 1;
			select[u] = 1;
			for(auto v : e[u]) vis[v] = 1;
		}
	}
	per(u, n, 1) {
		if(select[u]) {
			for(auto v : e[u]) select[v] = 0;
		}
	}
	rep(u, 1, n) if(select[u]) ans.push_back(u);
	printf("%d\n", (int)ans.size());
	for(auto i : ans) printf("%d ", i);
	return 0;
}