//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 105; 

int n, m, b[N][N], tgX[N], tgY[N], a[N][N], tg2X[N], tg2Y[N], bb[N][N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) tgX[i] = 1;
	rep(j, 1, m) tgY[j] = 1;
	rep(i, 1, n) {
		rep(j, 1, m) {
			scanf("%d", &b[i][j]);
			if(!b[i][j]) tgX[i] = tgY[j] = 0;
		}
	}
	rep(i, 1, n) {
		rep(j, 1, m) {
			a[i][j] = tgX[i] & tgY[j];
			if(a[i][j]) tg2X[i] = tg2Y[j] = 1;
		}
	}
	rep(i, 1, n) {
		rep(j, 1, m) {
			bb[i][j] = tg2X[i] | tg2Y[j];
			if(bb[i][j] != b[i][j]) return puts("NO")&0;
		}
	}
	puts("YES");
	rep(i, 1, n) {
		rep(j, 1, m) {
			printf("%d%c", a[i][j], " \n"[j==m]);
		}
	}
    return 0;
}