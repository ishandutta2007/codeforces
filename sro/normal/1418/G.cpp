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
typedef unsigned long long ull;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

int n;
int a[1 << 19];
int cnt[1 << 19];
ull ha[1 << 19], hs[1 << 19];
mt19937_64 Rand;

int main() {
	scanf("%d", &n);
	cont(i, n) scanf("%d", a + i);
	loop(i, 1 << 19) ha[i] = Rand();
	cont(i, n) {
		hs[i] = hs[i - 1];
		hs[i] -= ha[a[i]] * cnt[a[i]];
		cnt[a[i]] = (cnt[a[i]] + 1) % 3;
		hs[i] += ha[a[i]] * cnt[a[i]];
	}
	memset(cnt, 0, sizeof(cnt)); cnt[0] = 1;
	map<ull, int> cs; int r = 0; ll ans = 0; cs[0]++;
	loop(i, n) {
		cnt[a[i]]--, cs[hs[i]]--;
		while(r < n && cnt[a[r + 1]] < 3) {
			r++; cnt[a[r]]++; cs[hs[r]]++;
		}
		ans += cs[hs[i]];
	}
	printf("%lld\n", ans);
	return 0;
}