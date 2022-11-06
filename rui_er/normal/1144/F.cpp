//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, m, col[N];
vector<int> e[N];
vector<tuple<int, int> > G;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool dfs(int u, int c) {
	col[u] = c;
	for(int v : e[u]) {
		if(col[v] == -1) {
			if(!dfs(v, c^1)) return 0;
		}
		else if(col[v] == col[u]) return 0; 
	}
	return 1;
}

int main() {
	memset(col, -1, sizeof(col));
	scanf("%d%d", &n, &m);
	rep(i, 0, m-1) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
		G.emplace_back(u, v);
	}
	rep(i, 1, n) if(col[i] == -1) if(!dfs(i, 0)) return puts("NO")&0;
	puts("YES");
	rep(i, 0, m-1) putchar(col[get<1>(G[i])] ^ 48);
	return 0;
}