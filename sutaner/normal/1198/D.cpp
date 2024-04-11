#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define maxr 100000
#define pb push_back
#define maxn 52
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
char s[maxn][maxn];
int pre[maxn][maxn];
int num[maxn][maxn];

bool vis[maxn][maxn][maxn][maxn];
int dp[maxn][maxn][maxn][maxn];
int DP(int x1, int y1, int x2, int y2){
	if (x2 < x1 || y2 < y1) return 0;
	if (pre[x2][y2] - pre[x2][y1 - 1] - pre[x1 - 1][y2] + pre[x1 - 1][y1 - 1] == 0) return 0;
	if (vis[x1][y1][x2][y2]) return dp[x1][y1][x2][y2];
	vis[x1][y1][x2][y2] = 1;
	int& ans = dp[x1][y1][x2][y2];
	int x = x2 - x1 + 1, y = y2 - y1 + 1;
	int l = min(x, y);
	ans = max(x, y);
	if (x == y) ans = l; 
	else if (x < y){
		rep(i, y1 - 1, y2 - l){
			ans = min(ans, l + DP(x1, y1, x2, i) + DP(x1, i + l + 1, x2, y2));
		}
	}
	else {
		rep(i, x1 - 1, x2 - l){
			ans = min(ans, l + DP(x1, y1, i, y2) + DP(i + l + 1, y1, x2, y2));
		}
	}
	rep(i, x1, x2 - 1) ans = min(ans, DP(x1, y1, i, y2) + DP(i + 1, y1, x2, y2));
	rep(i, y1, y2 - 1) ans = min(ans, DP(x1, y1, x2, i) + DP(x1, i + 1, x2, y2));
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("D.in", "r", stdin);
	#endif
	scanf("%d", &n);
	rep(i, 1, n) scanf("%s", s[i] + 1);
	rep(i, 1, n) rep(j, 1, n) num[i][j] = (s[i][j] == '#') ? 1 : 0;
	rep(i, 1, n) rep(j, 1, n) pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + num[i][j];
	printf("%d", DP(1, 1, n, n));
	return 0;
}