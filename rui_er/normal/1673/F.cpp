//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 35, K = 5e4+5;

int n, k, a[N][N], b[N][N], s[N][N], x[K], y[K];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int lowbit(int x) {return x & (-x);}
int sqr(int x) {return x * x;}

int main() {
	scanf("%d%d", &n, &k);
	rep(i, 1, n) rep(j, 1, n-1) a[i][j] = sqr(lowbit(j));
	rep(i, 1, n-1) rep(j, 1, n) b[i][j] = sqr(lowbit(i)) * 2;
	rep(j, 1, n) s[1][j] = s[1][j-1] ^ a[1][j-1];
	rep(i, 2, n) rep(j, 1, n) s[i][j] = s[i-1][j] ^ b[i-1][j];
	rep(i, 1, n) rep(j, 1, n-1) printf("%d%c", a[i][j], " \n"[j==n-1]);
	rep(i, 1, n-1) rep(j, 1, n) printf("%d%c", b[i][j], " \n"[j==n]);
	fflush(stdout);
	rep(i, 1, n) rep(j, 1, n) x[s[i][j]] = i, y[s[i][j]] = j;
	int now = 0;
	while(k --> 0) {
		int u;
		scanf("%d", &u);
		now ^= u;
		printf("%d %d\n", x[now], y[now]);
		fflush(stdout);
	}
	return 0;
}