/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); i++)
#define cont(i, n)          for(int i = 1; i <= (n); i++)
#define circ(i, a, b)       for(int i = (a); i <= (b); i++)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

const int jt = 1000000007;
int dp[1005][1005][8];
int n, m;
int jc[1005];
int C[1005][1005];

int main() {
	scanf("%d%d", &n, &m);
	jc[0] = 1;
	cont(i, n) jc[i] = 1ll * jc[i - 1] * i % jt;
	loop(i, n + 1) C[i][0] = 1;
	cont(i, n) cont(j, i) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % jt;
	dp[0][0][0] = 1;
	loop(i, n) loop(j, i + 1) loop(msk, 8) {
		// The next pos is a SHENQI de pos
		if(i && !(msk & 2)) (dp[i + 1][j + 1][msk >> 1 | 1] += dp[i][j][msk]) %= jt;
		if(i < n - 1) (dp[i + 1][j + 1][msk >> 1 | 4] += dp[i][j][msk]) %= jt;
		// The next pos is not a SHENQI de pos
		(dp[i + 1][j][msk >> 1] += dp[i][j][msk]) %= jt;
	}
	int ans = 0;
	circ(i, m, n) loop(msk, 8) {
		if((m - i) & 1) (ans += 1ll * (jt - dp[n][i][msk]) * jc[n - i] % jt * C[i][m] % jt) %= jt;
		else (ans += 1ll * dp[n][i][msk] * jc[n - i] % jt * C[i][m] % jt) %= jt;
	}
	printf("%d\n", ans);
	return 0;
}