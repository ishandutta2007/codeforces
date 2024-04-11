#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;
#define Min(a, b) (a > b ? b : a)
#define N 3030
#define X first
#define Y second
#define inf 1<<30
#define clr(u) memset(u, 0, sizeof(u))

typedef pair <int, int> PII;
typedef vector <PII> VPII;

VPII v[N];
bool vis[N];
int f[N], g[N], h[N];

void dfs(int x){

    int cnt = 0, tot = 0, i, dir;

    vis[x] = 1; g[x] = 0;

    for(i = 0; i < v[x].size(); i++){
        int u = v[x][i].X;
        if(vis[u]) continue;

        if(v[x][i].Y > 0) dir = 0;
        else dir = 1;

        dfs(u);
        g[x] += (g[u] + dir);
        cnt = Min(cnt, f[u] + !dir - (g[u] + dir));
        tot = Min(tot, h[u] - g[u]);
    }

    f[x] = g[x] + cnt;
    h[x] = g[x] + tot;
    h[x] = Min(h[x], f[x]);
}

int main(){

    ///freopen("C.in", "r", stdin);

    int n, i, x, y;
    scanf("%d", &n);

	for(i = 1; i < n; i++){
		scanf("%d %d", &x, &y);
		v[x].push_back(make_pair(y, 1));
		v[y].push_back(make_pair(x, -1));
	}
	int ans = inf;
	for(i = 1; i <= n; i++){
		clr(vis); clr(f); clr(g); dfs(i);
		ans = Min(ans, h[i]);
	}
	printf("%d\n",ans);
    return 0;
}