/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
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

int n, x;
int a[505];

void solve() {
	scanf("%d%d", &n, &x);
	loop(i, n) scanf("%d", a + i);
	int ans = 0, yx = n - 1;
	range(i, n - 2, 0, -1) {
		if(a[i] <= a[i + 1]) --yx;
		else break;
	}
	int cur = 0, can = 1;
	while(1) {
		int nxt = cur;
		while(nxt < n && a[nxt] <= x) ++nxt;
		circ(i, cur, nxt - 1) if(i && a[i - 1] > a[i]) goto no;
		if(nxt >= yx) break;
		swap(a[nxt], x);
		++ans; cur = nxt;
	}
	printf("%d\n", ans); return;
	no: puts("-1");
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}