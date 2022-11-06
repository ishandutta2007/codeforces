//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 55, nxt[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int T, n, m, vis[N][N];
char s[N][N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool in(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
void dfs(int i, int j) {
	vis[i][j] = 1;
	rep(_, 0, 3) {
		int x = i + nxt[_][0], y = j + nxt[_][1];
		if(in(x, y) && s[x][y] != '#' && !vis[x][y]) dfs(x, y);
	}
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) rep(j, 1, m) vis[i][j] = 0;
		rep(i, 1, n) scanf("%s", s[i]+1);
		rep(i, 1, n) {
			rep(j, 1, m) {
				if(s[i][j] == 'B') {
					rep(_, 0, 3) {
						int x = i + nxt[_][0], y = j + nxt[_][1];
						if(in(x, y) && s[x][y] == '.') s[x][y] = '#';
					}
				}
			}
		}
		if(s[n][m] != '#') dfs(n, m);
		int ok = 1;
		rep(i, 1, n) {
			rep(j, 1, m) {
				if(s[i][j] == 'B') ok &= !vis[i][j];
				if(s[i][j] == 'G') ok &= vis[i][j];
			}
		}
		puts(ok?"Yes":"No");
	}
	return 0;
}