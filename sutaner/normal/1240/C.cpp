#include <bits/stdc++.h>
#define ll long long int 
#define maxn 600019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
using namespace std;

int n, k;
struct edge{
	int next, to, len;
	edge(int next, int to, int len) : next(next), to(to), len(len){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int z){
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, z);
	h[y] = cnt;
}

ll dp[maxn][2];
bool vis[maxn][2];
ll lis[maxn];
int ct = 0;
void DP(int x, int fa, bool op){
	if (vis[x][op]) return;
	vis[x][op] = 1;
	ll& ans = dp[x][op];
	ans = 0;
	erep(i, x){
		int y = e[i].to;
		if (y == fa) continue;
		DP(y, x, 1), DP(y, x, 0);
		ans += dp[y][0];
	}
	
	ct = 0;
	erep(i, x){
		int y = e[i].to;
		if (y == fa) continue;
		lis[++ct] = dp[y][1] + e[i].len - dp[y][0];
	}
	
	if (ct) sort(lis + 1, lis + 1 + ct);
	int bound = (op) ? (k - 1) : k;
	per(i, ct, 1){
		if (!bound || lis[i] <= 0) break;
		bound--;
		ans += lis[i];
	}
}

int main(){
	int T, x, y, z;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &k);
		srep(i, 1, n) scanf("%d%d%d", &x, &y, &z), Add_Edge(x, y, z);
		DP(1, 0, 0);
		printf("%lld\n", dp[1][0]);
		rep(i, 1, n) vis[i][0] = vis[i][1] = 0, h[i] = 0;
		cnt = 1;
	}
	return 0;
}