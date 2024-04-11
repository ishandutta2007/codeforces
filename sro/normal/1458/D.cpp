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

char s[1 << 19];
int n;
int l[1 << 20], r[1 << 20];
const int zr = 1 << 19;
vector<int> ans;

void dfs(int now) {
	if(!l[now] && !r[now]) return;
	if(l[now] && (l[now] > 1 || !r[now])) {
		ans.pub(0);
		--l[now]; --r[--now]; dfs(now);
	} else {
		ans.pub(1);
		--r[now]; --l[++now]; dfs(now);
	}
}

void solve() {
	scanf("%s", s + 1); n = strlen(s + 1);
	circ(i, zr - n, zr + n) l[i] = r[i] = 0;
	int val = zr;
	cont(i, n) {
		if(s[i] == '0') ++l[val], ++r[--val];
		else ++r[val], ++l[++val];
	}
	ans.clear();
	dfs(zr);
	loop(i, SZ(ans)) printf("%d", ans[i]);
	puts("");
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}