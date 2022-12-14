#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

#define N 21
#define M 300001

int root[M], use[M];

vector<int> V[M], W[M];
int deep[M], dp[M], vis[M], par[M], log[M];

int Pa[M][N], Dp[M][N];

ll ans[M];

int n;

struct dat{
	int x, y, w, id;
	dat(int x = 0, int y = 0, int w = 0, int id = 0):x(x), y(y), w(w),id(id){}
}p[M];

int find_root(int x) {
	if(root[x] == x) return x;
	return root[x] = find_root(root[x]);
}

void dfs(int u) {
	vis[u] = 1;
	for(int i = 0; i < V[u].size(); i ++) {
		int x = V[u][i];
		if(vis[x]) continue;
        dp[x] = dp[u] + 1;
        par[x] = u;
        deep[x] = W[u][i];
        dfs(x);
	}
}

void prepare() {
    for(int i = 2; i <= n; i ++) Pa[i][0] = par[i], Dp[i][0] = deep[i];
	for(int x = 1; x <= 20; x ++) {
		for(int i = 1; i <=n; i ++) {
			int y = Pa[i][x-1];
            Pa[i][x] = Pa[y][x-1];
            Dp[i][x] = max(Dp[i][x-1] , Dp[y][x-1]);
		}
	}
}

bool cmp(dat A, dat B) {
	if(A.w != B.w) return A.w < B.w;
	return 0;
}

int calc_pa(int x, int cur) {
    if(!cur) return x;
    int z = log[cur];
    return calc_pa(Pa[x][z], cur - (1 << z));
}

int is_par(int x, int y) {
    if(dp[x] > dp[y]) return 0;
    return x == calc_pa(y, dp[y] - dp[x]);
}

int lca(int x, int y) {
    int st = -1, en = dp[x];
    while(en > st + 1) {
        int mid = (en + st) / 2;
		int z = calc_pa(x, mid);
		if(is_par(z, y)) en = mid;
		else st = mid;
    }
    return calc_pa(x, en);
}

int calc(int x, int D) {
    if(!D) return 0;
    int z = log[D];
    return max(Dp[x][z], calc(Pa[x][z], D - (1 << z)));
}

int main() {
	log[1] = 0;
	for(int i = 2; i < M; i ++) log[i] = log[i/2] + 1;
	///freopen("e.in", "r", stdin);
	int m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i ++) {
    	scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].w);
		p[i].id = i;
    }
    sort(p, p + m, cmp);
    for(int i = 1; i <= n; i ++) root[i] = i;
    ll tot = 0;
    for(int i = 0; i < m; i ++) {
        int x = p[i].x, y = p[i].y, w = p[i].w, id = p[i].id;
		int a = find_root(x), b = find_root(y);
		if(a == b) use[i] = 0;
		else {
			use[i] = 1;
			tot += w;
            root[b] = a;
		}
    }
	for(int i = 0; i < m; i ++) if(use[i]){
        int x = p[i].x, y = p[i].y, w = p[i].w;
		V[x].push_back(y);
        W[x].push_back(w);
		V[y].push_back(x);
		W[y].push_back(w);
	}
	memset(vis, 0, sizeof(vis));
	dfs(1);
    prepare();
    for(int i = 0; i < m; i ++) {
		int x = p[i].x, y = p[i].y, id = p[i].id;
		if(par[x] == y || par[y] == x) ans[id] = tot;
		else {
			int z = lca(x, y);
			ans[id] = tot + p[i]. w - max(calc(x, dp[x] - dp[z]), calc(y, dp[y] - dp[z]));
		}
    }
    for(int i = 0; i < m; i ++) printf("%I64d\n", ans[i]);
}