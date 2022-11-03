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

int n;
ll b[1 << 17], a[1 << 17];
int fa[1 << 17], k[1 << 17];
vector<int> nei[1 << 17];

void inline dfs(int now) {
	loop(i, SZ(nei[now])) {
		int to = nei[now][i];
		dfs(to);
	}
	if(now == 1) {
		puts(b[1] >= a[1] ? "YES" : "NO");
		return;
	}
	if(a[now] < -5e17) {
		puts("NO");
		exit(0);
	}
	if(b[now] > a[now]) {
		b[fa[now]] += b[now] - a[now];
		b[now] = a[now];
	} else {
		ll ls = a[now] - b[now];
		if((5e17 - b[fa[now]]) / k[now] < ls) {
			puts("NO");
			exit(0);
		}
		b[fa[now]] -= 1ll * k[now] * ls;
		b[now] = a[now];
	}
}

int main() {
	scanf("%d", &n);
	cont(i, n) scanf("%lld", b + i);
	cont(i, n) scanf("%lld", a + i);
	circ(i, 2, n) scanf("%d%d", fa + i, k + i), nei[fa[i]].pub(i);
	dfs(1);
}