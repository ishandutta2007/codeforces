#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 320
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n, m, k;
int r[maxn], g[maxn], b[maxn];

bool vis[maxn][maxn][maxn];
int dp[maxn][maxn][maxn];
int DP(int x, int y, int z){
	if (x + y + z <= 1) return 0;
	if (vis[x][y][z]) return dp[x][y][z];
	vis[x][y][z] = 1;
	int& ans = dp[x][y][z];
	ans = 0;
	if (x && y) ans = max(ans, DP(x - 1, y - 1, z) + r[x] * g[y]);
	if (y && z) ans = max(ans, DP(x, y - 1, z - 1) + g[y] * b[z]);
	if (z && x) ans = max(ans, DP(x - 1, y, z - 1) + r[x] * b[z]);
	return ans; 
}
int main(){
	read(n), read(m), read(k);
	rep(i, 1, n) read(r[i]);
	rep(i, 1, m) read(g[i]);
	rep(i, 1, k) read(b[i]);
	sort(r + 1, r + 1 + n);
	sort(g + 1, g + 1 + m);
	sort(b + 1, b + 1 + k);
	printf("%d\n", DP(n, m, k));
	return 0;
}