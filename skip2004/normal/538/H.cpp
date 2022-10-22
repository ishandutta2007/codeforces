#include<bits/stdc++.h>
const int maxn = 100100;
int t,T,n,m,n0,n1;
int l[maxn],r[maxn],c[maxn],vis[maxn];
std::vector<int> v[maxn];
std::queue<int> q;
inline void dfs(int x) { if(vis[x]) return ; vis[x] = 1; for(auto i : v[x]) c[i] = !c[x],dfs(i); }
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> t >> T >> n >> m;
	n1 = 0; n0 = T;
	for(int i = 1;i <= n;++i){
		std::cin >> l[i] >> r[i],c[i] = -1;
		n0 = std::min(n0,r[i]);
		n1 = std::max(n1,l[i]);
	}
	if(n1 + n0 > T) n0 = T - n1;
	if(n1 + n0 < t) n1 = t - n0;
	if(n0 < 0 || n1 < 0) { puts("IMPOSSIBLE"); return 0; }
	for(int i = 1,x,y;i <= m;++i) {
		std::cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i = 1;i <= n;++i) {
		if(n1 < l[i] || r[i] < n1){
			if(c[i] != -1 && c[i] != 0) { puts("IMPOSSIBLE"); return 0; }
			c[i] = 0;
		}
		if(n0 < l[i] || r[i] < n0) {
			if(c[i] != -1 && c[i] != 1) { puts("IMPOSSIBLE"); return 0; }
			c[i] = 1;
		}
		if(c[i] >= 0) dfs(i);
	}
	for(int i = 1;i <= n;++i) if(c[i] == -1) c[i] = 0,dfs(i);
	for(int i = 1;i <= n;++i) for(int j : v[i]) if(c[i] + c[j] != 1) { puts("IMPOSSIBLE"); return 0; }
	std::cout << "POSSIBLE" << '\n' << n0 << ' ' << n1 << '\n';
	for(int i = 1;i <= n;++i) std::cout << c[i] + 1;
}