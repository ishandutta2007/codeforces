//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T, L, R, s[N][19];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	rep(i, 1, 200000) {
		per(j, 18, 0) {
			s[i][j] = s[i-1][j] + ((i >> j) & 1);
		}
	}
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &L, &R);
		int ans = 0;
		rep(i, 0, 18) chkmax(ans, s[R][i]-s[L-1][i]);
		printf("%d\n", (R-L+1)-ans);
	}
    return 0;
}