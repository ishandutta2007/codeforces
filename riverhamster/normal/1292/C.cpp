#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void gi(T &x){
	char ch; x = 0;
	int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}
const int N = 3005;
vector<int> G[N];
vector<pair<int, int> > path[N];

int n, sz[N], dep[N], dis[N];
int pto[N][N];
ll f[N][N][2];

void dfs(int x, int fa){
	sz[x] = 1;
	for(int v : G[x]){
		if(v == fa) continue;
		dep[v] = dep[x] + 1;
		dfs(v, x);
		sz[x] += sz[v];
	}
}
int rt;
void getPath(int x, int fa, int pfrom){
	path[dis[x]].push_back(make_pair(rt, x));
	pto[rt][x] = pfrom;
	for(int v : G[x]){
		if(v == fa) continue;
		dis[v] = dis[x] + 1;
		getPath(v, x, !pfrom ? v : pfrom);
	}
}

int main(){
	// File("c");
	gi(n);
	for(int i=1, x, y; i<n; i++) gi(x), gi(y), G[x].push_back(y), G[y].push_back(x);
	for(int i=1; i<=n; i++){
		rt = i;
		dis[i] = 0;
		getPath(i, i, 0);
	}
	dep[1] = 1; dfs(1, 1);
	memset(f, 0x9f, sizeof(f));
	for(int u=1; u<=n; u++)
		for(int v : G[u]){
			int p = u, q = v;
			if(dep[p] > dep[q]) swap(p, q);
			f[p][q][0] = sz[q] * (n - sz[q]);
			for(int x : G[p]){
				if(x == pto[p][q]) continue;
				if(dep[x] > dep[p]) upmax(f[x][q][1], max(f[p][q][0], f[p][q][1]) + sz[q] * sz[x]);
				else upmax(f[x][q][0], f[p][q][0] + sz[q] * (n - sz[p]));
			}
			for(int x : G[q]){
				if(x == pto[q][p]) continue;
				if(dep[x] > dep[q]){
					upmax(f[p][x][0], f[p][q][0] + sz[x] * (n - sz[pto[p][q]]));
					upmax(f[p][x][1], f[p][q][1] + sz[x] * sz[p]);
				}
			}
		}
	for(int d=2; d<=n; d++)
		for(pair<int, int> pt : path[d]){
			int p = pt.first, q = pt.second;
			for(int x : G[p]){
				if(x == pto[p][q]) continue;
				if(dep[x] > dep[p]) upmax(f[x][q][1], max(f[p][q][0], f[p][q][1]) + sz[q] * sz[x]);
				else upmax(f[x][q][0], f[p][q][0] + sz[q] * (n - sz[p]));
			}
			for(int x : G[q]){
				if(x == pto[q][p]) continue;
				if(dep[x] > dep[q]){
					upmax(f[p][x][0], f[p][q][0] + sz[x] * (n - sz[pto[p][q]]));
					upmax(f[p][x][1], f[p][q][1] + sz[x] * sz[p]);
				}
			}
		}
	ll res = 0;
	for(int p=1; p<=n; p++)
		for(int q=1; q<=n; q++){
			upmax(res, max(f[p][q][0], f[p][q][1]));
			// if(f[p][q][0] > 0) printf("f[%d][%d][0] = %lld\n", p, q, f[p][q][0]);
			// if(f[p][q][1] > 0) printf("f[%d][%d][1] = %lld\n", p, q, f[p][q][1]);
		}
	printf("%lld\n", res);
	return 0;
}