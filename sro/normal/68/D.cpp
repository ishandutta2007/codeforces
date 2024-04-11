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

int h, q;
map<int, int> al;
char tmp[15];

double dfs(int now, int val) {
	if(!al[now] || al[now] < val) return val;
	return (
		dfs(now << 1, max(val, al[now] - al[now << 1])) +
		dfs(now << 1 | 1, max(val, al[now] - al[now << 1 | 1]))
	) / 2;
}

int main() {
	scanf("%d%d", &h, &q);
	while(q--) {
		scanf("%s", tmp);
		if(tmp[0] == 'a') {
			int v, e; scanf("%d%d", &v, &e);
			while(v) al[v] += e, v >>= 1;
		} else {
			printf("%.10lf\n", dfs(1, 0));
		}
	}
	return 0;
}