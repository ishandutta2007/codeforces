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

int n;
ll a[1 << 17];

int main() {
	scanf("%d", &n);
	cont(i, n) scanf("%lld", a + i);
	if(n == 1) {
		puts("1 1\n0");
		puts("1 1\n0");
		printf("1 1\n%d\n", -a[1]);
		return 0;
	}
	puts("1 1");
	printf("%lld\n", -a[1]);
	a[1] = 0;
	printf("2 %d\n", n);
	int rl = n - 1;
	circ(i, 2, n) {
		ll rem = a[i] % n;
		printf("%lld%c", rem * rl, i == n ? '\n' : ' ');
		a[i] += rem * rl;
	}
	printf("1 %d\n", n);
	cont(i, n) {
		printf("%lld%c", -a[i], i == n ? '\n' : ' ');
	}
	return 0;
}