#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define maxr 100000
#define maxn 400019
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    x = (f) ? x : -x;
}

int n;

struct edge{
    int next, to;
    edge(int next, int to) : next(next), to(to){}
    edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn], deg[maxn];
void Add_Edge(int x, int y){
    e[++cnt] = edge(h[x], y);
    h[x] = cnt;
    e[++cnt] = edge(h[y], x);
    h[y] = cnt;
    deg[x]++, deg[y]++;
} 

int dp[maxn][2];
bool vis[maxn][2];
int DP(int x, bool op, int fa){
	if (vis[x][op]) return dp[x][op];
	vis[x][op] = 1;
	int& ans = dp[x][op];
	if (op){
		int mx = 0;
		erep(i, x){
			int op = e[i].to;
			if (op == fa) continue;
			mx = max(mx, DP(op, 1, x));
		}
		ans = mx + deg[x];
	}
	else {
		erep(i, x){
			int op = e[i].to;
			if (op == fa) continue;
			ans = max(ans, DP(op, 0, x));
		}
		int mx1 = 0, mx2 = 0;
		erep(i, x){
			int op = e[i].to;
			if (op == fa) continue;
			if (DP(op, 1, x) >= mx1) mx2 = mx1, mx1 = DP(op, 1, x);
			else if (DP(op, 1, x) > mx2) mx2 = DP(op, 1, x);
		}
		ans = max(ans, mx1 + mx2 + deg[x]);
	}
	return ans;
}

void recover(){
    cnt = 1;
    rep(i, 1, n) h[i] = deg[i] = 0;
	rep(i, 1, n) rep(j, 0, 1) dp[i][j] = vis[i][j] = 0;
}

int main(){
    int T, x, y;
    read(T);
    while (T--){
        read(n);
        srep(i, 1, n) read(x), read(y), Add_Edge(x, y);
        rep(i, 1, n) if (deg[i] > 1) deg[i]--;
		printf("%d\n", DP(1, 0, -1));
		recover();
    }
    return 0;
}