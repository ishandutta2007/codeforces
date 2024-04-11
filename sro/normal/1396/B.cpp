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
int a[105];
int sm;

void solve() {
	scanf("%d", &n);
	sm = 0;
	cont(i, n) {
		scanf("%d", a + i);
		sm += a[i];
	}
	sort(a + 1, a + n + 1);
	if(a[n] > sm / 2) return void(puts("T"));
	int jis = 0;
	cont(i, n) {
		if(a[i] % 2) jis++;
	}
	if(jis % 2) puts("T");
	else puts("HL");
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}