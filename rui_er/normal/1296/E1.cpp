//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 205; 

int n, id[N], col[N];
char s[N];
vector<int> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool dfs(int u, int f) {
	col[u] = col[f] ^ 1;
	for(auto v : e[u]) {
		if(col[v] == -1) {
			if(!dfs(v, u)) return 0;
		}
		else if(col[u] == col[v]) return 0;
	}
	return 1;
}

int main() {
	memset(col, -1, sizeof(col));
	col[0] = 0;
	scanf("%d%s", &n, s+1);
	rep(i, 1, n) id[i] = i;
	rep(i, 1, n-1) {
		rep(j, 1, n-1) {
			if(s[j] > s[j+1]) {
				e[id[j]].push_back(id[j+1]);
				e[id[j+1]].push_back(id[j]);
				swap(s[j], s[j+1]);
				swap(id[j], id[j+1]);
			}
		}
	}
	rep(i, 1, n) {
		if(col[i] == -1 && !dfs(i, 0)) return puts("NO")&0;
	}
	puts("YES");
	rep(i, 1, n) printf("%d", col[i]);
    return 0;
}