//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 5e3+5;

int n, to[N];
char a[N][N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%s", a[i]+1);
		rep(j, 1, i-1) {
			if((a[i][j] ^ 48) && (!to[i] || (a[j][to[i]] ^ 48))) to[i] = j;
		}
	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			if(to[i] && (a[to[i]][j] ^ 48) && (a[j][i] ^ 48)) {
				printf("%d %d %d\n", i, to[i], j);
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
}