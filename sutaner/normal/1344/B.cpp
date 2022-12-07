#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 1020
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

int n, m;
char g[maxn][maxn];
bool vis[maxn][maxn];
void dfs(int x, int y){	
	if (!(1 <= x && x <= n && 1 <= y && y <= m) || vis[x][y] || g[x][y] != '#') return;
	vis[x][y] = 1;
	for (register int i = -1; i < 3; i += 2){
		dfs(x + i, y);
		dfs(x, y + i);
	}
}

bool havx[maxn], havy[maxn];

int main(){ 

	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%s", g[i] + 1);
	bool have = 0;
	rep(i, 1, n){
		rep(j, 1, m){
			if (g[i][j] == '#') {
				have = 1;
				break;
			}
		}
	}
	if (!have) {printf("0"); return 0;}
	rep(i, 1, n){
		int l = 1;
		while (l <= m && g[i][l] == '.') l++;
		int r = m;
		while (r >= 1 && g[i][r] == '.') r--;
		rep(j, l, r){
			if (g[i][j] == '.') {
				printf("-1");
				return 0;
			}
		}
	}
	rep(j, 1, m){
		int u = 1;
		while (u <= n && g[u][j] == '.') u++;
		int d = n;
		while (d >= 1 && g[d][j] == '.') d--;
		rep(i, u, d){
			if (g[i][j] == '.') {	
				printf("-1");
				return 0;
			}
		}
	}
	if (n == 1 || m == 1){
		rep(i, 1, n) {
			rep(j, 1, m){
				if (g[i][j] == '.') {	
					printf("-1");
					return 0;
				}
			}
		}
	}
	rep(i, 1, n) {
		rep(j, 1, m){
			if (g[i][j] == '#') havx[i] = havy[j] = 1;
		}
	}
	bool fullx = 1;
	rep(i, 1, n) if (!havx[i]) {fullx = 0; break;} 
	if (fullx){
		rep(j, 1, m){
			bool alle = 1;
			rep(i, 1, n){
				if (g[i][j] == '#') {alle = 0; break;}
			}
			if (alle) {	
				printf("-1");
				return 0;
			} 
		}
	}
	bool fully = 1;
	rep(j, 1, m) if (!havy[j]) {fully = 0; break;}
	if (fully){	
		rep(i, 1, n){
			bool alle = 1;
			rep(j, 1, m){
				if (g[i][j] == '#') {alle = 0; break;}
			}
			if (alle){
				printf("-1");
				return 0;
			}
		}
	}
	int ans = 0;
	rep(i, 1, n){
		rep(j, 1, m){
			if (g[i][j] != '#') continue;
			if (!vis[i][j]) ans++, dfs(i, j); 
		}
	}
	printf("%d\n", ans);
	return 0;
}