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

int n, m;
int r, c;
double dp[1005][1005];
double xs[1005][1005], res[1005];

int main() {
	scanf("%d%d", &n, &m);
	scanf("%d%d", &r, &c);
	if(m == 1) {
		int dn = n - r;
		printf("%.10lf\n", dn * 2.0);
		return 0;
	}
	range(i, n - 1, 1, -1) {
		xs[1][1] = -2.0 / 3; xs[1][2] = 1.0 / 3; res[1] = -1.0 / 3 * dp[i + 1][1] - 1;
		xs[m][m] = -2.0 / 3; xs[m][m - 1] = 1.0 / 3; res[m] = -1.0 / 3 * dp[i + 1][m] - 1;
		circ(j, 2, m - 1) xs[j][j] = -3.0 / 4, xs[j][j - 1] = xs[j][j + 1] = 1.0 / 4, res[j] = -1.0 / 4 * dp[i + 1][j] - 1;
		cont(j, m - 1) {
			double choo = xs[j][j];
			xs[j][j] /= choo; xs[j][j + 1] /= choo; res[j] /= choo;
			double jan = xs[j + 1][j];
			xs[j + 1][j] -= xs[j][j] * jan; xs[j + 1][j + 1] -= xs[j][j + 1] * jan; res[j + 1] -= res[j] * jan;
		}
		res[m] /= xs[m][m]; xs[m][m] = 1;
		dp[i][m] = res[m];
		range(j, m - 1, 1, -1) {
			res[j] -= res[j + 1] * xs[j][j + 1];
			dp[i][j] = res[j];
		}
	}
	printf("%.10lf\n", dp[r][c]);
	return 0;
}