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
int a[2555][2555];
bitset<2555> b[2555];
vector<pair<int, pair<int, int> > > egs;

int main() {
	scanf("%d", &n);
	cont(i, n) cont(j, n) scanf("%d", a[i] + j);
	bool can = 1;
	cont(i, n) if(a[i][i]) can = 0;
	cont(i, n) cont(j, n) if(a[i][j] != a[j][i]) can = 0;
	cont(i, n) cont(j, i - 1) {
		egs.pub(mak(a[i][j], mak(i, j)));
	}
	sort(all(egs)); reverse(all(egs));
	loop(i, SZ(egs)) {
		int j = i;
		while(j < SZ(egs) && egs[j].first == egs[i].first) {
			int u = egs[j].second.first, v = egs[j].second.second;
			b[u][v] = b[v][u] = 1; ++j;
		}
		circ(k, i, j - 1) {
			int u = egs[k].second.first, v = egs[k].second.second;
			if((b[u] | b[v]).count() < n) can = 0;
		}
		i = j - 1;
	}
	if(can) puts("MAGIC");
	else puts("NOT MAGIC");
	return 0;
}