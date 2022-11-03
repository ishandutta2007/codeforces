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

int n, r1, r2, r3, d;
int a[1 << 20];
ll dp[1 << 20];

int main() {
	scanf("%d%d%d%d%d", &n, &r1, &r2, &r3, &d);
	cont(i, n) scanf("%d", a + i);
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	cont(i, n) {
		ll kil = 1ll * r1 * a[i] + r3;
		if(i < n) kil += d;
		dp[i] = min(dp[i], dp[i - 1] + kil);
		ll base = r2 + 2ll * d + r1;
		if(i < n - 1) base += d;
		dp[i] = min(dp[i], dp[i - 1] + base);
		base = 1ll * r1 * (a[i] + 1) + 2ll * d + r1;
		if(i < n - 1) base += d;
		dp[i] = min(dp[i], dp[i - 1] + base);
		ll ph = 2ll * r2 + 3ll * d + 2ll * r1;
		if(i > 1){
			if(i < n) ph += d;
			dp[i] = min(dp[i], dp[i - 2] + ph);
		}
		ph = r2 + 1ll * r1 * (a[i - 1] + 1) + 3ll * d + 2ll * r1;
		if(i > 1){
			if(i < n) ph += d;
			dp[i] = min(dp[i], dp[i - 2] + ph);
		}
		ph = r2 + 1ll * r1 * (a[i] + 1) + 3ll * d + 2ll * r1;
		if(i > 1){
			if(i < n) ph += d;
			dp[i] = min(dp[i], dp[i - 2] + ph);
		}
		ph = 1ll * r1 * (a[i - 1] + 1) + 1ll * r1 * (a[i] + 1) + 3ll * d + 2ll * r1;
		if(i > 1){
			if(i < n) ph += d;
			dp[i] = min(dp[i], dp[i - 2] + ph);
		}
	}
	printf("%lld\n", dp[n]);
	return 0;
}