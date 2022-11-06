//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 705, inf = 0x3f3f3f3f;
const char ans[2][5] = {"No", "Yes"};

int n, a[N], gcd[N][N], dp[N][N][2], Ans;
int euclid(int x, int y) {return !y ? x : euclid(y, x%y);}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) rep(j, 1, n) gcd[i][j] = euclid(a[i], a[j]);
	rep(i, 1, n) dp[i][i][0] = dp[i][i][1] = 1;
	rep(delta, 0, n-1) {
		rep(L, 1, n) {
			int R = L + delta;
			if(R > n) break;
			rep(M, L, R) {
				if(dp[L][M][0] && dp[M][R][1]) {
					if(L == 1 && R == n) {Ans = 1; break;}
					dp[L-1][R][1] |= gcd[L-1][M] > 1;
					dp[L][R+1][0] |= gcd[M][R+1] > 1;
				}
//				printf("[%d, %d] root=%d OK: %s\n", L, R, M, ans[Ans]);
				if(Ans) break;
			}
//			printf("[%d, %d] STATUS: %s\n", L, R, ans[Ans]);
			if(Ans) break;
		}
	}
	printf("%s\n", ans[Ans]);
    return 0;
}