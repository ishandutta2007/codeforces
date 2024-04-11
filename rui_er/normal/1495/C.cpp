//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 505; 

int T, n, m;
char s[N][N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%s", s[i]+1);
		rep(i, 1, n) if(i % 3 == 1) rep(j, 1, m) s[i][j] = 'X';
		rep(i, 1, n) if(i % 3 == 2) {
			if(i + 1 < n) {
				if(s[i][2] == 'X' || s[i+1][2] == 'X') s[i][2] = s[i+1][2] = 'X';
				else s[i][1] = s[i+1][1] = 'X';
			}
			else if(i + 1 == n) {
				rep(j, 1, m) if(s[i+1][j] == 'X') s[i][j] = 'X';
			}
		}
		rep(i, 1, n) puts(s[i]+1);
	}
	return 0;
}