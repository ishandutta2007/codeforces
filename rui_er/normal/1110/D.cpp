//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e6+5; 

int n, m, a[N], buc[N], dp[N][3][3];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		++buc[a[i]];
	}
	rep(i, 1, m) {
		rep(j, 0, 2) {
			rep(k, 0, 2) {
				rep(l, 0, 2) {
					if(buc[i] >= j + k + l) {
						int triple = (buc[i] - j - k - l) / 3 + l;
						chkmax(dp[i][k][l], dp[i-1][j][k]+triple);
					}
				}
			}
		}
	}
	printf("%d\n", dp[m][0][0]);
	return 0;
}